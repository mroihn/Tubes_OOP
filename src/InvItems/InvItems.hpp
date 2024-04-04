// ini adalah InvItems.hpp

#include <string>
#include <iostream>
#include <vector>
using namespace std;

class InvItems{
    protected:
        int id;
        string kode_huruf;
        string nama;
        int price;
    public:
        InvItems();
        InvItems(int id, string kode_huruf, string nama, int price);

        string getKode();
        string getNama();
        int getPriceItem();
        virtual int getDurationToHarvestItem();

        //Operator overloading (akan memprint nama item)
        friend ostream& operator<<(ostream& os, InvItems& b);
        //memprint semua atribut objek
        virtual void print();
};

//<ID> <KODE_HURUF> <NAME> <TYPE> <WEIGHT_TO_HARVEST> <PRICE>
class Hewan: public InvItems{
    protected:
        int weight_to_harvest;
        string type;
    public:
        Hewan();
        Hewan(int id, string kode_huruf, string nama, string type, int weight_to_harvest, int price);

        void print();
};

//<ID> <KODE_HURUF> <NAME> <TYPE> <DURATION_TO_HARVEST> <PRICE>
class Tanaman: public InvItems{
    protected:
        int duration_to_harvest;
        string type;
    public:
        Tanaman();
        Tanaman(int id, string kode_huruf, string nama, string type, int duration_to_harvest, int price);

        int getDurationToHarvestItem();

        void print();
        virtual bool siapPanen() = 0;
};

//<ID> <KODE_HURUF> <NAME> <TYPE> <DURATION_TO_HARVEST> <PRICE> <UMUR_TANAMAN>
class TanamanLadang: public Tanaman{
    private:
        int umur_tanaman;
    public:
        TanamanLadang(){}
        TanamanLadang(int id, string kode_huruf, string nama, string type, int duration_to_harvest, int price);

        void print();
        //Cek apakah tanaman siap untuk dipanen
        bool siapPanen();
};

//<ID> <KODE_HURUF> <NAME> <TYPE> <ORIGIN> <ADDED_WEIGHT> <PRICE>
class Product: public InvItems{
    private:
        string origin;
        int added_weight;
        string type;
    public:
        Product();
        Product(int id, string kode_huruf, string nama, string type, string origin, int added_weight, int price);
        void print();
};


//<ID> <KODE_HURUF> <NAME> <PRICE> <MATERIAL_1> <MATERIAL_1_QUANTITY> <MATERIAL_2> <MATERIAL_2_QUANTITY> ... <MATERIAL_N> <MATERIAL_N_QUANTITY>
//Building tidak perlu Material dan quantity, karena tdk digunakan dalam Inventory
class Building: public InvItems{
    public:
        Building(){}
        Building(int id, string kode_huruf, string nama, int price):
        InvItems(id, kode_huruf, nama,price){}
        void print(){
            cout << id << " " << kode_huruf << " " << nama << price << endl;
        }
};