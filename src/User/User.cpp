#include "User.hpp"


User::User(string username, pair<int,int> invSize): penyimpanan(invSize.first, invSize.second){
    this->username = username;
    berat_badan = 40;
    uang = 50;
    // n_player++;
    // id = n_player;
}

User::~User(){}

int User::getBerat(){
    return berat_badan;
}
Inventory<InvItems*> *User::getInv(){
    return &  penyimpanan;
}
int User::getUang(){
    return uang;
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
    cout << "+" << endl;
}
void User::setPenyimpanan(int i, int j, InvItems* item){
    if (i>=penyimpanan.getRows() || j>penyimpanan.getCols() || i<0 || j<0){
        // Throw Exception
    }
    delete penyimpanan(i,j);
    penyimpanan(i,j) = item;
}
void User::makan() {
    cetak_penyimpanan();
    string slot;
    string subslot;
    while(true){
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
            if (item->isMakanan()) {
                // Downcast objek item ke kelas Product
                Product* productItem = dynamic_cast<Product*>(item);
                if (productItem != nullptr) {
                    // Memanggil metode getAddedWeight() dari objek yang telah di-downcast
                    berat_badan += productItem->getAddedWeight();
                    cout << "Dengan lahapnya, kamu memakan hidangan itu." << endl;
                    cout << "Alhasil, berat badan kamu naik menjadi " << berat_badan << endl;
                    delete penyimpanan(i, j);
                    break;
                } 
            } else {
                throw BukanMakanan();
            }
        } catch (BarisKolomTidakSesuai &e) {
            cout << e.what() << endl;
        } catch (HarapanKosong &e) {
            cout << e.what() << endl;
        } catch (BukanMakanan &e) {
            cout << e.what() << endl;
        }
    }
};

void User::beli(){}
void User::jual(){}
 

int Walikota::jumlah_walikota = 0;
Walikota::Walikota(string username, pair<int, int> invSize) : User(username, invSize){
    if(jumlah_walikota!=0){
        throw WalikotaHanyaSatu();
    }
    jumlah_walikota++;
}
Walikota::~Walikota(){}
void Walikota::tagihPajak(){}
void Walikota::tambahBangunan(){}
void Walikota::tambahPemain(){}



// Petani::Petani() :ladang(5,5){};
// void Petani::setLadang(int i, int j, Tanaman* t){
//     if (i>=ladang.getRows() || j>ladang.getCols() || i<0 || j<0){
//         // Throw Exception
//     }
//     delete ladang(i,j);
//     ladang(i,j) = t;
// }
// void Petani::tanamTanaman(){
//     if (ladang.isFull()){
//         //throw exception
//     }
//     if(penyimpanan.isEmpty()){
//         //throw exception
//     }
//     string slot;
//     string subslot;
//     Tanaman* temp;
//     while (true){
//         cout << "Pilih Tanaman Dari Penyimpanan \n";
//         cetak_penyimpanan();

//         cout << "Slot: ";
//         cin >> slot;
//         subslot = slot.substr(1,3);
//         int y = slot[0] - 'A';
//         int x = stoi(subslot)-1;

//         if (x>penyimpanan.getRows()-1 || y>penyimpanan.getCols()-1){
//             //throw exception;
//         }
//         else{
//             temp = static_cast<Tanaman*>(penyimpanan(x,y));
//             penyimpanan(x,y)=nullptr;
//             break;
//         }
//     }
//     while (true){
//         cout << "\n\nPilih Pilih petak tanah yang akan ditanami \n";
//         cetakLadang();

//         cout << "Slot: ";
//         cin >> slot;
//         subslot = slot.substr(1,3);
//         int y = slot[0] - 'A';
//         int x = stoi(subslot)-1;
//         if (x>ladang.getRows()-1 || y>ladang.getCols()-1){
//             //throw exception;
//         }
//         else{
            
//             setLadang(x,y,temp);
//             break;
//         }
//     }
// }
// void Petani::panenTanaman(){
//     cetakLadang();
//     vector<Tanaman*> printed(0);
//     bool flag = false;
//     int i,j,k;
//     for (i=0;i<ladang.getRows();i++){
//         for (j=0;j<ladang.getCols();j++){
//             if(ladang(i,j)){
//                 for (k=0;k<printed.size();k++){
//                     if(ladang(i,j)->getKode() == printed[k]->getKode()){
//                         flag = true;
//                     }
//                 }
//             }
//         }
//     }
// }
// void Petani::cetakLadang(){
//     vector<Tanaman*> printed(0);
//     int length1 = (7 + (ladang.getCols()-1)*6)/2 - 5;
//     int i,j,k;
//     bool flag = false;
//     cout << "     ";
//     for (i=0;i<length1;i++){
//         cout << '=';
//     }
//     cout << "[ Ladang ]";
//     if (ladang.getCols()%2!=0){
//         length1++;
//     }
//     for (i=0;i<length1;i++){
//         cout << '=';
//     }
//     cout << '\n';
//     cout << "        ";
//     for(i=0; i<ladang.getCols(); i++){
//         cout << char('A'+i) << "     ";
//     }
//     cout << endl;
//     for (i = 0; i < ladang.getRows(); ++i) {
//         cout << "     ";
//         for (j = 0; j < ladang.getCols(); ++j) {
//             cout << "+-----";
//         }
//         cout << "+" << endl;
//         cout << "  " << setw(2) << setfill(' ') << i+1;
//         for (j = 0; j < ladang.getCols(); ++j) {
//             cout << " | ";
//             if (ladang(i,j)){
//                 for (k=0;k<printed.size();k++){
//                     if(ladang(i,j)->getKode() == printed[k]->getKode()){
//                         flag = true;
//                     }
//                 }
                
