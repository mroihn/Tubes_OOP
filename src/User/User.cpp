#include "User.hpp"
#include <limits>
#include <stdexcept>
#include <cmath>

using namespace std;

User::User(std::string username, pair<int,int> invSize): penyimpanan(invSize.first, invSize.second){
    this->username = username;
    berat_badan = 40;
    uang = 50;
    // n_player++;
    // id = n_player;
}
User::User(std::string username, int berat,int uang, pair<int,int> invSize): penyimpanan(invSize.first, invSize.second){
    this->username = username;
    this->berat_badan = berat;
    this->uang = uang;
}

User::~User(){}

string User::getNama(){
    return username;
}

int User::getBerat(){
    return berat_badan;
}
Inventory<InvItems*>& User::getInv(){
    return penyimpanan;
}

int User::getUang(){
    return uang;
} 

//validasi Walikota
void Peternak::tagihPajak(map<string,User*> ListUser){
    throw RoleTidakSesuai();
}
int Peternak::findMaterial(const string& materialName, int neededQuantity){
    throw RoleTidakSesuai();
}
void Peternak::tambahBangunan(){
    throw RoleTidakSesuai();
}
User* Peternak::tambahPemain(map<string,User*> ListUser,pair<int,int> inventorySize,pair<int,int> fieldSize,pair<int,int> farmSize){
    throw RoleTidakSesuai();
}
void Petani::tagihPajak(map<string,User*> ListUser){
    throw RoleTidakSesuai();
}
int Petani::findMaterial(const string& materialName, int neededQuantity){
    throw RoleTidakSesuai();
}
void Petani::tambahBangunan(){
    throw RoleTidakSesuai();
}
User* Petani::tambahPemain(map<string,User*> ListUser,pair<int,int> inventorySize,pair<int,int> fieldSize,pair<int,int> farmSize){
    throw RoleTidakSesuai();
}
//Validasi Petani
void Walikota::setLadang(int i, int j, Tanaman* t){
    throw RoleTidakSesuai();
}
void Walikota::tanamTanaman(){
    throw RoleTidakSesuai();
}

Inventory<Tanaman*>& Walikota::getladang(){
    throw RoleTidakSesuai();
}
Tanaman* Walikota::getTanaman(int i, int j){
    throw RoleTidakSesuai();
}
void Walikota::panen(){
    throw RoleTidakSesuai();
}
void Walikota::cetakLadang(){
    throw RoleTidakSesuai();
}
int Walikota::getNetoKekayaan(){
    throw RoleTidakSesuai();
}
void Walikota::tambahUmurTanaman(){
    throw RoleTidakSesuai();
}
void Peternak::setLadang(int i, int j, Tanaman* t){
    throw RoleTidakSesuai();
}
void Peternak::tanamTanaman(){
    throw RoleTidakSesuai();
}

Inventory<Tanaman*>& Peternak::getladang(){
    throw RoleTidakSesuai();
}
Tanaman* Peternak::getTanaman(int i, int j){
    throw RoleTidakSesuai();
}
void Peternak::cetakLadang(){
    throw RoleTidakSesuai();
}
void Peternak::tambahUmurTanaman(){
    throw RoleTidakSesuai();
}

//Validasi Peternak
void Walikota::cetakPeternakan(){
    throw RoleTidakSesuai();
}
void Walikota::setPeternakan(int i, int j, Hewan* t){
    throw RoleTidakSesuai();
}
Inventory<Hewan*>& Walikota::getfarm(){
    throw RoleTidakSesuai();
}

Hewan* Walikota::getHewan(int i, int j){
    throw RoleTidakSesuai();
}
void Walikota::ternak(){
    throw RoleTidakSesuai();
}
void Walikota::kasihMakan(){
    throw RoleTidakSesuai();
}
void Petani::cetakPeternakan(){
    throw RoleTidakSesuai();
}
void Petani::setPeternakan(int i, int j, Hewan* t){
    throw RoleTidakSesuai();
}
Inventory<Hewan*>& Petani::getfarm(){
    throw RoleTidakSesuai();
}

Hewan* Petani::getHewan(int i, int j){
    throw RoleTidakSesuai();
}
void Petani::ternak(){
    throw RoleTidakSesuai();
}
void Petani::kasihMakan(){
    throw RoleTidakSesuai();
}

//Validasi role
bool Walikota::isPetani(){
    return false;
}
bool Walikota::isPeternak(){
    return false;
}
bool Walikota::isWalikota(){
    return true;
}
bool Petani::isPetani(){
    return true;
}
bool Petani::isPeternak(){
    return false;
}
bool Petani::isWalikota(){
    return false;
}
bool Peternak::isPeternak(){
    return true;
}
bool Peternak::isPetani(){
    return false;
}
bool Peternak::isWalikota(){
    return false;
}
void User::next(){}
void User::cetak_penyimpanan(){
    int length1 = (7 + (penyimpanan.getCols()-1)*6)/2 - 7;
    int i;
    cout << "     ";
    for (i=0;i<length1;i++){
        cout << '=';
    }
    cout << "[ Penyimpanan ]";
    if (penyimpanan.getCols()%2==0){
        length1++;
    }
    for (i=0;i<length1;i++){
        cout << '=';
    }
    cout << '\n';
    cout << "        ";
    for(int i=0; i<penyimpanan.getCols(); i++){
        cout << char('A'+i) << "     ";
    }
    cout << endl;
    for (int i = 0; i < penyimpanan.getRows(); ++i) {
        cout << "     ";
        for (int j = 0; j < penyimpanan.getCols(); ++j) {
            cout << "+-----";
        }
        cout << "+" << endl;
        cout << "  " << setw(2) << setfill(' ') << i+1;
        for (int j = 0; j < penyimpanan.getCols(); ++j) {
            cout << " | ";
            if (penyimpanan(i,j)){
                cout << penyimpanan(i,j)->getKode();
            }
            else{
                cout << "   ";
            }
        }
        cout << " |" << endl;
    }
    cout << "     ";
    for (int j = 0; j < penyimpanan.getCols(); ++j) {
        cout << "+-----";
    }
    cout << "+\n\n";
}
void User::setPenyimpanan(int i, int j, InvItems* item){
    if (i>=penyimpanan.getRows() || j>penyimpanan.getCols() || i<0 || j<0){
        throw BarisKolomTidakSesuai();
    }
    penyimpanan.incNeff();
    delete penyimpanan(i,j);
    penyimpanan(i,j) = item;
}

