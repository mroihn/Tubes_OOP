#include "InvItems.hpp"

map<string,Tanaman*> Tanaman::ListTanaman;
map<string,Hewan*> Hewan::animals;
map<string,Product*> Product::ListProduk;
map<string,Building*> Building::ListBuilding;

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

//getter id
int InvItems::getId(){
    return id;
}

bool InvItems::operator==(const InvItems& other){
    return (id==other.id && kode_huruf==other.kode_huruf && nama==other.nama && price==other.price);
}

ostream& operator<<(ostream& os, InvItems& b){
    os << b.kode_huruf;
    return os;
}

void InvItems::print(){
    cout << id << " " << kode_huruf << " " << nama << " " << price << endl;
}

bool Hewan::isMakanan(){
    return false;
}
bool Tanaman::isMakanan(){
    return false;
}
bool Building::isMakanan(){
    return false;
}
bool Fruit::isMakanan(){
    return true;
}
bool Meat::isMakanan(){
    return true;
}
bool Material::isMakanan(){
    return false;
}

//PRODUCT
Product::Product(){}
Product::Product(int id, string kode_huruf, string nama, string origin, int added_weight, int price): 
InvItems(id,kode_huruf,nama, price){
    this->origin = origin;
    this->added_weight = added_weight;
}
Product* Meat::clone(){
    return new Meat(*this);
}
Product* Fruit::clone(){
    return new Fruit(*this);
}
Product* Material::clone(){
    return new Material(*this);
}

int Hewan::getAddedWeight(){
    throw ItemBukanMakanan();
}
int Tanaman::getAddedWeight(){
    throw ItemBukanMakanan();
}
int Building::getAddedWeight(){
    throw ItemBukanMakanan();
}

void Product::print(){
    cout << id << " " << kode_huruf << " " << nama << " " << origin << " " << added_weight << " " << price << endl;
}
int Product::getAddedWeight(){
    return added_weight;
}

bool Product::isProduct() const {
    return true; 
}

