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
        std::string username;
        int berat_badan;
        int uang;
        Inventory<InvItems*> penyimpanan;
    public:
        User();
        User(std::string username, pair<int,int> invSize);
        User(std::string username, int berat,int uang, pair<int,int> invSize);
        virtual ~User();

        string getNama();
        int getBerat();
        Inventory<InvItems*>& getInv();
        InvItems* getItem(std::string kode_huruf);
        int getUang();
        void next();
        void cetak_penyimpanan();
        void setPenyimpanan(int i, int j, InvItems* item);

        void setPenyimpanan( InvItems* item);

        virtual double pungutpajak() = 0;

        int sisaPenyimpanan();
        void makan();
        void beli(int harga);
        InvItems* jual(int i,int j);
        void batalJual(InvItems* item,int i,int j);

        //virtual untuk cek role
        virtual bool isPetani() = 0;
        virtual bool isPeternak() = 0;
        virtual bool isWalikota() = 0;

        //virtual for walikota
        virtual void tagihPajak(map<string,User*> ListUser) = 0;
        virtual int findMaterial(const string& materialName, int neededQuantity) = 0;
        virtual void tambahBangunan() = 0;
        virtual User* tambahPemain(map<string,User*> ListUser,pair<int,int> inventorySize,pair<int,int> fieldSize,pair<int,int> farmSize) = 0;

        //Virtual for Petani
        virtual void setLadang(int i, int j, Tanaman* t) = 0;
        virtual void tanamTanaman() = 0;
        virtual Inventory<Tanaman*>& getladang() = 0;
        virtual Tanaman* getTanaman(int i, int j) = 0;
        virtual void cetakLadang() = 0;
        virtual void tambahUmurTanaman() = 0;

        //virtual for Peternak
        virtual void cetakPeternakan() = 0;
        virtual void setPeternakan(int i, int j, Hewan* t) = 0;
        virtual Inventory<Hewan*>& getfarm() = 0;
        virtual Hewan* getHewan(int i, int j) = 0;
        virtual void ternak() = 0;
        virtual void kasihMakan() = 0;

        //Panen: Petani & Peternak
        virtual int getNetoKekayaan() = 0;
        virtual void panen() = 0;

};
 
 
class Walikota: public User{
    private:
        static int jumlah_walikota;
    public:
        Walikota(std::string username, pair<int,int> invSize);
        Walikota(std::string username, int berat, int uang, pair<int,int> invSize);
        ~Walikota();
        void tagihPajak(map<string,User*> ListUser);
        int findMaterial(const string& materialName, int neededQuantity);
        void tambahBangunan();
        User* tambahPemain(map<string,User*> ListUser, pair<int,int> inventorySize,pair<int,int> fieldSize,pair<int,int> farmSize);
        double pungutpajak() override;
        int getNetoKekayaan();

        //virtual untuk cek role
        bool isPetani();
        bool isPeternak();
        bool isWalikota();

        //Virtual from petani
        //Always throw roletidakcocokexception
        void setLadang(int i, int j, Tanaman* t);
        void tanamTanaman();
        Inventory<Tanaman*>& getladang();
        Tanaman* getTanaman(int i, int j);
        void cetakLadang();
        void tambahUmurTanaman();

        //virtual from peternak
        //always throw exception
        void cetakPeternakan();
        void setPeternakan(int i, int j, Hewan* t);
        Inventory<Hewan*>& getfarm();
        Hewan* getHewan(int i, int j);
        void ternak();
        void kasihMakan();

        void panen();

};

class Petani: public User{
    private:
        Inventory<Tanaman*> ladang;
        int tax_amount;
        int KTKP;
        int netoKekayaan = 0;
    public: 
        Petani(std::string username, pair<int,int> invSize, pair<int,int> fieldSize);
        Petani(std::string nama,int berat,int uang,pair<int,int> inventorySize,pair<int,int> fieldSize);
        void setLadang(int i, int j, Tanaman* t);
        void tanamTanaman();
    
        Inventory<Tanaman*>& getladang();
        Tanaman* getTanaman(int i, int j);
        void panen();
        void cetakLadang();

        double pungutpajak() override;
        int getNetoKekayaan();

        void tambahUmurTanaman();

        //virtual untuk cek role
        bool isPetani();
        bool isPeternak();
        bool isWalikota();

        //virtual dari walikota
        //Always throw roletidakcocokException
        void tagihPajak(map<string,User*> ListUser);
        int findMaterial(const string& materialName, int neededQuantity);
        void tambahBangunan();
        User* tambahPemain(map<string,User*> ListUser,pair<int,int> inventorySize,pair<int,int> fieldSize,pair<int,int> farmSize);

        //virtual dari peternakan
        //always throw exception
        void cetakPeternakan();
        void setPeternakan(int i, int j, Hewan* t);
        Inventory<Hewan*>& getfarm();
        Hewan* getHewan(int i, int j);
        void ternak();
        void kasihMakan();
}; 

class Peternak: public User{
    private:
        Inventory<Hewan*> peternakan;
        int KTKP;
        int netoKekayaan = 0;
    public:
        Peternak(std::string nama, pair<int,int> invSize, pair<int,int> farmSize);
        Peternak(std::string nama,int berat,int uang,pair<int,int> inventorySize,pair<int,int> farmSize);
        void cetakPeternakan();
        void setPeternakan(int i, int j, Hewan* t);
        Inventory<Hewan*>& getfarm();

        Hewan* getHewan(int i, int j);
        void ternak();
        void panen();
        void kasihMakan();
        double pungutpajak() override;
        int getNetoKekayaan();

        //virtual untuk cek role
        bool isPetani();
        bool isPeternak();
        bool isWalikota();

        //virtual dari walikota
        //Always throw roletidakcocokException
        void tagihPajak(map<string,User*> ListUser);
        int findMaterial(const string& materialName, int neededQuantity);
        void tambahBangunan();
        User* tambahPemain(map<string,User*> ListUser,pair<int,int> inventorySize,pair<int,int> fieldSize,pair<int,int> farmSize);

        //virtual from petani
        //always throw exception
        void setLadang(int i, int j, Tanaman* t);
        void tanamTanaman();
        Inventory<Tanaman*>& getladang();
        Tanaman* getTanaman(int i, int j);
        void panenTanaman();
        void cetakLadang();
        void tambahUmurTanaman();

};


#endif