void User :: setPenyimpanan( InvItems* item){
    for (int i = 0; i < penyimpanan.getRows();i++){
        for (int j = 0; j < penyimpanan.getCols();j++){
            if(penyimpanan(i,j) == nullptr){
                this->setPenyimpanan(i, j, item);
                return ;
            }
        }
    }
}

void User::makan() {
    cetak_penyimpanan();
    std::string slot;
    std::string subslot;
    cout << "\nSlot: ";
    cin >> slot;
    subslot = slot.substr(1, 2);
    int i = stoi(subslot) - 1;
    int j = slot[0] - 'A';


    try {
        // Melakukan penanganan exception
        if (i >= penyimpanan.getRows() || j >= penyimpanan.getCols() || i < 0 || j < 0) {
            throw BarisKolomTidakSesuai();
        }

        if (penyimpanan(i, j) == nullptr) {
            throw HarapanKosong();
        }

        // Menambah berat badan jika item di slot adalah makanan
        InvItems* item = penyimpanan(i, j);
        if(item->isMakanan()){
            berat_badan+=item->getAddedWeight();
            cout << "Dengan lahapnya, kamu memakan hidangan itu." << endl;
            cout << "Alhasil, berat badan kamu naik menjadi " << berat_badan << endl;
            penyimpanan(i, j) = nullptr;
            penyimpanan.decNeff();
            return;
        }
        throw BukanMakanan();
    } catch (BarisKolomTidakSesuai &e) {
        for (int i = 0; i < e.what().length(); ++i) {
            print_red(e.what()[i]);
        }
    } catch (HarapanKosong &e) {
        for (int i = 0; i < e.what().length(); ++i) {
            print_red(e.what()[i]);
        }
    } catch (BukanMakanan &e) {
        for (int i = 0; i < e.what().length(); ++i) {
            print_red(e.what()[i]);
        }
    }catch (InvItemsException& e){
        for (int i = 0; i < e.what().length(); ++i) {
            print_red(e.what()[i]);
        }
    }
}

int User :: sisaPenyimpanan(){
    return penyimpanan.getCols() * penyimpanan.getRows() - penyimpanan.getNeff();
}

void User::beli(int harga){
    uang -= harga;
}

InvItems* User::jual(int i,int j){
    InvItems *barang;
    if(penyimpanan(i, j) == nullptr){
        throw SlotKosong();
    }
    uang += penyimpanan(i,j)->getPriceItem();
    barang = penyimpanan(i, j);
    penyimpanan(i, j) = nullptr;
    penyimpanan.decNeff();
    
    return barang;
}

void User::batalJual(InvItems* item,int i,int j){
    uang -= item->getPriceItem();
    this->setPenyimpanan(i, j, item);
}
 

int Walikota::jumlah_walikota = 0;
Walikota::Walikota(std::string username, pair<int, int> invSize) : User(username, invSize){
    if(jumlah_walikota!=0){
        throw WalikotaHanyaSatu();
    }
    jumlah_walikota++;
}
Walikota::Walikota(std::string username, int berat, int uang, pair<int,int> invSize): User(username, berat, uang, invSize){
    if(jumlah_walikota!=0){
        throw WalikotaHanyaSatu();
    }
    jumlah_walikota++;
}
Walikota::~Walikota(){}

void Walikota::tagihPajak(map<string,User*> ListUser){
    cout << "Cring cring cring..." << endl;
    cout << "Pajak sudah dipungut!" << endl;
    cout << "\n";
    cout << "Berikut adalah detil dari pemungutan" << endl;
    map<std::string, User*>::iterator itr = ListUser.begin();
    int i = 1;
    int total = 0;
    while(itr != ListUser.end()){
        if(Petani* p = dynamic_cast<Petani*>(itr->second)){
            double pajak = p->pungutpajak();
            total += pajak;
            cout << "  " << i << ". " << p->getNama() << " - Petani : " << pajak << " gulden" << endl;
        }

        if(Peternak* p = dynamic_cast<Peternak*>(itr->second)){
            double pajak = p->pungutpajak();
            total += pajak;
            cout << "  " << i << ". " << p->getNama() << " - Peternak : " << pajak << " gulden" << endl;
        }

        itr++;
        i++;
    }

    uang += total;
    cout << "Negara mendapatkan pemasukan sebesar " << total << " gulden." << endl;
    cout << "Gunakan dengan baik dan jangan dikorupsi ya!" << endl;
}

