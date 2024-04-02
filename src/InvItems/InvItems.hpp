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
        InvItems() {}

        InvItems(int id, string kode_huruf, string nama, string type, int price)
        : id(id), kode_huruf(kode_huruf), nama(nama), price(price) {}
        string getKode(){
            return kode_huruf;
        }

        // getter price
        int getPriceItem(){
            return price;
        }

        friend ostream& operator<<(ostream& os, InvItems& b){
            os << b.kode_huruf;
            return os;
        }
};


class Hewan: public InvItems{
    protected:
        int weight_to_harvest;
        string type;
    public:
        Hewan(){}
        Hewan(int id, string kode_huruf, string nama, string type, int weight_to_harvest, int price): 
        InvItems(id,kode_huruf,nama, type, price){
            this->weight_to_harvest = weight_to_harvest;
            this->type = type;
        }

        void print(){
            cout << id << " " << kode_huruf << " " << nama << " " << type << " " << weight_to_harvest << " " << price << endl;
        }
};

class Tanaman: public InvItems{
    protected:
        int duration_to_harvest;
        string type;
    public:
        Tanaman(){}
        Tanaman(int id, string kode_huruf, string nama, string type, int duration_to_harvest, int price): 
        InvItems(id,kode_huruf,nama, type, price){
            this->duration_to_harvest = duration_to_harvest;
            this->type = type;
        }

        void print(){
            cout << id << " " << kode_huruf << " " << nama << " " << type << " " << duration_to_harvest << " " << price << endl;
        }
};

class TanamanLadang: public Tanaman{
    private:
        int umur_tanaman;
    public:
        TanamanLadang(){}
        TanamanLadang(int id, string kode_huruf, string nama, string type, int duration_to_harvest, int price): 
        Tanaman(id,kode_huruf,nama, type, duration_to_harvest, price){
            this->umur_tanaman = 0;
        }

        void print(){
            cout << id << " " << kode_huruf << " " << nama << " " << type << " " << duration_to_harvest << " " << price << endl;
        }
};

//<ID> <KODE_HURUF> <NAME> <TYPE> <ORIGIN> <ADDED_WEIGHT> <PRICE>
class Product: public InvItems{
    private:
        string origin;
        int added_weight;
        string type;
    public:
        Product(){}
        Product(int id, string kode_huruf, string nama, string type, string origin, int added_weight, int price): 
        InvItems(id,kode_huruf,nama, type, price){
            this->origin = origin;
            this->added_weight = added_weight;
            this->type = type;
        }
        void print(){
            cout << id << " " << kode_huruf << " " << nama << " " << type << " " << origin << " " << added_weight << " " << price << endl;
        }
};


//<ID> <KODE_HURUF> <NAME> <PRICE> <MATERIAL_1> <MATERIAL_1_QUANTITY> <MATERIAL_2> <MATERIAL_2_QUANTITY> ... <MATERIAL_N> <MATERIAL_N_QUANTITY>
//Building tidak perlu Material dan quantity, karena tdk digunakan dalam Inventory
class Building: public InvItems{
    public:
        Building(){}
        Building(int id, string kode_huruf, string nama, int price):
        InvItems(id, kode_huruf, nama, "",price){}
        void print(){
            cout << id << " " << kode_huruf << " " << nama << price << endl;
        }
};