//                 if (!flag){
//                     printed.push_back(ladang(i,j));
//                 }
//                 flag=false;
//                 if (ladang(i,j)->siapPanen()){
//                     for (k=0;k<3;k++){
//                         print_green(ladang(i,j)->getKode()[k]);
//                     }
//                 }
//                 else{
//                     for (k=0;k<3;k++){
//                         print_red(ladang(i,j)->getKode()[k]);
//                     }
//                 }
//             }
//             else{
//                 cout << "   ";
//             }
//         }
//         cout << " |" << endl;
//     }
//     cout << "     ";
//     for (int j = 0; j < ladang.getCols(); ++j) {
//         cout << "+-----";
//     }
//     cout << "+\n\n";

//     for(i=0;i<printed.size();i++){
//         cout << "- " << printed[i]->getKode() << ": " << printed[i]->getNama() << '\n';
//     }
// }

// Peternak::Peternak() : peternakan(5,5){}
// void Peternak::setPeternakan(int i, int j, Hewan* t){
//     if (i>=peternakan.getRows() || j>peternakan.getCols() || i<0 || j<0){
//         // Throw Exception
//     }
//     delete peternakan(i,j);
//     peternakan(i,j) = t;
// }
// void Peternak::cetakPeternakan(){
//     vector<Hewan*> printed(0);
//     int length1 = (7 + (peternakan.getCols()-1)*6)/2 - 7;
//     int i,j,k;
//     bool flag = false;
//     cout << "     ";
//     for (i=0;i<length1;i++){
//         cout << '=';
//     }
//     cout << "[ Peternakan ]";
//     if (peternakan.getCols()%2!=0){
//         length1++;
//     }
//     for (i=0;i<length1;i++){
//         cout << '=';
//     }
//     cout << '\n';
//     cout << "        ";
//     for(i=0; i<peternakan.getCols(); i++){
//         cout << char('A'+i) << "     ";
//     }
//     cout << endl;
//     for (i = 0; i < peternakan.getRows(); ++i) {
//         cout << "     ";
//         for (j = 0; j < peternakan.getCols(); ++j) {
//             cout << "+-----";
//         }
//         cout << "+" << endl;
//         cout << "  " << setw(2) << setfill(' ') << i+1;
//         for (j = 0; j < peternakan.getCols(); ++j) {
//             cout << " | ";
//             if (peternakan(i,j)){
//                 for (k=0;k<printed.size();k++){
//                     if(peternakan(i,j)->getKode() == printed[k]->getKode()){
//                         flag = true;
//                     }
//                 }
                
//                 if (!flag){
//                     printed.push_back(peternakan(i,j));
//                 }
//                 flag=false;
//                 if (peternakan(i,j)->siapPanen()){
//                     for (k=0;k<3;k++){
//                         print_green(peternakan(i,j)->getKode()[k]);
//                     }
//                 }
//                 else{
//                     for (k=0;k<3;k++){
//                         print_red(peternakan(i,j)->getKode()[k]);
//                     }
//                 }
//             }
//             else{
//                 cout << "   ";
//             }
//         }
//         cout << " |" << endl;
//     }
//     cout << "     ";
//     for (int j = 0; j < peternakan.getCols(); ++j) {
//         cout << "+-----";
//     }
//     cout << "+\n\n";

//     for(i=0;i<printed.size();i++){
//         cout << "- " << printed[i]->getKode() << ": " << printed[i]->getNama() << '\n';
//     }
// }

// void Peternak::ternak(){
//     if (peternakan.isFull()){
//         //throw exception
//     }
//     if(penyimpanan.isEmpty()){
//         //throw exception
//     }
//     string slot;
//     string subslot;
//     Hewan* temp;
//     while (true){
//         cout << "Pilih Hewan Dari Penyimpanan \n";
//         cetak_penyimpanan();

//         cout << "Slot: ";
//         cin >> slot;
//         subslot = slot.substr(1,3);
//         int y = slot[0] - 'A';
//         int x = stoi(subslot)-1;

//         if (x>penyimpanan.getRows()-1 || y>penyimpanan.getCols()-1){
//             //throw exception;
//         }
//         else{
//             temp = static_cast<Hewan*>(penyimpanan(x,y));
//             penyimpanan(x,y)=nullptr;
//             break;
//         }
//     }
//     while (true){
//         cout << "\n\nPilih Pilih petak tanah yang akan ditanami \n";
//         cetakPeternakan();

//         cout << "Slot: ";
//         cin >> slot;
//         subslot = slot.substr(1,3);
//         int y = slot[0] - 'A';
//         int x = stoi(subslot)-1;

//         if (x>peternakan.getRows()-1 || y>peternakan.getCols()-1){
//             //throw exception;
//         }
//         else{
//             setPeternakan(x,y,temp);
//             break;
//         }
//     }
// }
// void panen();

