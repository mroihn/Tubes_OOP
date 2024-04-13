#ifndef USER_HPP
#define USER_HPP

#include <string>
#include "../Inventory/Inventory.hpp"  
#include "../InvItems/InvItems.hpp"
#include "../pcolor/pcolor.h"
#include "../Inventory/Inventory.cpp"  
#include "UserException.hpp"
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
        User(string username, pair<int,int> invSize);
        User(string username, int berat,int uang, pair<int,int> invSize);
        virtual ~User();

        int getBerat();
        Inventory<InvItems*>& getInv();
        InvItems* getItem(string kode_huruf);
        int getUang();
        void setUang(int uang);
        void next();
        void cetak_penyimpanan();
        void setPenyimpanan(int i, int j, InvItems* item);

        void setPenyimpanan( InvItems* item);
        //virtual void cetakPeternakan();

        //virtual double calculatetax() const = 0;

        int sisaPenyimpanan();
        void makan();
        void beli();
        void jual();
};
 
 
class Walikota: public User{
    private:
        static int jumlah_walikota;
    public:
        Walikota(string username, pair<int,int> invSize);
        Walikota(string username, int berat, int uang, pair<int,int> invSize);
        ~Walikota();
        void tagihPajak();
        void tambahBangunan();
        void tambahPemain();
        //double calculatetax() const override;
};

class Petani: public User{
    private:
        Inventory<Tanaman*> ladang;
    public: 
        Petani(string username, pair<int,int> invSize, pair<int,int> fieldSize);
        Petani(string nama,int berat,int uang,pair<int,int> inventorySize,pair<int,int> fieldSize);
        void setLadang(int i, int j, Tanaman* t);
        void tanamTanaman();
    
        Inventory<Tanaman*>& getladang();
        Tanaman* getTanaman(string kode_huruf);
        void panenTanaman();
        void cetakLadang();
        //double calculatetax() const override;
}; 

class Peternak: public User{
    private:
        Inventory<Hewan*> peternakan;
    public:
        Peternak(string username, pair<int,int> invSize, pair<int,int> barnSize);
        Peternak(string nama,int berat,int uang,pair<int,int> inventorySize,pair<int,int> farmSize);
        void cetakPeternakan();
        void setPeternakan(int i, int j, Hewan* t);
        Inventory<Hewan*>& getfarm(){
            return peternakan;
        }
        void ternak();
        void panen();
        //double calculatetax() const override;
};


#endif