// ini adalah InvItems.hpp
#ifndef INVITEMS_H
#define INVITEMS_H

#include <string>
#include <iostream>
#include <vector>
#include <map>
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

//<ID> <KODE_HURUF> <NAME> <TYPE> <WEIGHT_TO_HARVEST> <PRICE> <BERAT>
class Hewan: public InvItems{
    protected:
        int weight_to_harvest;
        string type;
        int weight;
    public:
        Hewan();
        //user defined constructor, dengan berat awal 0
        Hewan(int id, string kode_huruf, string nama, string type, int weight_to_harvest, int price);
        //user defined constructor, dengan berat awal diset oleh user
        Hewan(int id, string kode_huruf, string nama, string type, int weight_to_harvest, int price, int weight);

        void print();
};

//<ID> <KODE_HURUF> <NAME> <TYPE> <DURATION_TO_HARVEST> <PRICE> <UMUR>
class Tanaman: public InvItems{
    protected:
        int duration_to_harvest;
        string type;
        int umur_tanaman;
    public:
        Tanaman();
        //user defined constructor, umur di awal selalu 0
        Tanaman(int id, string kode_huruf, string nama, string type, int duration_to_harvest, int price);

        int getDurationToHarvestItem();

        void print();
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
    private:
        map<string, int> recipe;
    public:
        Building();
        Building(int id, string kode_huruf, string nama, int price, map<string, int> recipe);
        void print();
};

#endif