int Walikota::findMaterial(const string& materialName, int neededQuantity) {
    int foundQuantity = 0;
    for (int i = 0; i < penyimpanan.getRows(); ++i) {
        for (int j = 0; j < penyimpanan.getCols(); ++j) {
            if (penyimpanan(i,j)!=nullptr && penyimpanan(i,j)->getNama() == materialName) {
                foundQuantity++;
                if (foundQuantity == neededQuantity) {
                    return foundQuantity;
                }
            }
        }
    }
    return foundQuantity;
}

void Walikota::tambahBangunan() {
    // Mencetak daftar resep bangunan yang tersedia
    cout << endl;
    cout << "Resep bangunan yang ada adalah sebagai berikut:" << endl;
    Building::printListBuilding();


    // Meminta input nama bangunan yang ingin dibangun
    string namaBangunan;
    cout << "Bangunan yang ingin dibangun: ";
    cin >> namaBangunan;

    // Mengecek apakah nama bangunan ada dalam daftar resep bangunan
    auto buildingIterator = Building::getlistBuilding().find(namaBangunan);
    if (buildingIterator == Building::getlistBuilding().end()) {
        throw TidakAdaResep();
    }

    // Mengambil resep bangunan
    Building* building = buildingIterator->second;
    map<string, int> recipe = building->getRecipe();

    // Mengecek apakah inventori Walikota cukup untuk membangun bangunan
    bool cukupBahan = true;
    for (const auto& material : recipe) {
        int neededQuantity = material.second;
        int foundQuantity = findMaterial(material.first, neededQuantity);
        if (foundQuantity < neededQuantity) {
            cukupBahan = false;
            break;
        }
    }

    if (!cukupBahan) {
        cout << "Kamu tidak punya sumber daya yang cukup untuk membangun bangunan tersebut! Masih memerlukan ";
        int materialCount = 0; 
        for (const auto& material : recipe) {
            int neededQuantity = material.second;
            int foundQuantity = findMaterial(material.first, neededQuantity);
            int sisa = max(0, neededQuantity - foundQuantity);
            cout << sisa << " " << material.first;
            materialCount++; 
            if (materialCount < recipe.size()) {
                cout << ", "; 
            } else {
                cout << "!"; 
            }
        }
        cout << endl;
    } else{
        // Mengurangi bahan yang digunakan dari inventaris Walikota
        for (const auto& material : recipe) {
            int neededQuantity = material.second;
            int foundQuantity = findMaterial(material.first, neededQuantity);
            for (int i = 0; i < penyimpanan.getRows(); ++i) {
                for (int j = 0; j < penyimpanan.getCols(); ++j) {
                    if (penyimpanan(i,j)!=nullptr && penyimpanan(i,j)->getNama() == material.first) {
                        penyimpanan(i,j) = nullptr;
                        neededQuantity--;
                        if (neededQuantity == 0) {
                            break;
                        }
                    }
                }
                if (neededQuantity == 0) {
                    break;
                }
            }
        }

        // Memasukkan bangunan yang berhasil dibangun ke penyimpanan Walikota
        penyimpanan+building;

        cout << namaBangunan << " berhasil dibangun dan telah menjadi hak milik walikota!" << endl;
    }

    
}

User* Walikota:: tambahPemain(map<string,User*> ListUser,pair<int,int> inventorySize,pair<int,int> fieldSize,pair<int,int> farmSize){
    Petani *p = new Petani("Dummy", inventorySize, fieldSize);
    if(uang < 50){
        throw UangTidakCukup();
    }
    cout << "Masukkan jenis pemain (huruf kecil) : ";
    string jenis;
    cin >> jenis;
    cout << "Masukkan nama pemain : ";
    string nama;
    cin >> nama;

    if (ListUser[nama] != nullptr){
        throw NamaSudahDipakai();
    }
    
    if(jenis == "walikota"){
        throw WalikotaHanyaSatu();
    }
    else if(jenis == "petani"){
        delete p;
        Petani *p = new Petani(nama, inventorySize, fieldSize);
    }
    else if(jenis == "peternak"){
        delete p;
        Peternak *p = new Peternak(nama, inventorySize, farmSize);
    }
    uang -= 50;
    return p;
}

double Walikota :: pungutpajak(){
    return 0;
}



