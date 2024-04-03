#ifndef USER_H
#define USER_H

#include <string>
#include "./Inventory/Inventory.hpp"
#include "./InvItems/InvItems.hpp"

using namespace std;

class User{
    protected:
        int id;
        string username;
        int berat_badan;
        int uang;
        Inventory<InvItems*> penyimpanan;
    public:
        User(): penyimpanan(0,0){
            berat_badan = 40;
            uang = 50;
        };
        void next();
        void cetak_penyimpanan();
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
        Inventory<TanamanLadang> ladang;
    public:
        void tanamTanaman();
        void panenTanaman();
        void cetakLadang();
}; 

class Peternak: public User{
    private:
        Inventory<Hewan> peternakan;
    public:
        void cetakPeternakan();
        void ternak();
        void panen();
};


#endif