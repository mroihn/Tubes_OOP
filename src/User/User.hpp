#ifndef USER_H
#define USER_H

#include <string>

using namespace std;

class User{
    protected:
        int id;
        string username;
        int berat_badan;
        int uang;
        //Inventory penyimpanan;
    public:
        User(){
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
        //Inventory ladang;
    public:
        void tanamTanaman();
        void panenTanaman();
        void cetakLadang();
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