Petani::Petani(std::string username, pair<int,int> invSize, pair<int,int> fieldSize): ladang(fieldSize.first,fieldSize.second), User(username, invSize){};
Petani::Petani(std::string nama,int berat,int uang,pair<int,int> inventorySize,pair<int,int> fieldSize): User(username, berat, uang, inventorySize), ladang(fieldSize.first, fieldSize.second){};
void Petani::setLadang(int i, int j, Tanaman* t){
    if (i>=ladang.getRows() || j>ladang.getCols() || i<0 || j<0){
        throw BarisKolomTidakSesuai();
    }
    ladang.incNeff();
    delete ladang(i,j);
    ladang(i,j) = t;
}
void Petani::tanamTanaman(){
    try{
        if (ladang.isFull()){
            throw LadangFull();
        }
        if(penyimpanan.isEmpty()){
            throw PenyimpananKosong();
        }
        std::string slot;
        std::string subslot;
        Tanaman* temp;
        while (true){
            try{
                cout << "Pilih Tanaman Dari Penyimpanan \n";
                cetak_penyimpanan();

                cout << "Slot: ";
                cin >> slot;
                subslot = slot.substr(1,3);
                int y = slot[0] - 'A';
                int x = stoi(subslot)-1;

                if (x>penyimpanan.getRows()-1 || y>penyimpanan.getCols()-1 || x<0 || y<0){
                    throw BarisKolomTidakSesuai();
                }
                else{
                    if (penyimpanan(x,y)){
                        if (dynamic_cast<Tanaman*>(penyimpanan(x,y))){
                            temp = static_cast<Tanaman*>(penyimpanan(x,y));
                            penyimpanan(x,y)=nullptr;
                            penyimpanan.decNeff();
                            break;
                        }
                        else{
                            throw BukanTanaman();
                        }
                    }
                    else{
                        throw SlotKosong();
                    }
                }
            }catch (UserException& e){
                for (int i = 0; i < e.what().length(); ++i) {
                print_red(e.what()[i]);
            }
            cout << "\n";
            }catch (InventoryException& e){
                for (int i = 0; i < e.what().length(); ++i) {
                    print_red(e.what()[i]);
                }
            cout << "\n";
            }
        }
        while (true){
            try{
                cout << "\n\nPilih Pilih petak tanah yang akan ditanami \n";
                cetakLadang();

                cout << "Slot: ";
                cin >> slot;
                subslot = slot.substr(1,3);
                int y = slot[0] - 'A';
                int x = stoi(subslot)-1;
                if (x>penyimpanan.getRows()-1 || y>penyimpanan.getCols()-1 || x<0 || y<0){
                    throw BarisKolomTidakSesuai();
                }
                else{
                    if (!ladang(x,y)){
                        ladang.addItem(temp,x,y);
                        break;
                    }
                    else{
                        throw SlotTerisi();
                    }
                }
            }catch (UserException& e){
                for (int i = 0; i < e.what().length(); ++i) {
                    print_red(e.what()[i]);
                }
                cout << "\n";
            }catch (InventoryException& e){
                for (int i = 0; i < e.what().length(); ++i) {
                    print_red(e.what()[i]);
                }
                cout << "\n";
            }
        }
    }catch (UserException& e){
        for (int i = 0; i < e.what().length(); ++i) {
        print_red(e.what()[i]);cout << "\n";
        }
    }
}

double Petani::pungutpajak(){
    KTKP = 13;
    int KKP = getNetoKekayaan()-KTKP;
    double percent;

    if (KKP <= 6){
        percent = 0.05;
    }
    if (KKP > 6 && KKP <= 25){
        percent = 0.15;
    }
    if (KKP > 25 && KKP <= 50){
        percent = 0.25;
    }
    if (KKP > 50 && KKP <= 500){
        percent = 0.3;
    }
    else{
        percent = 0.35;
    } 
    int pajak = round(KKP * percent);

    if (KKP <= 0){
        return 0.0;
    }
    if (pajak >= getUang()){
        return getUang();
        uang = 0;
    }
    else{
        uang -= pajak;
        return pajak;
    }
}


int Petani::getNetoKekayaan(){
    // periksa berapa nilai aset di penyimpanan
    int total = 0;
    for (int i = 0; i < penyimpanan.getRows(); i++){
        for (int j = 0; j < penyimpanan.getCols(); j++){
            if (penyimpanan(i,j) != nullptr){
                total += penyimpanan(i,j)->getPriceItem();
            }
        }
    }

    //periksa berapa nilai aset di ladang
    for (int i = 0; i < ladang.getRows(); i++){
        for (int j = 0; j < ladang.getCols(); j++){
            if (ladang(i,j) != nullptr){
                total += ladang(i,j)->getPriceItem();
            }
        }
    }

    //periksa berapa nilai uang
    total += getUang();

    return total;
}

Inventory<Tanaman*>& Petani::getladang(){
    return ladang;
}

Inventory<Hewan*>& Peternak::getfarm(){
    return peternakan;
}

Tanaman* Petani::getTanaman(int i, int j){
    if(ladang.isEmpty()){
        throw LadangEmpty();
    }
    if (i>ladang.getRows()-1 || j>ladang.getCols()-1 || i<0 || j<0){
        throw BarisKolomTidakSesuai();
    }
    if(ladang(i,j)!=nullptr){
        return ladang(i,j);
    }
    cout << "Tanaman tidak ada di ladang!\n";
    return nullptr;
}

