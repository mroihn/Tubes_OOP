// ini adalah InvItems.hpp
#ifndef INVITEMS_HPP
#define INVITEMS_HPP

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include "InvItemsException.hpp"
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

        //Operator overloading (akan memprint nama item)
        friend ostream& operator<<(ostream& os, InvItems& b);
        //memprint semua atribut objek
        virtual void print();
        virtual bool isMakanan() const = 0;


};

//<ID> <KODE_HURUF> <NAME> <TYPE> <ORIGIN> <ADDED_WEIGHT> <PRICE>
//Turunan: Material, Fruit, Meat
//Types: PRODUCT_MATERIAL_PLANT, PRODUCT_FRUIT_PLANT, PRODUCT_ANIMAL
class Product: public InvItems{
    protected:
        string origin;
        int added_weight;
        static map<string,Product*> ListProduk;
    public:
        Product();
        Product(int id, string kode_huruf, string nama, string origin, int added_weight, int price);
        Product* clone();
        void print();
        static void addListProduk(Product* p);
        static void printListProduk();
        static map<string, Product*>& getListProduk();
        int getAddedWeight();
        bool isMakanan() const override;
};

//Type : PRODUCT_MATERIAL_PLANT
class Material: public Product{
    public:
        Material();
        Material(int id, string kode_huruf, string nama, string origin, int added_weight, int price);
        void print();
};

//Type : PRODUCT_FRUIT_PLANT
class Fruit: public Product{
    public:
        Fruit();
        Fruit(int id, string kode_huruf, string nama, string origin, int added_weight, int price);
        void print();
};

//Type : PRODUCT_ANIMAL
class Meat: public Product{
    public:
        Meat();
        Meat(int id, string kode_huruf, string nama, string origin, int added_weight, int price);
        void print();
};

//<ID> <KODE_HURUF> <NAME> <TYPE> <WEIGHT_TO_HARVEST> <PRICE> <BERAT>
//Turunan: Herbivora, Carnivore, Omnivore
class Hewan: public InvItems{
    protected:
        int weight_to_harvest;
        int weight;
        static map<string,Hewan*> animals;
    public:
        Hewan();
        //user defined constructor, dengan berat awal 0
        Hewan(int id, string kode_huruf, string nama, int weight_to_harvest, int price);
        virtual Hewan* clone() =0;
        void setBerat(int berat);
        void tambahBerat(int berat);
        int getWeightToHarvestItem();
        static void addListHewan(Hewan*h);
        static void printListHewan();
        static map<string,Hewan*>& getListHewan();
        virtual void print();
        virtual vector<Product*> Panen() = 0;
        bool siapPanen();
        bool isMakanan() const override;
};

class Herbivore: public Hewan{
    public:
        Herbivore();
        Herbivore(int id, string kode_huruf, string nama, int weight_to_harvest, int price);

        Hewan* clone();
        void print();
        vector<Product*> Panen();
        void makan(Product* Food);
};

class Carnivore: public Hewan{
    public:
        Carnivore();
        Carnivore(int id, string kode_huruf, string nama, int weight_to_harvest, int price);

        Hewan* clone();
        void print();
        void makan(Product* Food);
        vector<Product*> Panen();
};
class Omnivore: public Hewan{

    public:
        Omnivore();
        Omnivore(int id, string kode_huruf, string nama, int weight_to_harvest, int price);

        Hewan* clone();
        void print();
        void makan(Product* Food);
        vector<Product*> Panen();
};

//<ID> <KODE_HURUF> <NAME> <TYPE> <DURATION_TO_HARVEST> <PRICE> <UMUR>
//Turunan: Material_Plant, Fruit_Plant
class Tanaman: public InvItems{
    protected:
        static map<string,Tanaman*> ListTanaman;
        int duration_to_harvest;
        int umur_tanaman;
    public:
        Tanaman();
        //user defined constructor, umur di awal selalu 0
        Tanaman(int id, string kode_huruf, string nama, int duration_to_harvest, int price);
        void setUmur(int umur);
        virtual Tanaman* clone() = 0;
        void tambahUmurTanaman();
        int getDurationToHarvestItem();
        static map<string, Tanaman*>& getlistTanaman();
        static void addlistTanaman(Tanaman*h);
        static void printListTanaman();
        virtual Product* Panen() = 0;
        virtual void print();
        bool siapPanen();
        bool isMakanan() const override;
};

class Material_Plant: public Tanaman{
    public:
        Material_Plant();
        Material_Plant(int id, string kode_huruf, string nama, int duration_to_harvest, int price);
        Product* Panen();
        Tanaman* clone();
        void print();
};

class Fruit_Plant: public Tanaman{
    public:
        Fruit_Plant();
        Fruit_Plant(int id, string kode_huruf, string nama, int duration_to_harvest, int price);
        Product* Panen();
        Tanaman* clone();
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
        bool isMakanan() const override;
};

#endif