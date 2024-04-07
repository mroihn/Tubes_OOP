#include "InvItems.hpp"

//InvItems
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


ostream& operator<<(ostream& os, InvItems& b){
    os << b.kode_huruf;
    return os;
}

void InvItems::print(){
    cout << id << " " << kode_huruf << " " << nama << " " << price << endl;
}

//PRODUCT
Product::Product(){}
Product::Product(int id, string kode_huruf, string nama, string origin, int added_weight, int price): 
InvItems(id,kode_huruf,nama, price){
    this->origin = origin;
    this->added_weight = added_weight;
}
void Product::print(){
    cout << id << " " << kode_huruf << " " << nama << " " << origin << " " << added_weight << " " << price << endl;
}
int Product::getAddedWeight(){
    return added_weight;
}

Material::Material(){}
Material::Material(int id, string kode_huruf, string nama, string origin, int added_weight, int price): Product(id,kode_huruf,nama, origin,added_weight,price){}
void Material::print(){
    cout << id << " " << kode_huruf << " " << nama << " PRODUCT_MATERIAL_PLANT " << origin << " " << added_weight << " " << price << endl;
}

Fruit::Fruit(){}
Fruit::Fruit(int id, string kode_huruf, string nama, string origin, int added_weight, int price): Product(id,kode_huruf,nama, origin,added_weight,price){}
void Fruit::print(){
    cout << id << " " << kode_huruf << " " << nama << " PRODUCT_FRUIT_PLANT " << origin << " " << added_weight << " " << price << endl;
}

Meat::Meat(){}
Meat::Meat(int id, string kode_huruf, string nama, string origin, int added_weight, int price): Product(id,kode_huruf,nama, origin,added_weight,price){}
void Meat::print(){
    cout << id << " " << kode_huruf << " " << nama << " PRODUCT_ANIMAL " << origin << " " << added_weight << " " << price << endl;
}

Hewan::Hewan(){}

Hewan::Hewan(int id, string kode_huruf, string nama, int weight_to_harvest, int price): 
InvItems(id,kode_huruf,nama, price){
    this->weight_to_harvest = weight_to_harvest;
    this ->weight = 0;
}

void Hewan::tambahBerat(int berat){
    weight+=berat;
}

int Hewan::getWeightToHarvestItem(){
    return weight_to_harvest;
}

void Hewan::print(){
    cout << id << " " << kode_huruf << " " << nama << " " << weight_to_harvest << " " << price << " " << weight << endl;
}

bool Hewan::siapPanen(){
    return weight>=weight_to_harvest;
}

Herbivore::Herbivore(){}
Herbivore::Herbivore(int id, string kode_huruf, string nama, int weight_to_harvest, int price): Hewan(id,kode_huruf,nama,weight_to_harvest,price){}

void Herbivore::print(){
    cout << id << " " << kode_huruf << " " << nama << " HERBIVORE " << weight_to_harvest << " " << price << " " << weight << endl;
}
void Herbivore::makan(Product* Food){
    if(Fruit* buah = dynamic_cast<Fruit*>(Food)){
        weight+=Food->getAddedWeight();
        cout << "herbivore makan buah " << buah->getNama() << endl;
    }else{
        throw MakananTidakCocokException();
    }
}

Carnivore::Carnivore(){}
Carnivore::Carnivore(int id, string kode_huruf, string nama, int weight_to_harvest, int price): Hewan(id,kode_huruf,nama,weight_to_harvest,price){}

void Carnivore::print(){
    cout << id << " " << kode_huruf << " " << nama << " CARNIVORE " << weight_to_harvest << " " << price << " " << weight << endl;
}
void Carnivore::makan(Product* Food){
    if(Meat* daging = dynamic_cast<Meat*>(Food)){
        weight+=Food->getAddedWeight();
        cout << "carnivore makan daging " << daging->getNama() << endl; 
    }else{
        throw MakananTidakCocokException();
    }
}

Omnivore::Omnivore(){}
Omnivore::Omnivore(int id, string kode_huruf, string nama, int weight_to_harvest, int price): Hewan(id,kode_huruf,nama,weight_to_harvest,price){}

void Omnivore::print(){
    cout << id << " " << kode_huruf << " " << nama << " OMNIVORE " << weight_to_harvest << " " << price << " " << weight << endl;
}
void Omnivore::makan(Product* Food){
    weight+=Food->getAddedWeight();
}


Tanaman::Tanaman(){}
Tanaman::Tanaman(int id, string kode_huruf, string nama, int duration_to_harvest, int price): 
InvItems(id,kode_huruf,nama, price){
    this->duration_to_harvest = duration_to_harvest;
    this->umur_tanaman = 0;
}

void Tanaman::tambahUmurTanaman(){
    umur_tanaman++;
}

int Tanaman::getDurationToHarvestItem(){
    return duration_to_harvest;
}

void Tanaman::print(){
    cout << id << " " << kode_huruf << " " << nama << " " << duration_to_harvest << " " << price << " " << umur_tanaman << endl;
}


bool Tanaman::siapPanen(){
    return umur_tanaman>=duration_to_harvest;
}

Material_Plant::Material_Plant(){}
Material_Plant::Material_Plant(int id, string kode_huruf, string nama, int duration_to_harvest, int price): Tanaman(id,kode_huruf,nama,duration_to_harvest,price){}

void Material_Plant::print(){
    cout << id << " " << kode_huruf << " " << nama << " MATERIAL_PLANT " << duration_to_harvest << " " << price << " " << umur_tanaman << endl;
}

Fruit_Plant::Fruit_Plant(){}
Fruit_Plant::Fruit_Plant(int id, string kode_huruf, string nama, int duration_to_harvest, int price): Tanaman(id,kode_huruf,nama,duration_to_harvest,price){}

void Fruit_Plant::print(){
    cout << id << " " << kode_huruf << " " << nama << " FRUIT_PLANT " << duration_to_harvest << " " << price << " " << umur_tanaman << endl;
}




Building::Building(){}
Building::Building(int id, string kode_huruf, string nama, int price, map<string,int> recipe):
InvItems(id, kode_huruf, nama,price){
    this->recipe = recipe;
}
void Building::print(){
    cout << id << " " << kode_huruf << " " << nama << " " << price << " ";
    for(auto it = recipe.begin(); it != recipe.end(); ++it){
        const std::string& material = it->first;
        int quantity = it->second;
        cout << material << " " << quantity << " ";
    }
    cout << endl;
}