void Petani::panen(){
    cetakLadang();
    map<std::string, int> ListSiapPanen;
    int jumlahSiapPanen, noTanaman, JumlahPetak;
    jumlahSiapPanen=0;
    for(int i = 0; i<ladang.getRows(); i++){
        for(int j = 0; j<ladang.getCols(); j++){
            if(ladang(i,j)!=nullptr && ladang(i,j)->siapPanen()){
                ListSiapPanen[ladang(i,j)->getKode()]+=1;
                jumlahSiapPanen++;
            }
        }
    }
    try{
        if(jumlahSiapPanen==0){
            throw TanamanBelumSiapPanen();
        }

        cout << "Pilih tanaman siap panen yang kamu miliki \n";
        int size = ListSiapPanen.size();

        for (int i = 0; i < size; ++i) {
            auto it = ListSiapPanen.begin();
            std::advance(it, i); // Move iterator
            cout << "\t" << i+1 << ". " << it->first << " (" << it->second << " petak siap panen)\n";
        }

        noTanaman = -1;
        JumlahPetak = -1;
        
        while (noTanaman<1 || noTanaman>size)
        {
            cout << "Nomor tanaman yang ingin dipanen: ";
            cin >> noTanaman;
            if(noTanaman<1 || noTanaman>size){
                cout << "\nTidak ada Tanaman dengan nomor tersebut, masukkan nomor yang lain!\n";
            }
        }
        auto it = ListSiapPanen.begin();
        advance(it, noTanaman-1);
        
        while (JumlahPetak<1 || JumlahPetak>it->second)
        {
            cout << "Berapa petak yang ingin dipanen: ";
            cin >> JumlahPetak;
            if(JumlahPetak<1 || JumlahPetak>it->second){
                cout << "\nPetak tidak cukup\n";
            }
        }
        if(JumlahPetak>sisaPenyimpanan()){
            throw PenyimpananTidakCukup();
        }
        cout << "\nPilih petak yang ingin dipanen\n";
        // ostream& printPetak;
        vector<string> ListPetak;
        for(int i=0; i<JumlahPetak; i++){
            std::string petak;
            cout << "Petak ke-" << i+1 << ": ";
            cin >> petak;
            int col = int(petak[0]-'A');
            int row = (petak[1]-'0')*10 + (petak[2]-'0')-1;
            while (ladang(row,col) == nullptr || ladang(row,col)->getKode()!=it->first)
            {
                cout << "Tidak ada " << it->first << " di petak tersebut!\n";
                cout << "Petak ke-" << i+1 << ": ";
                cin >> petak;
                col = int(petak[0]-'A');
                row = (petak[1]-'0')*10 + (petak[2]-'0')-1;
            }
            ListPetak.push_back(petak);
            
            cout << row << " " << col << endl;
            Tanaman* t = getTanaman(row,col);
            Product *p = t->Panen();
            penyimpanan+p;
            ladang.deleteItem(t);
        }
        cout << JumlahPetak << " petak Tanaman " << it->first << " pada petak";
        int sizePetak = ListPetak.size();
        for(int i=0; i<sizePetak; i++){
            cout << " " << ListPetak[i];
            if(i<sizePetak-1){
                cout << ",";
            }
        }
        cout << " telah dipanen!\n";
        cetak_penyimpanan();
        cetakLadang();

        
    }catch(UserException& e){
        for (int i = 0; i < e.what().length(); ++i) {
            print_red(e.what()[i]);
        }
    }catch(InventoryException& e){
        for (int i = 0; i < e.what().length(); ++i) {
            print_red(e.what()[i]);
        }
    }
}
void Petani::cetakLadang(){
    vector<Tanaman*> printed(0);
    int length1 = (7 + (ladang.getCols()-1)*6)/2 - 5;
    int i,j,k;
    bool flag = false;
    cout << "     ";
    for (i=0;i<length1;i++){
        cout << '=';
    }
    cout << "[ Ladang ]";
    if (ladang.getCols()%2!=0){
        length1++;
    }
    for (i=0;i<length1;i++){
        cout << '=';
    }
    cout << '\n';
    cout << "        ";
    for(i=0; i<ladang.getCols(); i++){
        cout << char('A'+i) << "     ";
    }
    cout << endl;
    for (i = 0; i < ladang.getRows(); ++i) {
        cout << "     ";
        for (j = 0; j < ladang.getCols(); ++j) {
            cout << "+-----";
        }
        cout << "+" << endl;
        cout << "  " << setw(2) << setfill(' ') << i+1;
        for (j = 0; j < ladang.getCols(); ++j) {
            cout << " | ";
            if (ladang(i,j)){
                for (k=0;k<printed.size();k++){
                    if(ladang(i,j)->getKode() == printed[k]->getKode()){
                        flag = true;
                    }
                }
                
                if (!flag){
                    printed.push_back(ladang(i,j));
                }
                flag=false;
                if (ladang(i,j)->siapPanen()){
                    for (k=0;k<3;k++){
                        print_green(ladang(i,j)->getKode()[k]);
                    }
                }
                else{
                    for (k=0;k<3;k++){
                        print_red(ladang(i,j)->getKode()[k]);
                    }
                }
            }
            else{
                cout << "   ";
            }
        }
        cout << " |" << endl;
    }
    cout << "     ";
    for (int j = 0; j < ladang.getCols(); ++j) {
        cout << "+-----";
    }
    cout << "+\n\n";

    for(i=0;i<printed.size();i++){
        cout << "- " << printed[i]->getKode() << ": " << printed[i]->getNama() << '\n';
    }
}

void Petani :: tambahUmurTanaman(){
    for (int i = 0; i < ladang.getRows(); ++i){
        for (int j = 0; j < ladang.getCols(); ++j){
            if(ladang(i,j)){
                ladang(i, j)->tambahUmurTanaman();
            }
        }
    }
}

