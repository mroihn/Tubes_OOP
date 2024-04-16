#include "GameManager.hpp"

void GameManager::bacaConfigHewan(string filename){
    ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file." << std::endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        int id, weight_to_harvest, price;
        string kode_huruf, nama, type;

        if (iss >> id >> kode_huruf >> nama >> type >> weight_to_harvest >> price) {
            if(type=="HERBIVORE"){
                Herbivore *h = new Herbivore(id, kode_huruf, nama, weight_to_harvest, price);
                Hewan::addListHewan(h);
                // animals[nama] = h;
            }else if(type=="CARNIVORE"){
                Carnivore *h = new Carnivore(id, kode_huruf, nama, weight_to_harvest, price);
                Hewan::addListHewan(h);
                // animals[nama] = h; 
            }else{
                Omnivore *h = new Omnivore(id, kode_huruf, nama, weight_to_harvest, price);
                Hewan::addListHewan(h);
                // animals[nama] = h;
            }
        }
    }
    file.close();
}

void GameManager::bacaConfigTanaman(string filename){
    ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file." << std::endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        int id, duration_to_harvest, price;
        string kode_huruf, nama, type;

        if (iss >> id >> kode_huruf >> nama >> type >> duration_to_harvest >> price) {
            if(type=="FRUIT_PLANT"){
                Fruit_Plant *p = new Fruit_Plant(id,kode_huruf,nama,duration_to_harvest,price);
                Tanaman::addlistTanaman(p);
            }else if(type=="MATERIAL_PLANT"){
                Material_Plant *p = new Material_Plant(id,kode_huruf,nama,duration_to_harvest,price);
                Tanaman::addlistTanaman(p);
            }
        }
    }
    file.close();
}

void GameManager::bacaConfigProduk(string filename){
    ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file." << std::endl;
        return;
    }
    // Product
    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        int id, added_weight, price;
        string kode_huruf, nama, type, origin;

        if (iss >> id >> kode_huruf >> nama >> type >> origin >> added_weight >> price) {
            if(type=="PRODUCT_MATERIAL_PLANT"){
                Material *produk = new Material(id,kode_huruf,nama,origin,added_weight,price);
                Product::addListProduk(produk);
            }else if(type=="PRODUCT_FRUIT_PLANT"){
                Fruit *produk = new Fruit(id,kode_huruf,nama,origin,added_weight,price);
                Product::addListProduk(produk);
            }else{
                Meat *produk = new Meat(id,kode_huruf,nama,origin,added_weight,price);
                Product::addListProduk(produk);
            }
        }
    }
    file.close();
}

void GameManager::bacaConfigRecipe(string filename){
    ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file." << std::endl;
        return;
    }
    // Product
    string line;
    map<string, int> recipe;
    while (getline(file, line)) {
        istringstream iss(line);
        int id, material_num, price;
        string kode_huruf, nama, material;

        if (iss >> id >> kode_huruf >> nama >> price) {
            while (iss >> material)
            {
                iss >> material_num;
                recipe[material] = material_num;
            }
            Building *b = new  Building(id, kode_huruf, nama, price, recipe);
            Building::addlistBuilding(b);
        }
        recipe.clear();
    }
    file.close();
}

void GameManager::bacaConfigMisc(string filename){
    ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file." << std::endl;
        return;
    }
    file >> max_uang;
    file.ignore();
    file >> max_berat;
    file.ignore();
    file >> inventorySize.first >> inventorySize.second;
    file.ignore();
    file >> fieldSize.first >> fieldSize.second;
    file.ignore();
    file >> farmSize.first >> farmSize.second;
    // cout << max_uang << " " << max_berat << " " << inventorySize.first << " " << inventorySize.second << " " << fieldSize.first << " " << fieldSize.second << " " << farmSize.first << " " << farmSize.second << endl;
}

