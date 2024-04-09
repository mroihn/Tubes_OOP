#ifndef USER_HPP
#define USER_HPP

#include <string>
#include "../Inventory/Inventory.hpp"  
#include "../InvItems/InvItems.hpp"
#include "../pcolor/pcolor.h"
// #include "../Inventory/Inventory.cpp"  
// #include "../InvItems/InvItems.cpp"
// #include "../pcolor/pcolor.c"

using namespace std;

class User{
    protected:
        // static int n_player;
        int id;
        string username;
        int berat_badan;
        int uang;
        Inventory<InvItems*> penyimpanan;
    public:
        User();
        User(string username, int berat, int uang, pair<int,int> invSize);
        int getBerat();
        Inventory<InvItems*> *getInv();
        int getUang();
        void next();
        void cetak_penyimpanan();
        void setPenyimpanan(int i, int j, InvItems* item);

        void setPenyimpanan( InvItems* item);
        virtual void cetakPeternakan();

        void makan();
        void beli();
        void jual();
};
 
class Walikota: public User{
    private:
        static int jumlah_walikota;
    public:
        Walikota(string nama, int berat, int uang, pair<int,int> invSize);
        void tagihPajak();
        void tambahBangunan();
        void tambahPemain();
};

class Petani: public User{
    private:
        Inventory<Tanaman*> ladang;
    public: 
        Petani();
        Petani(string nama, int berat, int uang, pair<int,int> invSize, pair<int,int> fieldSize);
        void setLadang(int i, int j, Tanaman* t);
        void tanamTanaman();
    
        Inventory<Tanaman*> *getladang();
        void panenTanaman();
        void cetakLadang();
        
}; 

class Peternak: public User{
    private:
        Inventory<Hewan*> peternakan;
    public:
        Peternak(string nama, int berat, int uang, pair<int,int> invSize, pair<int,int> farmSize): User(nama,berat,uang, invSize), peternakan(farmSize.first, farmSize.second){}
        void cetakPeternakan(){
            cout << "TODO IMPLEMENT CETAK PETERNAKAN\n";
        }
        Inventory<Hewan*>* getfarm(){
            return &peternakan;
        }
        void ternak(){cout << "do nothing";}
        void panen(){cout << "do nothing";}
};


#endif