Peternak::Peternak(std::string nama, pair<int,int> invSize, pair<int,int> farmSize) : peternakan(farmSize.first,farmSize.second), User(nama, invSize){}
Peternak::Peternak(std::string nama,int berat,int uang,pair<int,int> inventorySize,pair<int,int> farmSize): User(username, berat, uang, inventorySize), peternakan(farmSize.first, farmSize.second){};
void Peternak::setPeternakan(int i, int j, Hewan* t){
    if (i>=peternakan.getRows() || j>peternakan.getCols() || i<0 || j<0){
        // Throw Exception
    }
    peternakan.incNeff();
    delete peternakan(i,j);
    peternakan(i,j) = t;
    //setBerat(0) hewan;  
    t -> setBerat(0);
}
void Peternak::cetakPeternakan(){
    vector<Hewan*> printed(0);
    int length1 = (7 + (peternakan.getCols()-1)*6)/2 - 7;
    int i,j,k;
    bool flag = false;
    cout << "     ";
    for (i=0;i<length1;i++){
        cout << '=';
    }
    cout << "[ Peternakan ]";
    if (peternakan.getCols()%2!=0){
        length1++;
    }
    for (i=0;i<length1;i++){
        cout << '=';
    }
    cout << '\n';
    cout << "        ";
    for(i=0; i<peternakan.getCols(); i++){
        cout << char('A'+i) << "     ";
    }
    cout << endl;
    for (i = 0; i < peternakan.getRows(); ++i) {
        cout << "     ";
        for (j = 0; j < peternakan.getCols(); ++j) {
            cout << "+-----";
        }
        cout << "+" << endl;
        cout << "  " << setw(2) << setfill(' ') << i+1;
        for (j = 0; j < peternakan.getCols(); ++j) {
            cout << " | ";
            if (peternakan(i,j)){
                for (k=0;k<printed.size();k++){
                    if(peternakan(i,j)->getKode() == printed[k]->getKode()){
                        flag = true;
                    }
                }
                
                if (!flag){
                    printed.push_back(peternakan(i,j));
                }
                flag=false;
                if (peternakan(i,j)->siapPanen()){
                    for (k=0;k<3;k++){
                        print_green(peternakan(i,j)->getKode()[k]);
                    }
                }
                else{
                    for (k=0;k<3;k++){
                        print_red(peternakan(i,j)->getKode()[k]);
                    }
                }
            }
            else{
                cout << "   ";
            }
        }
        cout << " |" << endl;
    }
    cout << "     ";
    for (int j = 0; j < peternakan.getCols(); ++j) {
        cout << "+-----";
    }
    cout << "+\n\n";

    for(i=0;i<printed.size();i++){
        cout << "- " << printed[i]->getKode() << ": " << printed[i]->getNama() << '\n';
    }
}