void Product::addListProduk(Product*h){
    Product::ListProduk[h->getNama()] = h;
}
void Product::printListProduk(){
    for (auto Produk : ListProduk) {
        Produk.second->print();
    }
}
map<string,Product*>& Product::getListProduk(){
    return ListProduk;
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
// Hewan::Hewan(const Hewan& other): id(other.id), kode_huruf(other.kode_huruf)

void Hewan::setBerat(int berat){
    this->weight = berat;
}
int Hewan::getBerat(){
    return weight;
}


void Hewan::tambahBerat(int berat){
    weight+=berat;
}

int Hewan::getWeightToHarvestItem(){
    return weight_to_harvest;
}

void Hewan::addListHewan(Hewan*h){
    animals[h->getNama()] = h;
}
void Hewan::printListHewan(){
    for (auto hewan : animals) {
        hewan.second->print();
    }
}
map<string,Hewan*>& Hewan::getListHewan(){
    return animals;
}

void Hewan::print(){
    cout << id << " " << kode_huruf << " " << nama << " " << weight_to_harvest << " " << price << " " << weight << endl;
}

bool Hewan::siapPanen(){
    return weight>=weight_to_harvest;
}

bool Hewan::isProduct() const {
    return false; 
}
Herbivore::Herbivore(){}
Herbivore::Herbivore(int id, string kode_huruf, string nama, int weight_to_harvest, int price): Hewan(id,kode_huruf,nama,weight_to_harvest,price){}

void Herbivore::print(){
    cout << id << " " << kode_huruf << " " << nama << " HERBIVORE " << weight_to_harvest << " " << price << " " << weight << endl;
}

Hewan* Herbivore::clone(){
    return new Herbivore(*this);
}
void Herbivore::makan(InvItems* Food){
    if(Fruit* buah = dynamic_cast<Fruit*>(Food)){
        weight+=buah->getAddedWeight();
        cout << "herbivore makan buah " << buah->getNama() << endl;
    }else if(Fruit* buah = dynamic_cast<Fruit*>(Food)){
        throw HerbivoreMakanDaging();
    }else{
        throw ItemBukanMakanan();
    }
}

vector<Product*> Herbivore::Panen(){
    vector<Product*> products;
    if(kode_huruf=="COW"){
        Product *p = Product::getListProduk()["COW_MEAT"]->clone();
        products.push_back(p);
    }else if(kode_huruf=="SHP"){
        Product *p = Product::getListProduk()["SHEEP_MEAT"]->clone();
        products.push_back(p);
    }else if(kode_huruf=="HRS"){
        Product *p = Product::getListProduk()["HORSE_MEAT"]->clone();
        products.push_back(p);
    }else if(kode_huruf=="RBT"){
        Product *p = Product::getListProduk()["RABBIT_MEAT"]->clone();
        products.push_back(p);
    }else{
        //throw exc
    }
    return products;
}

Carnivore::Carnivore(){}
Carnivore::Carnivore(int id, string kode_huruf, string nama, int weight_to_harvest, int price): Hewan(id,kode_huruf,nama,weight_to_harvest,price){}

void Carnivore::print(){
    cout << id << " " << kode_huruf << " " << nama << " CARNIVORE " << weight_to_harvest << " " << price << " " << weight << endl;
}

Hewan* Carnivore::clone(){
    return new Carnivore(*this);
}

void Carnivore::makan(InvItems* Food){
    if(Meat* daging = dynamic_cast<Meat*>(Food)){
        weight+=daging->getAddedWeight();
        cout << "carnivore makan daging " << daging->getNama() << endl; 
    }else if(Fruit* daging = dynamic_cast<Fruit*>(Food)){
        throw CarnivoreMakanBuah();
    }else{
        throw ItemBukanMakanan();
    }
}

vector<Product*> Carnivore::Panen(){
    vector<Product*> products;
    if(kode_huruf=="SNK"){
        Product *p = Product::getListProduk()["SNAKE_MEAT"]->clone();
        products.push_back(p);
    }else{
        //throw exc
    }
    return products;
}

Omnivore::Omnivore(){}
Omnivore::Omnivore(int id, string kode_huruf, string nama, int weight_to_harvest, int price): Hewan(id,kode_huruf,nama,weight_to_harvest,price){}

void Omnivore::print(){
    cout << id << " " << kode_huruf << " " << nama << " OMNIVORE " << weight_to_harvest << " " << price << " " << weight << endl;
}

Hewan* Omnivore::clone(){
    return new Omnivore(*this);
}

void Omnivore::makan(InvItems* Food){
    if(Fruit* makanan = dynamic_cast<Fruit*>(Food)){
        weight+=makanan->getAddedWeight();
        return;
    }
    if(Meat* makanan = dynamic_cast<Meat*>(Food)){
        weight+=makanan->getAddedWeight();
        return;
    }
    throw ItemBukanMakanan();
}

vector<Product*> Omnivore::Panen(){
    vector<Product*> products;
    if(kode_huruf=="CHK"){
        Product *M = Product::getListProduk()["CHICKEN_MEAT"]->clone();
        products.push_back(M);
        Product *E = Product::getListProduk()["CHICKEN_EGG"]->clone();
        products.push_back(E);
    }else if(kode_huruf=="DCK"){
        Product *M = Product::getListProduk()["DUCK_MEAT"]->clone();
        products.push_back(M);
        Product *E = Product::getListProduk()["DUCK_EGG"]->clone();
        products.push_back(E);
    }else{
        //throw exc
    }
    return products;
}


Tanaman::Tanaman(){}
Tanaman::Tanaman(int id, string kode_huruf, string nama, int duration_to_harvest, int price): 
InvItems(id,kode_huruf,nama, price){
    this->duration_to_harvest = duration_to_harvest;
    this->umur_tanaman = 0;
}


void Tanaman::setUmur(int umur){
    this->umur_tanaman = umur;
}
int Tanaman::getUmur(){
    return umur_tanaman;
}
void Tanaman::tambahUmurTanaman(){
    umur_tanaman++;
}

int Tanaman::getDurationToHarvestItem(){
    return duration_to_harvest;
}

map<string, Tanaman*>& Tanaman::getlistTanaman(){
    return ListTanaman;
}
void Tanaman::addlistTanaman(Tanaman*h){
    ListTanaman[h->getNama()] = h;
}
void Tanaman::printListTanaman(){
    for (auto& tanaman : ListTanaman) {
        tanaman.second->print();
    }
}

void Tanaman::print(){
    cout << id << " " << kode_huruf << " " << nama << " " << duration_to_harvest << " " << price << " " << umur_tanaman << endl;
}


bool Tanaman::siapPanen(){
    return umur_tanaman>=duration_to_harvest;
}

bool Tanaman::isProduct() const {
    return false; 
}

Material_Plant::Material_Plant(){}
Material_Plant::Material_Plant(int id, string kode_huruf, string nama, int duration_to_harvest, int price): Tanaman(id,kode_huruf,nama,duration_to_harvest,price){}

void Material_Plant::print(){
    cout << id << " " << kode_huruf << " " << nama << " MATERIAL_PLANT " << duration_to_harvest << " " << price << " " << umur_tanaman << endl;
}

Product* Material_Plant::Panen(){
    if(kode_huruf=="TEK"){
        Product * p = Product::getListProduk()["TEAK_WOOD"]->clone();
        return p;
    }else if(kode_huruf == "SDT"){
        Product * p = Product::getListProduk()["SANDALWOOD_WOOD"]->clone();
        return p;
    }else if(kode_huruf=="ALT"){
        Product * p = Product::getListProduk()["ALOE_WOOD"]->clone();
        return p;
    }else if(kode_huruf=="IRN"){
        Product * p = Product::getListProduk()["IRONWOOD_WOOD"]->clone();
        return p;
    }else{
        cout << "Tidak ada resep panen yang cocok\n";
        return nullptr;
    }
}
Tanaman* Material_Plant::clone(){
    return new Material_Plant(*this);
}

Fruit_Plant::Fruit_Plant(){}
Fruit_Plant::Fruit_Plant(int id, string kode_huruf, string nama, int duration_to_harvest, int price): Tanaman(id,kode_huruf,nama,duration_to_harvest,price){}

void Fruit_Plant::print(){
    cout << id << " " << kode_huruf << " " << nama << " FRUIT_PLANT " << duration_to_harvest << " " << price << " " << umur_tanaman << endl;
}

Product* Fruit_Plant::Panen(){
    if(kode_huruf=="APL"){
        Product * p = Product::getListProduk()["APPLE"]->clone();
        return p;
    }else if(kode_huruf == "ORG"){
        Product * p = Product::getListProduk()["ORANGE"]->clone();
        return p;
    }else if(kode_huruf=="BNT"){
        Product * p = Product::getListProduk()["BANANA"]->clone();
        return p;
    }else if(kode_huruf=="GAV"){
        Product * p = Product::getListProduk()["GUAVA"]->clone();
        return p;
    }else{
        cout << "Tidak ada resep panen yang cocok\n";
        return nullptr;
    }
}

Tanaman* Fruit_Plant::clone(){
    return new Fruit_Plant(*this);
}




Building::Building(){}
Building::Building(int id, string kode_huruf, string nama, int price, map<string,int> recipe):
InvItems(id, kode_huruf, nama,price){
    this->recipe = recipe;
}

void Building::print(){
    cout << getId() << ". " << nama << " (";
    for (auto it = recipe.begin(); it != recipe.end(); ++it) {
        const string& material = it->first;
        int quantity = it->second;
        cout << material << " " << quantity;
        if (next(it) != recipe.end()) {
            cout << ", ";
        }
    }
    cout << ")" << endl;
}

bool Building::isProduct() const {
    return false; 
}

map<string, Building*>& Building::getlistBuilding(){
    return ListBuilding;
}

map<string, int> Building::getRecipe() const {
    return recipe;
}

void Building::addlistBuilding(Building* h){
    ListBuilding[h->getNama()] = h;
}

void Building::printListBuilding() {
    vector<pair<string, Building*>> buildingVector(ListBuilding.begin(), ListBuilding.end());
    
    // Urutkan vektor secara terbalik
    reverse(buildingVector.begin(), buildingVector.end());

    // Cetak elemen-elemen vektor
    for (const auto& building : buildingVector) {
        building.second->print();
    }
}


Building* Building::clone(){
    return new Building(*this);
}