void GameManager::bacaState(string filename){
    ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file." << std::endl;
        return;
    }
    int jumlahPlayer;
    file >> jumlahPlayer;
    // jumlahPlayer=1;
    while(jumlahPlayer>0){
        string nama, role;
        int berat, uang, n_items;
        file >> nama >> role >> berat >> uang;
        User*u = new Petani(nama,inventorySize, fieldSize);
        if(role=="Petani"){
            delete u;
            u = new Petani(nama,berat,uang, inventorySize, fieldSize);
        }else if(role=="Peternak"){
            delete u;
            u = new Peternak(nama,berat,uang,inventorySize, farmSize);
        }else{
            delete u;
            u = new Walikota(nama,berat,uang,inventorySize);
        }
        ListUser[nama] = u;
        // u->cetak_penyimpanan();
        file.ignore();
        file >> n_items;
        // n_items=;
        while (n_items>0)
        {
            string item_name;
            file.ignore();
            file >> item_name;
            // animals["COW"]->print();
            // animals[item_name]->print();
            auto it = Hewan::getListHewan().find(item_name);
            auto it2 = Tanaman::getlistTanaman().find(item_name);
            auto it3 = Product::getListProduk().find(item_name);
            auto it4 = Building::getlistBuilding().find(item_name);
            if(it != Hewan::getListHewan().end()){
                Hewan * h = Hewan::getListHewan()[item_name]->clone();
                u->setPenyimpanan(h);
                //u->penyimpanan.addItem(h)
            }else if(it2 != Tanaman::getlistTanaman().end()){
                Tanaman * t = Tanaman::getlistTanaman()[item_name]->clone();
                u->setPenyimpanan(t);
            }else if(it3 != Product::getListProduk().end()){
                Product * p = Product::getListProduk()[item_name]->clone();
                u->setPenyimpanan(p);
            }else if(it4 != Building::getlistBuilding().end()){
                Building *b = Building::getlistBuilding()[item_name];
                u->setPenyimpanan(b);
            }
            n_items--;
        }
        // u->cetak_penyimpanan();
        if(role=="Petani"){
            int n_tanaman;
            Petani*p = dynamic_cast<Petani*>(u);
            file >> n_tanaman;
            while (n_tanaman>0)
            {
                string pos, plantname;
                int umur;
                file >> pos >> plantname >> umur;
                int col = int(pos[0]-'A');
                int row = (pos[1]-'0')*10 + (pos[2]-'0')-1;
                Tanaman * t = Tanaman::getlistTanaman()[plantname]->clone();
                t->setUmur(umur);
                p->getladang().addItem(t,row,col);
                n_tanaman--;
            }
            // p->cetakLadang();
            ListUser[nama] = p;
        }
        if(role=="Peternak"){
            int n_hewan;
            Peternak*p = dynamic_cast<Peternak*>(u);
            file >> n_hewan;
            while (n_hewan>0)
            {
                string pos, animalName;
                int berat;
                file >> pos >> animalName >> berat;
                int col = int(pos[0]-'A');
                int row = (pos[1]-'0')*10 + (pos[2]-'0')-1;
                Hewan * t = Hewan::getListHewan()[animalName]->clone();
                t->setBerat(berat);
                p->getfarm().addItem(t,row,col);
                n_hewan--;
            }
            // p->cetakPeternakan();
            ListUser[nama] = p;
        }
        jumlahPlayer--;
    }
    file.ignore();
    int n_item_in_toko;
    file >> n_item_in_toko;
    while (n_item_in_toko>0)
    {
        string item_name;
        int kuantitas;
        file.ignore();
        file >> item_name >> kuantitas;
        auto it = Hewan::getListHewan().find(item_name);
        auto it2 = Tanaman::getlistTanaman().find(item_name);
        auto it3 = Product::getListProduk().find(item_name);
        auto it4 = Building::getlistBuilding().find(item_name);
        InvItems* i;
        if(it != Hewan::getListHewan().end()){
            i = Hewan::getListHewan()[item_name]->clone();
        }else if(it2 != Tanaman::getlistTanaman().end()){
            i = Tanaman::getlistTanaman()[item_name]->clone();
        }else if(it3 != Product::getListProduk().end()){
            i = Product::getListProduk()[item_name]->clone();
        }else if(it4 != Building::getlistBuilding().end()){
            Building *b = Building::getlistBuilding()[item_name];
            i = b;
        }
        toko.addBarang(i, kuantitas);
        n_item_in_toko--;
    }
    // toko.cetak_toko();
    
}

