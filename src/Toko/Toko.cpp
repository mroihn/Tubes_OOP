#include "Toko.hpp"

Toko :: Toko(){
    Tanaman* t1 = new Material_Plant(1,"TTT","Teak Tree",5,4);
    this->addBarang(t1, 1, -1);
    Tanaman* t2 = new Material_Plant(1,"TTT","Sandalwood Tree",5,4);
    this->addBarang(t2, 1, -1);
    Tanaman* t3 = new Material_Plant(1,"TTT","Aloe Tree",5,4);
    this->addBarang(t3, 1, -1);
    Tanaman* t4 = new Material_Plant(1,"TTT","Ironwood Tree",5,4);
    this->addBarang(t4, 1, -1);
    Tanaman* t5 = new Fruit_Plant(1,"TTT","Apple Tree",5,4);
    this->addBarang(t5, 1, -1);
    Tanaman* t6 = new Fruit_Plant(1,"TTT","Orange Tree ",5,4);
    this->addBarang(t6, 1, -1);
    Tanaman* t7 = new Fruit_Plant(1,"TTT","Banana Tree",5,4);
    this->addBarang(t7, 1, -1);
    Tanaman* t8 = new Fruit_Plant(1,"TTT","Guava Tree",5,4);
    this->addBarang(t8, 1, -1);
    Hewan *h1 = new Herbivore(2, "HHH", "Cow", 7, 8);
    this->addBarang(h1, 1, -1);
    Hewan *h2 = new Herbivore(2, "HHH", "Sheep", 7, 8);
    this->addBarang(h2, 1, -1);
    Hewan *h3 = new Herbivore(2, "HHH", "Horse", 7, 8);
    this->addBarang(h3, 1, -1);
    Hewan *h4 = new Herbivore(2, "HHH", "Rabbit ", 7, 8);
    this->addBarang(h4, 1, -1);
    Hewan *h5 = new Carnivore(2, "HHH", "Snake", 7, 8);
    this->addBarang(h5, 1, -1);
    Hewan *h6 = new Omnivore(2, "HHH", "Chicken", 7, 8);
    this->addBarang(h6, 1, -1);
    Hewan *h7 = new Omnivore(2, "HHH", "Duck", 7, 8);
    this->addBarang(h7, 1, -1);
}

void Toko :: cetak_toko(){
    for (int i = 0; i < ListBarang.size(); i++)
    {
        string namaBarang = ListBarang[i]->getNama();
        int harga = ListHarga[namaBarang];
        int stok = ListStok[namaBarang];
        if(stok == -1){
            cout << i+1 << ". " << namaBarang << " - " << harga << endl;
        }
        else{
            cout << i+1 << ". " << namaBarang << " - " << harga << " (" << stok << ")" << endl;
        }
    }
}

void Toko :: addBarang(InvItems *item, int harga, int stok){
    ListBarang.push_back(item);
    string namaBarang = item->getNama();
    ListHarga[namaBarang] = harga;
    ListStok[namaBarang] += stok;
}

void Toko :: kurangiBarang(string namaBarang, int jumlah){
    if(ListStok[namaBarang] != -1){
        if(jumlah>ListStok[namaBarang]){
        cout << "gak cukup bos" << endl;
        }
        else if(jumlah == ListStok[namaBarang]){
            int idx = -1;
            for (int i = 0; i < ListBarang.size();i++){
                if(ListBarang[i]->getNama() == namaBarang){
                    idx = i;
                }
            }
            if(idx!=-1){
                ListBarang.erase(ListBarang.begin() + idx);
                ListHarga.erase(namaBarang);
                ListStok.erase(namaBarang);
            }
        }
        else{
            ListStok[namaBarang]-=jumlah;
        }
    }
    
}

void Toko :: beli(User* pembeli){
    cout << "Selamat datang di toko!!" << endl;
    cout << "Berikut merupakan hal yang dapat Anda Beli" << endl;
    this->cetak_toko();
    cout << "\n";
    cout << "Uang anda : " << pembeli->getUang() << endl;
    cout << "Sisa Penyimpanan : " << pembeli->sisaPenyimpanan() << endl;
    cout << "\n";
    cout << "Barang ingin dibeli : ";
    int pilihanBarang;
    cin >> pilihanBarang;
    bool cek = false;
    int kuantitas;
    while(!cek){
        cout << "kuantitas : ";
        cin >> kuantitas;
        if(kuantitas> pembeli->sisaPenyimpanan()){
            cout << "slot gak cukup" << endl;
        }
        else{
            cek = true;
        }
    }
    string namaBarang = ListBarang[pilihanBarang - 1]->getNama();
    int totalHarga = ListHarga[namaBarang] * kuantitas;
    if(pembeli->getUang() < totalHarga){
        cout << "Uang lu gak cukup bos" << endl;
    }
    else{
        pembeli->setUang(pembeli->getUang() - totalHarga);
        for (int i = 0; i < kuantitas;i++){
            pembeli->setPenyimpanan(ListBarang[pilihanBarang - 1]);
        }
        this->kurangiBarang(namaBarang, kuantitas);
        cout << "Selamat Anda berhasil membeli " << kuantitas << " " << namaBarang << ". Uang Anda tersisa " << pembeli->getUang() << " gulden." << endl;
    }
}

void Toko :: jual(User* penjual){
    cout << "\nBerikut merupakan penyimpanan Anda" << endl;
    penjual->cetak_penyimpanan();
    cout << "Silahkan pilih petak yang ingin Anda jual!" << endl;
    string petakPilihan;
    cin >> petakPilihan;
    cout << petakPilihan << endl;
}
