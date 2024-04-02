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
        User();
        void next();
        void cetak_penyimpanan();
        void makan();
        void beli();
        void jual();
};

class Walikota: public User{
    private:
        static int jumlah_walikota;
        //inventory
    public:
        void tagihPajak();
        void tambahBangunan();
        void tambahPemain();
};

class Petani: public User{
    private:
        static int jumlah_petani;
        //inventory
    public:
        Petani(string username);
        ~Petani();
        void tanamTanaman();
        void panenTanaman();
        void cetakLadang();
}; 

class Peternak: public User{
    private:
        static int jumlah_peternak;
    public:
        Peternak(string username);
        ~Peternak();
        void cetakPeternakan();
        void ternak();
        void panenTernak();
    
};


#endif