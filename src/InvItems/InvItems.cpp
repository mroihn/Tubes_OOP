#include "InvItems.hpp"

InvItems::InvItems() {}

InvItems::InvItems(int id, string kode_huruf, string nama, int price)
: id(id), kode_huruf(kode_huruf), nama(nama), price(price) {}

// getter kode
string InvItems::getKode(){
    return kode_huruf;
}
// getter nama
string InvItems::getNama(){
    return nama;
}

// getter price
int InvItems::getPriceItem(){
    return price;
}

int InvItems::getDurationToHarvestItem(){
    return 0;
}

ostream& operator<<(ostream& os, InvItems& b){
    os << b.kode_huruf;
    return os;
}

void InvItems::print(){
    cout << id << " " << kode_huruf << " " << nama << " " << price << endl;
}

Hewan::Hewan(){}

Hewan::Hewan(int id, string kode_huruf, string nama, string type, int weight_to_harvest, int price): 
InvItems(id,kode_huruf,nama, price){
    this->weight_to_harvest = weight_to_harvest;
    this->type = type;
    this ->weight = 0;
}

Hewan::Hewan(int id, string kode_huruf, string nama, string type, int weight_to_harvest, int price, int weight): 
InvItems(id,kode_huruf,nama, price){
    this->weight_to_harvest = weight_to_harvest;
    this->type = type;
    this ->weight = weight;
}

void Hewan::print(){
    cout << id << " " << kode_huruf << " " << nama << " " << type << " " << weight_to_harvest << " " << price << endl;
}


Tanaman::Tanaman(){}
Tanaman::Tanaman(int id, string kode_huruf, string nama, string type, int duration_to_harvest, int price): 
InvItems(id,kode_huruf,nama, price){
    this->duration_to_harvest = duration_to_harvest;
    this->type = type;
    this->umur_tanaman = 0;
}

int Tanaman::getDurationToHarvestItem(){
    return duration_to_harvest;
}

void Tanaman::print(){
    cout << id << " " << kode_huruf << " " << nama << " " << type << " " << duration_to_harvest << " " << price << " " << umur_tanaman << endl;
}


bool Tanaman::siapPanen(){
    return umur_tanaman>=duration_to_harvest;
}

Product::Product(){}
Product::Product(int id, string kode_huruf, string nama, string type, string origin, int added_weight, int price): 
InvItems(id,kode_huruf,nama, price){
    this->origin = origin;
    this->added_weight = added_weight;
    this->type = type;
}
void Product::print(){
    cout << "Tumbuhan" << id << " " << kode_huruf << " " << nama << " " << type << " " << origin << " " << added_weight << " " << price << endl;
}

Building::Building(){}
Building::Building(int id, string kode_huruf, string nama, int price):
InvItems(id, kode_huruf, nama,price){}
void Building::print(){
    cout << id << " " << kode_huruf << " " << nama << price << endl;
}