void GameManager::simpan(string fileloc){
    ofstream file(fileloc);
    if (!file.is_open()) {
        std::cerr << "Lokasi berkas tidak valid\n ";
        return;
    }
    file.clear();
    int n_pemain = ListUser.size();
    file << n_pemain;
    file << endl;
    for(const auto& [nama, user] : ListUser){
        string role;
        stringstream ss;
        if(Petani *p = dynamic_cast<Petani*>(user)){
            role = "Petani";
            ss << p->getladang().getNeff() << endl;
            for(int i = 0; i<p->getladang().getRows(); i++){
                for(int j = 0; j<p->getladang().getCols(); j++){
                    if(p->getladang()(i,j)!=nullptr){
                        string pos;
                        pos = 'A'+j;
                        ss << pos << setw(2) << setfill('0') << i+1 << " " <<  p->getladang()(i,j)->getNama() << " " << p->getladang()(i,j)->getUmur() << endl;
                    }
                }
            }
        }else if(Peternak *p = dynamic_cast<Peternak*>(user)){
            role = "Peternak";
            ss << p->getfarm().getNeff() << endl;
            for(int i = 0; i<p->getfarm().getRows(); i++){
                for(int j = 0; j<p->getfarm().getCols(); j++){
                    if(p->getfarm()(i,j)!=nullptr){
                        string pos;
                        pos = 'A'+j;
                        ss << pos << setw(2) << setfill('0') << i+1 << " " <<  p->getfarm()(i,j)->getNama() << " " << p->getfarm()(i,j)->getBerat() << endl;
                    }
                }
            }
        }else{
            role = "Walikota";
        }
        file << user->getNama() << " " << role << " " << user->getBerat() << " " << user->getUang() << endl;
        file << user->getInv().getNeff() << endl;
        for(int i = 0; i<user->getInv().getRows(); i++){
            for(int j = 0; j<user->getInv().getCols(); j++){
                if(user->getInv()(i,j)!=nullptr){
                    file << user->getInv()(i,j)->getNama() << endl;
                }
            }
        }
        file << ss.str();
    }
    int jumlahJenis = toko.getJumlahJenisBarang();
    file << jumlahJenis << endl;
    for(const auto& pair : toko.getListStok()){
        if(pair.second>0){
            file << pair.first << " " << pair.second << endl;
        }
    }
}

void GameManager :: mulaiTanpaBaca(){
    Petani *p = new Petani("Petani1",inventorySize,fieldSize);
    ListUser["Petani1"] = p;
    Peternak *r = new Peternak("Peternak1",inventorySize,farmSize);
    ListUser["Peternak1"] = r;
    Walikota *w = new Walikota("Walikota",inventorySize);
    ListUser["Walikota"] = w;
}


void GameManager :: printLogo(){
    system("clear");
    cout<<"██████╗  █████╗ ██╗  ██╗ █████╗ ██████╗ ██╗ █████╗  █████╗ "<<endl;
    cout<<"██╔══██╗██╔══██╗██║  ██║██╔══██╗██╔══██╗██║██╔══██╗██╔══██╗"<<endl;
    cout<<"██████╔╝███████║███████║███████║██████╔╝██║╚█████╔╝╚█████╔╝"<<endl;
    cout<<"██╔══██╗██╔══██║██╔══██║██╔══██║██╔══██╗██║██╔══██╗██╔══██╗"<<endl;
    cout<<"██████╔╝██║  ██║██║  ██║██║  ██║██║  ██║██║╚█████╔╝╚█████╔╝"<<endl;
    cout<<"╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝ ╚════╝  ╚════╝ "<<endl;
    cout<<"\n";
}

bool GameManager :: isWin(map<string,User*> ListUser){
    map<std::string, User*>::iterator itr = ListUser.begin();
     while(itr != ListUser.end()){
        if(itr->second->getBerat() >= max_berat && itr->second->getUang() >= max_uang){
            Pemenang = itr->second;
            return true;
        }
        itr++;
     }
    return false;
}

void GameManager :: cetakPemenang(){
    string nama = Pemenang->getNama();
    string s = "SELAMAT!!! " + nama + " memenangkan permainan";
    for (int i = 0; i < s.length(); ++i) {
        print_green(s[i]);
    }
    cout << "\n\n";
}