Hewan* Peternak::getHewan(int i, int j){
    if(peternakan.isEmpty()){
        throw LadangEmpty();
    }
    if (i>peternakan.getRows()-1 || j>peternakan.getCols()-1 || i<0 || j<0){
        throw BarisKolomTidakSesuai();
    }
    if(peternakan(i,j)!=nullptr){
        return peternakan(i,j);
    }
    cout << "Hewan tidak ada di peternakan!\n";
    return nullptr;
}
void Peternak::ternak(){
    try{
        if (peternakan.isFull()){
            throw PeternakanFull();
        }
        if(penyimpanan.isEmpty()){
            throw PenyimpananKosong();
        }
        std::string slot;
        std::string subslot;
        Hewan* temp;
        while (true){
            try{
                cout << "Pilih Hewan Dari Penyimpanan \n";
                cetak_penyimpanan();

                cout << "Slot: ";
                cin >> slot;
                subslot = slot.substr(1,3);
                int y = slot[0] - 'A';
                int x = stoi(subslot)-1;

            if (x>penyimpanan.getRows()-1 || y>penyimpanan.getCols()-1 || x<0 || y<0){
                throw BarisKolomTidakSesuai();
            }
            else{
                if (penyimpanan(x,y)){
                    if (dynamic_cast<Hewan*>(penyimpanan(x,y))){
                        temp = static_cast<Hewan*>(penyimpanan(x,y));
                        penyimpanan(x,y)=nullptr;
                        penyimpanan.decNeff();
                        break;
                    }
                    else{
                        throw BukanHewan();
                    }
                }
                else{
                    throw SlotKosong();
                }
            }
        }catch (UserException& e){
            for (int i = 0; i < e.what().length(); ++i) {
                print_red(e.what()[i]);
            }
        }catch (InventoryException& e){
            for (int i = 0; i < e.what().length(); ++i) {
                print_red(e.what()[i]);
            }
            cout << "\n";
        }
    }
    while (true){
        try{
            cout << "\n\nPilih petak tanah yang akan menjadi lokasi ternak \n";
            cetakPeternakan();

                cout << "Slot: ";
                cin >> slot;
                subslot = slot.substr(1,3);
                int y = slot[0] - 'A';
                int x = stoi(subslot)-1;

                if (x>peternakan.getRows()-1 || y>peternakan.getCols()-1 || x<0 || y<0){
                    throw BarisKolomTidakSesuai();
                }
                else{
                    if (!peternakan(x,y)){
                        peternakan.addItem(temp,x,y);
                        break;
                    }
                    else{
                        throw SlotTerisi();
                    }
                }
            }catch (UserException& e){
                for (int i = 0; i < e.what().length(); ++i) {
                    print_red(e.what()[i]);
                }
                cout << "\n";
            }catch(InventoryException& e){
                for (int i = 0; i < e.what().length(); ++i) {
                    print_red(e.what()[i]);
                }
                cout << "\n";
            }
        }
    }catch (UserException& e){
        for (int i = 0; i < e.what().length(); ++i) {
            print_red(e.what()[i]);
        }
        cout << "\n";
    }
}
void Peternak::panen(){
    cetakPeternakan();
    map<std::string, int> ListSiapPanen;
    int jumlahSiapPanen, noHewan, JumlahPetak;
    jumlahSiapPanen=0;
    for(int i = 0; i<peternakan.getRows(); i++){
        for(int j = 0; j<peternakan.getCols(); j++){
            if(peternakan(i,j)!=nullptr && peternakan(i,j)->siapPanen()){
                ListSiapPanen[peternakan(i,j)->getKode()]+=1;
                jumlahSiapPanen++;
            }
        }
    }
    try{
        if(jumlahSiapPanen==0){
            throw HewanBelumSiapPanen();
        }

        cout << "Pilih Hewan siap panen yang kamu miliki \n";
        int size = ListSiapPanen.size();

        for (int i = 0; i < size; ++i) {
            auto it = ListSiapPanen.begin();
            std::advance(it, i); // Move iterator
            cout << "\t" << i+1 << ". " << it->first << " (" << it->second << " petak siap panen)\n";
        }

        noHewan = -1;
        JumlahPetak = -1;
        
        while (noHewan<1 || noHewan>size)
        {
            cout << "Nomor tanaman yang ingin dipanen: ";
            cin >> noHewan;
            if(noHewan<1 || noHewan>size){
                cout << "\nTidak ada Tanaman dengan nomor tersebut, masukkan nomor yang lain!\n";
            }
        }
        auto it = ListSiapPanen.begin();
        advance(it, noHewan-1);
        
        while (JumlahPetak<1 || JumlahPetak>it->second)
        {
            cout << "Berapa petak yang ingin dipanen: ";
            cin >> JumlahPetak;
            if(JumlahPetak<1 || JumlahPetak>it->second){
                cout << "\nPetak tidak cukup\n";
            }
        }
        //Ayam dan bebek akan menghasilkan 2 produk, sementara hewan lain
        //hanya menghasilkan 1 produk saja
        if(it->first=="CHK" || it->first=="DCK"){
            if(JumlahPetak*2>sisaPenyimpanan()){
                throw PenyimpananTidakCukup();
            }else{
                if(JumlahPetak>sisaPenyimpanan()){
                    throw PenyimpananTidakCukup();
                }
            }
        }
        cout << "\nPilih petak yang ingin dipanen\n";
        // ostream& printPetak;
        vector<string> ListPetak;
        for(int i=0; i<JumlahPetak; i++){
            std::string petak;
            cout << "Petak ke-" << i+1 << ": ";
            cin >> petak;
            int col = int(petak[0]-'A');
            int row = (petak[1]-'0')*10 + (petak[2]-'0')-1;
            cout << row << " " << col << "\n";
            while (peternakan(row,col) == nullptr || peternakan(row,col)->getKode()!=it->first)
            {
                cout << "Tidak ada " << it->first << " di petak tersebut!\n";
                cout << "Petak ke-" << i+1 << ": ";
                cin >> petak;
                col = int(petak[0]-'A');
                row = (petak[1]-'0')*10 + (petak[2]-'0')-1;
            }
            ListPetak.push_back(petak);
            Hewan* t = getHewan(row,col);
            vector<Product*> p = t->Panen();
            int size = p.size();
            for(int i=0; i<size; i++){
                penyimpanan+p[i];
            }
            // setPenyimpanan(p);
            peternakan.deleteItem(t);
            // printPetak << petak << " ";
        }
        cout << JumlahPetak << " petak Tanaman " << it->first << " pada petak";
        int sizePetak = ListPetak.size();
        for(int i=0; i<sizePetak; i++){
            cout << " " << ListPetak[i];
            if(i<sizePetak-1){
                cout << ",";
            }
        }
        cout << " telah dipanen!\n";
        cetak_penyimpanan();
        cetakPeternakan();

        
    }catch(UserException& e){
        for (int i = 0; i < e.what().length(); ++i) {
            print_red(e.what()[i]);
        }
    }catch(InventoryException& e){
        for (int i = 0; i < e.what().length(); ++i) {
            print_red(e.what()[i]);
        }
    }
}

