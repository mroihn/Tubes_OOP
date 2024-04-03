#ifndef USER_H
#define USER_H

#include <string>
#include "../Inventory/Inventory.hpp"  
#include "../BahanBaku/BahanBaku.hpp"
#include "../pcolor/pcolor.h"

using namespace std;

class User{
    protected:
        int id;
        string username;
        int berat_badan;
        int uang;
        Inventory<BahanBaku*> penyimpanan;
    public:
        User() : penyimpanan(5,5){
            berat_badan = 40;
            uang = 50;
        };
        int getBerat(){
            return berat_badan;
        }
        int getUang(){
            return uang;
        }
        void next();
        void cetak_penyimpanan(){
            int length1 = (7 + (penyimpanan.getCols()-1)*6)/2 - 7;
            int i;
            cout << "     ";
            for (i=0;i<length1;i++){
                cout << '=';
            }
            cout << "[ penyimpanan ]";
            if (penyimpanan.getCols()%2==0){
                length1++;
            }
            for (i=0;i<length1;i++){
                cout << '=';
            }
            cout << '\n';
            cout << "        ";
            for(int i=0; i<penyimpanan.getCols(); i++){
                cout << char('A'+i) << "     ";
            }
            cout << endl;
            for (int i = 0; i < penyimpanan.getRows(); ++i) {
                cout << "     ";
                for (int j = 0; j < penyimpanan.getCols(); ++j) {
                    cout << "+-----";
                }
                cout << "+" << endl;
                cout << "  " << setw(2) << setfill(' ') << i+1;
                for (int j = 0; j < penyimpanan.getCols(); ++j) {
                    cout << " | ";
                    if (penyimpanan(i,j)){
                        cout << penyimpanan(i,j)->getKode();
                    }
                    else{
                        cout << "   ";
                    }
                }
                cout << " |" << endl;
            }
            cout << "     ";
            for (int j = 0; j < penyimpanan.getCols(); ++j) {
                cout << "+-----";
            }
            cout << "+" << endl;
        }
        void setPenyimpanan(int i, int j, BahanBaku* b){
            if (i>=penyimpanan.getRows() || j>penyimpanan.getCols() || i<0 || j<0){
                // Throw Exception
            }
            delete penyimpanan(i,j);
            penyimpanan(i,j) = b;
        }
        void makan();
        void beli();
        void jual();
};
 
class Walikota: public User{
    private:
        static int jumlah_walikota;
    public:
        void tagihPajak();
        void tambahBangunan();
        void tambahPemain();
};

class Petani: public User{
    private:
        Inventory<Tanaman*> ladang;
    public: 
        Petani() :ladang(5,5){};
        void setLadang(int i, int j, Tanaman* t){
            if (i>=ladang.getRows() || j>ladang.getCols() || i<0 || j<0){
                // Throw Exception
            }
            delete ladang(i,j);
            ladang(i,j) = t;
        }
        void tanamTanaman(){
            if (ladang.isFull()){
                //throw exception
            }
            if(penyimpanan.isEmpty()){
                //throw exception
            }
            string slot;
            string subslot;
            Tanaman* temp;
            while (true){
                cout << "Pilih Tanaman Dari Penyimpanan \n";
                cetak_penyimpanan();

                cout << "Slot: ";
                cin >> slot;
                subslot = slot.substr(1,3);
                int x = slot[0] - 'A';
                int y = stoi(subslot)-1;

                if (x>penyimpanan.getRows()-1 || y>penyimpanan.getCols()-1){
                    //throw exception;
                }
                else{
                    temp = static_cast<Tanaman*>(penyimpanan(x,y));
                    penyimpanan(x,y)=nullptr;
                    break;
                }
            }
            while (true){
                cout << "\n\nPilih Pilih petak tanah yang akan ditanami \n";
                cetakLadang();

                cout << "Slot: ";
                cin >> slot;
                subslot = slot.substr(1,3);
                int x = slot[0] - 'A';
                int y = stoi(subslot)-1;

                if (x>ladang.getRows()-1 || y>ladang.getCols()-1){
                    //throw exception;
                }
                else{
                    setLadang(x,y,temp);
                    break;
                }
            }
        }
        void panenTanaman(){
            cetakLadang();
            vector<Tanaman*> printed(0);
            bool flag = false;
            int i,j,k;
            for (i=0;i<ladang.getRows();i++){
                for (j=0;j<ladang.getCols();j++){
                    if(ladang(i,j)){
                        for (k=0;k<printed.size();k++){
                            if(ladang(i,j)->getKode() == printed[k]->getKode()){
                                flag = true;
                            }
                        }
                    }
                }
            }
        }
        void cetakLadang(){
            vector<Tanaman*> printed(0);
            int length1 = (7 + (ladang.getCols()-1)*6)/2 - 5;
            int i,j,k;
            bool flag = false;
            cout << "     ";
            for (i=0;i<length1;i++){
                cout << '=';
            }
            cout << "[ Ladang ]";
            if (ladang.getCols()%2!=0){
                length1++;
            }
            for (i=0;i<length1;i++){
                cout << '=';
            }
            cout << '\n';
            cout << "        ";
            for(i=0; i<ladang.getCols(); i++){
                cout << char('A'+i) << "     ";
            }
            cout << endl;
            for (i = 0; i < ladang.getRows(); ++i) {
                cout << "     ";
                for (j = 0; j < ladang.getCols(); ++j) {
                    cout << "+-----";
                }
                cout << "+" << endl;
                cout << "  " << setw(2) << setfill(' ') << i+1;
                for (j = 0; j < ladang.getCols(); ++j) {
                    cout << " | ";
                    if (ladang(i,j)){
                        for (k=0;k<printed.size();k++){
                            if(ladang(i,j)->getKode() == printed[k]->getKode()){
                                flag = true;
                            }
                        }
                        
                        if (!flag){
                            printed.push_back(ladang(i,j));
                        }
                        flag=false;
                        if (ladang(i,j)->siapPanen()){
                            for (k=0;k<3;k++){
                                print_green(ladang(i,j)->getKode()[k]);
                            }
                        }
                        else{
                            for (k=0;k<3;k++){
                                print_red(ladang(i,j)->getKode()[k]);
                            }
                        }
                    }
                    else{
                        cout << "   ";
                    }
                }
                cout << " |" << endl;
            }
            cout << "     ";
            for (int j = 0; j < ladang.getCols(); ++j) {
                cout << "+-----";
            }
            cout << "+\n\n";

            for(i=0;i<printed.size();i++){
                cout << "- " << printed[i]->getKode() << ": " << printed[i]->getNama() << '\n';
            }
        }
        
}; 

class Peternak: public User{
    private:
        //Inventory peternakan;
    public:
        void cetakPeternakan();
        void ternak();
        void panen();
};


#endif