void GameManager :: cetakCommand(){
    cout << "\nBerikut command yang dapat dijalankan :\n";
    cout << "1. NEXT\n";
    cout << "2. CETAK_PENYIMPANAN\n";
    cout << "3. PUNGUT_PAJAK\n";
    cout << "4. CETAK_LADANG\n";
    cout << "5. CETAK_PETERNAKAN\n";
    cout << "6. TANAM\n";
    cout << "7. TERNAK\n";
    cout << "8. BANGUN\n";
    cout << "9. MAKAN\n";
    cout << "10. KASIH_MAKAN\n";
    cout << "11. BELI\n";
    cout << "12. JUAL\n";
    cout << "13. PANEN\n";
    cout << "14. SIMPAN\n";
    cout << "15. TAMBAH_PEMAIN\n";
}

void GameManager :: play(){
    cekMenang = false;
    map<std::string, User*>::iterator it = ListUser.begin();
    while (!cekMenang){
        cout << "\nGiliran " << it->first<< " untuk bermain!\n";

        string pilihan;
        while(pilihan != "NEXT" && !cekMenang){
            try{
                
                if(isWin(ListUser)){
                    cekMenang = true;
                }
                
                else{
                    cout << "\nUntuk menang diperlukan uang >= " << max_uang << " dan berat >= " << max_berat << endl;
                    cout << "Uang : " << it->second->getUang() << " Berat : " << it->second->getBerat() << endl;
                    print_green('>');
                    cout << " ";
                    cin >> pilihan;

                    if(pilihan == "NEXT"){
                        map<std::string, User*>::iterator itr = ListUser.begin();
                        while(itr != ListUser.end()){
                            if(itr->second->isPetani()){
                                itr->second->tambahUmurTanaman();
                            }
                            itr++;
                        }
                    }

                    else if(pilihan == "CETAK_PENYIMPANAN"){
                        it->second->cetak_penyimpanan();
                    }

                    else if(pilihan == "PUNGUT_PAJAK"){
                        it->second->tagihPajak(ListUser);
                    }

                    else if(pilihan == "CETAK_LADANG"){
                        it->second->cetakLadang();
                    }

                    else if(pilihan == "CETAK_PETERNAKAN"){
                        it->second->cetakPeternakan();
                    }

                    else if(pilihan == "TANAM"){
                        it->second->tanamTanaman();
                    }

                    else if(pilihan == "TERNAK"){
                        it->second->ternak();
                    }

                    else if(pilihan == "BANGUN"){
                        it->second->tambahBangunan();
                    }

                    else if(pilihan == "MAKAN"){
                        it->second->makan();
                    }

                    else if(pilihan == "KASIH_MAKAN"){
                        it->second->kasihMakan();
                    }

                    else if(pilihan == "BELI"){
                        toko.beli(it->second);
                    }

                    else if(pilihan == "JUAL"){
                        toko.jual(it->second);
                    }

                    else if(pilihan == "PANEN"){
                        it->second->panen();
                    }

                    else if(pilihan == "SIMPAN"){
                        cout << "Masukkan lokasi berkas state : ";
                        string loc;
                        cin >> loc;
                        this->simpan(loc);
                    }

                    else if(pilihan == "TAMBAH_PEMAIN"){
                        if(it->second->isWalikota()){
                            User *pemain = it->second->tambahPemain(ListUser,inventorySize, fieldSize, farmSize);
                            if(Petani* s = dynamic_cast<Petani*>(pemain)){
                                ListUser[s->getNama()] = s;
                                cout << "Pemain baru ditambahkan!" << endl;
                                cout << "Selamat datang “" << s->getNama() << "” di kota ini !" << endl;
                            }
                            if(Peternak* t = dynamic_cast<Peternak*>(pemain)){
                                ListUser[t->getNama()] = t;
                                cout << "Pemain baru ditambahkan!" << endl;
                                cout << "Selamat datang “" << t->getNama() << "” di kota ini !" << endl;
                            }

                        }else{
                            throw RoleTidakSesuai();
                        }
                    }

                    else{
                        throw MasukkanSalah();
                    }
                }

                // if(isWin(it->second)){
                //     cekMenang = true;
                // }

            }catch(GameManagerException& e){
                for (int i = 0; i < e.what().length(); ++i) {
                    print_red(e.what()[i]);
                }
            }catch(UserException& e){
                for (int i = 0; i < e.what().length(); ++i) {
                    print_red(e.what()[i]);
                }
            }

        }
        it++;
        if(it == ListUser.end()){
            it = ListUser.begin();
        }
    }
}