//pilih satu hewan di peternakan, lalu hewan tersebut bila karnivora hanya bisa makan Meat yang ada di penyimpanan
void Peternak::kasihMakan()
{
    cout << endl  << endl << " di bawah ini adalah command kasihMakan() "<< endl;
    string tipe;
    int x, y;
    std::string slot;
    std::string subslot;

    try
    {
        if (penyimpanan.isEmpty())
        {
            throw PenyimpananKosong();
        }
        if (peternakan.isEmpty())
        {
            throw PeternakanKosong();
        }
        else
        {
            cetakPeternakan();
            cout << "Pilih hewan di peternakan yang ingin diberi makan: ";
            while (true)
            {
                cout << "\nSlot: ";
                cin >> slot;
                subslot = slot.substr(1, 2);
                x = stoi(subslot) - 1;
                y = slot[0] - 'A';
                    try
                    {

                        if (x >= peternakan.getRows() || y >= peternakan.getCols() || x < 0 || y < 0)
                        {
                            throw BarisKolomTidakSesuai();
                        }

                        if (peternakan(x, y) == nullptr)
                        {
                            throw BukanHewan();
                        }
                        if (peternakan(x, y)->siapPanen())
                        {
                            throw HewanSudahSiapPanen();
                        }
                        else
                        {
                            string tipeId = typeid(*peternakan(x, y)).name();
                            tipe = tipeId.substr(1);
                            cout << "Anda memilih " << tipe << " untuk makan " << endl;
                            Hewan* h = peternakan(x,y);
                            break;
                        }
                    } catch (PeternakanKosong &e){
                        for (int i = 0; i < e.what().length(); ++i) {
                            print_red(e.what()[i]);
                        }
                        return;
                    } catch (BarisKolomTidakSesuai &e) {
                        for (int i = 0; i < e.what().length(); ++i) {
                            print_red(e.what()[i]);
                        }
                    } catch (BukanHewan &e) {
                        for (int i = 0; i < e.what().length(); ++i) {
                            print_red(e.what()[i]);
                        }
                    } catch (HewanSudahSiapPanen &e) {
                        for (int i = 0; i < e.what().length(); ++i) {
                            print_red(e.what()[i]);
                        }
                    } catch (PenyimpananKosong &e) {
                        for (int i = 0; i < e.what().length(); ++i) {
                            print_red(e.what()[i]);
                        }
                        return;
                    } catch (exception& e) {
                        cout << "Kesalahan di luar ketentuan: " << e.what() << endl;
                    }
            }

            cetak_penyimpanan();
            while (true) 
            {
                cout << "\nSlot: ";
                cin >> slot;
                subslot = slot.substr(1, 2);
                int i = stoi(subslot) - 1;
                int j = slot[0] - 'A';


                try
                {
                    // Melakukan penanganan exception
                    if (i >= penyimpanan.getRows() || j >= penyimpanan.getCols() || i < 0 || j < 0)
                    {
                        throw BarisKolomTidakSesuai();
                    }

                    if (penyimpanan(i, j) == nullptr)
                    {
                        throw HarapanKosong();
                    }

                    else
                    {
                        // Menambah berat badan jika item di slot adalah makanan
                        InvItems* item = penyimpanan(i, j);
                        string tipeIdItem = typeid(*item).name();
                        string tipeItem = tipeIdItem.substr(1);
                        cout << "Anda memilih " << tipeItem << " untuk diberikan kepada " << tipe << endl;


                        if(tipe == "Carnivore" && tipeItem != "Meat"){
                            throw MakananTidakCocokException();
                        } 
                        if(tipe == "Herbivore" && tipeItem != "Fruit"){ 
                            throw MakananTidakCocokException();
                        }
                        if(tipe == "Omnivore" && !(tipeItem == "Meat" || tipeItem == "Fruit")){
                            throw MakananTidakCocokException();
                        } else{
                            Product* productItem = dynamic_cast<Product*>(item);
                            if (productItem != nullptr) {
                                // Memanggil metode getAddedWeight() dari objek yang telah di-downcast
                                getHewan(x, y)->tambahBerat(productItem->getAddedWeight());
                                cout << "Dengan lahapnya, hewan ternak kamu memakan hidangan itu." << endl;
                                cout << "Alhasil, berat hewan ini naik menjadi " <<  getHewan(x, y) -> getBerat() << endl;
                                penyimpanan(i,j) = nullptr;
                                penyimpanan.decNeff();
                                break;
                            }
                        }
                    }
                } catch (BarisKolomTidakSesuai &e) {
                    for (int i = 0; i < e.what().length(); ++i) {
                        print_red(e.what()[i]);
                    }
                } catch (HarapanKosong &e) {
                    for (int i = 0; i < e.what().length(); ++i) {
                        print_red(e.what()[i]);
                    }
                } catch (MakananTidakCocokException &e) {
                    for (int i = 0; i < e.what().length(); ++i) {
                        print_red(e.what()[i]);
                    }
                } catch (exception& e) {
                    cout << "Kesalahan di luar ketentuan: " << e.what() << endl;
                }
            }
        }
    }

    catch (PenyimpananKosong &e)
    {
        for (int i = 0; i < e.what().length(); ++i) {
            print_red(e.what()[i]);
        }
    }
    catch (PeternakanKosong &e)
    {
        for (int i = 0; i < e.what().length(); ++i) {
            print_red(e.what()[i]);
        }
    }
    catch (exception &e)
    {
        cout << "Kesalahan di luar ketentuan: " << e.what() << endl;
    }
}

int Peternak::getNetoKekayaan(){
    // periksa berapa nilai aset di penyimpanan
    int total = 0;
    for (int i = 0; i < penyimpanan.getRows(); i++){
        for (int j = 0; j < penyimpanan.getCols(); j++){
            if (penyimpanan(i,j) != nullptr){
                total += penyimpanan(i,j)->getPriceItem();
            }
        }
    }

    //periksa berapa nilai aset di ladang
    for (int i = 0; i < peternakan.getRows(); i++){
        for (int j = 0; j < peternakan.getCols(); j++){
            if (peternakan(i,j) != nullptr){
                total += peternakan(i,j)->getPriceItem();
            }
        }
    }

    //periksa berapa nilai uang
    total += getUang();

    return total;
}

double Peternak::pungutpajak(){
    KTKP = 11;
    int KKP = getNetoKekayaan()-KTKP;
    double percent;

    if (KKP <= 6){
        percent = 0.05;
    }
    if (KKP > 6 && KKP <= 25){
        percent = 0.15;
    }
    if (KKP > 25 && KKP <= 50){
        percent = 0.25;
    }
    if (KKP > 50 && KKP <= 500){
        percent = 0.3;
    }
    else{
        percent = 0.35;
    } 
    int pajak = round(KKP * percent);
    if (KKP <= 0){
        return 0.0;
    }
    if (pajak >= getUang()){
        return getUang();
        uang = 0;
    }
    else{
        uang -= pajak;
        return pajak;
    }
}