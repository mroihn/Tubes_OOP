#include "Toko.hpp"

Toko :: Toko(){
    Tanaman* t1 = new Material_Plant(1,"TTT","Teak Tree",5,4);
    this->addBarang(t1, -1);
    Tanaman* t2 = new Material_Plant(1,"TTT","Sandalwood Tree",5,4);
    this->addBarang(t2, -1);
    Tanaman* t3 = new Material_Plant(1,"TTT","Aloe Tree",5,4);
    this->addBarang(t3, -1);
    Tanaman* t4 = new Material_Plant(1,"TTT","Ironwood Tree",5,4);
    this->addBarang(t4, -1);
    Tanaman* t5 = new Fruit_Plant(1,"TTT","Apple Tree",5,4);
    this->addBarang(t5, -1);
    Tanaman* t6 = new Fruit_Plant(1,"TTT","Orange Tree ",5,4);
    this->addBarang(t6, -1);
    Tanaman* t7 = new Fruit_Plant(1,"TTT","Banana Tree",5,4);
    this->addBarang(t7, -1);
    Tanaman* t8 = new Fruit_Plant(1,"TTT","Guava Tree",5,4);
    this->addBarang(t8, -1);
    Hewan *h1 = new Herbivore(2, "HHH", "Cow", 7, 8);
    this->addBarang(h1, -1);
    Hewan *h2 = new Herbivore(2, "HHH", "Sheep", 7, 8);
    this->addBarang(h2, -1);
    Hewan *h3 = new Herbivore(2, "HHH", "Horse", 7, 8);
    this->addBarang(h3, -1);
    Hewan *h4 = new Herbivore(2, "HHH", "Rabbit ", 7, 8);
    this->addBarang(h4, -1);
    Hewan *h5 = new Carnivore(2, "HHH", "Snake", 7, 8);
    this->addBarang(h5, -1);
    Hewan *h6 = new Omnivore(2, "HHH", "Chicken", 7, 8);
    this->addBarang(h6, -1);
    Hewan *h7 = new Omnivore(2, "HHH", "Duck", 7, 8);
    this->addBarang(h7, -1);
}

int Toko::getJumlahJenisBarang(){
    int count=0;
    for(const auto& item : ListStok){
        if(item.second>0){
            count++;
        }
    }
    return count;
}

InvItems* Toko :: getBarang(int i){
    return ListBarang[i];
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

void Toko :: addBarang(InvItems *item, int stok){
    string namaBarang = item->getNama();
    if(!ListStok[namaBarang]){
        ListBarang.push_back(item);
        ListHarga[namaBarang] = item->getPriceItem();
        ListStok[namaBarang] += stok;
    }
    else{
        if(ListStok[namaBarang] != -1){
            ListStok[namaBarang] += stok;
        }
    }
}

void Toko :: kurangiBarang(string namaBarang, int jumlah){
    try{
        if(ListStok[namaBarang] != -1){
            if(jumlah>ListStok[namaBarang]){
                throw StokBarangKurang();
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
    }catch (TokoException& e){
        cout << e.what() << "\n";
    }
}

void Toko :: beli(User* pembeli){
    try{
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
        cout << "kuantitas : ";
        cin >> kuantitas;
        if(kuantitas> pembeli->sisaPenyimpanan()){
            throw SlotPembeliTidakCukup();
        }

        string namaBarang = ListBarang[pilihanBarang - 1]->getNama();
        if(kuantitas > ListStok[namaBarang] && ListStok[namaBarang] != -1){
            throw StokBarangKurang();
        }
        
        int totalHarga = ListHarga[namaBarang] * kuantitas;
        if(pembeli->getUang() < totalHarga){
            throw UangPembeliTidakCukup();
        }

        if(Walikota* p = dynamic_cast<Walikota*>(pembeli)){
            if(Building* b = dynamic_cast<Building*>(ListBarang[pilihanBarang - 1])){
                throw RoleBeliTidakSesuai();
            }
        }

        pembeli->beli(totalHarga);
        cout << "Pilih cara penyimpanan" << endl;
        cout << "1. Otomatis" << endl;
        cout << "2. Manual" << endl;
        int pilihan;
        cin >> pilihan;
        if(pilihan == 1){
            for (int i = 0; i < kuantitas;i++){
                this->kurangiBarang(namaBarang, 1);
                pembeli->setPenyimpanan(ListBarang[pilihanBarang - 1]);
            }
        }
        else if(pilihan == 2){
            for (int i = 0; i < kuantitas;i++){
                string petakPilihan;
                cout << "Petak slot ke-" << i+1 << " : ";
                cin >> petakPilihan;
                string subslot = petakPilihan.substr(1,3);
                int y = petakPilihan[0] - 'A';
                int x = stoi(subslot)-1;
                this->kurangiBarang(namaBarang, 1);
                pembeli->setPenyimpanan(x, y, ListBarang[pilihanBarang - 1]);
            }
            
        }
        cout << "Selamat Anda berhasil membeli " << kuantitas << " " << namaBarang << ". Uang Anda tersisa " << pembeli->getUang() << " gulden." << endl;

    }catch(TokoException& e){
        cout << e.what() << '\n';
    }
}

void Toko :: jual(User* penjual){
    try{
        cout << "\nBerikut merupakan penyimpanan Anda" << endl;
        penjual->cetak_penyimpanan();
        cout << "Masukkan jumlah barang yang ingin dijual : ";
        int cntBarang;
        cin >> cntBarang;
        cout << "Silahkan pilih petak yang ingin Anda jual!" << endl;
        int total = 0;
        for (int i = 0; i < cntBarang;i++){
            cout << "Pilih slot ke-" << i + 1 << " : ";
            string petakPilihan;
            cin >> petakPilihan;
            string subslot = petakPilihan.substr(1,3);
            int y = petakPilihan[0] - 'A';
            int x = stoi(subslot)-1;
            InvItems *barang = penjual->jual(x, y);
            cout << barang->getNama() << endl;

            if(Petani* p = dynamic_cast<Petani*>(penjual)){
                if(Building* b = dynamic_cast<Building*>(barang)){
                    penjual->batalJual(barang, x, y);
                    throw RoleJualTidakSesuai();
                }
            }

            if(Peternak* p = dynamic_cast<Peternak*>(penjual)){
                if(Building* b = dynamic_cast<Building*>(barang)){
                    penjual->batalJual(barang, x, y);
                    throw RoleJualTidakSesuai();
                }
            }

            this->addBarang(barang, 1);
            total += barang->getPriceItem();
        }

        cout << "\nBarang Anda berhasil dijual! Uang Anda bertambah "<<total<<" gulden!" << endl;
    }catch(TokoException& e){
        cout << e.what() << '\n';
    }catch(UserException& e){
        cout << e.what() << "\n";
    }
}

const map<string, int>& Toko::getListStok(){
    return ListStok;
}