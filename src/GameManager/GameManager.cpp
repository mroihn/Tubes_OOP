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
                animals[nama] = h;
            }else if(type=="CARNIVORE"){
                Carnivore *h = new Carnivore(id, kode_huruf, nama, weight_to_harvest, price);
                animals[nama] = h; 
            }else{
                Omnivore *h = new Omnivore(id, kode_huruf, nama, weight_to_harvest, price);
                animals[nama] = h;
            }
        }
    }
    file.close();

    for (auto hewan : animals) {
        hewan.second->print();
    }
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
                ListTanaman[nama] = p;
            }else if(type=="MATERIAL_PLANT"){
                Material_Plant *p = new Material_Plant(id,kode_huruf,nama,duration_to_harvest,price);
                ListTanaman[nama] = p;
            }
        }
    }
    file.close();
    //test print to see if the config has been read
    for (auto& tanaman : ListTanaman) {
        tanaman.second->print();
    }
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
                ListProduk[nama] = produk;
            }else if(type=="PRODUCT_FRUIT_PLANT"){
                Fruit *produk = new Fruit(id,kode_huruf,nama,origin,added_weight,price);
                ListProduk[nama] = produk;
            }else{
                Meat *produk = new Meat(id,kode_huruf,nama,origin,added_weight,price);
                ListProduk[nama] = produk;
            }
        }
    }
    file.close();
    //test print to see if the config has been read
    for (auto& produk : ListProduk) {
        produk.second->print();
    }
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
            
            Building building(id, kode_huruf, nama, price, recipe);
            ListBuilding[nama] = building;
        }
        recipe.clear();
    }
    file.close();

    //test print to see if the config has been read
    for (auto& building : ListBuilding) {
        building.second.print();
    }
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
        User*u;
        if(role=="Petani"){
            u = new Petani(nama,berat,uang, inventorySize, fieldSize);
        }else if(role=="Peternak"){
            u = new Peternak(nama,berat,uang,inventorySize, farmSize);
        }else{
            u = new Walikota(nama,berat,uang,inventorySize);
        }
        ListUser[nama] = u;
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
            auto it = animals.find(item_name);
            auto it2 = ListTanaman.find(item_name);
            auto it3 = ListProduk.find(item_name);
            auto it4 = ListBuilding.find(item_name);
            if(it != animals.end()){
                Hewan * h = animals[item_name]->clone();
                u->setPenyimpanan(h);
                //u->penyimpanan.addItem(h)
            }else if(it2 != ListTanaman.end()){
                Tanaman * t = ListTanaman[item_name]->clone();
                u->setPenyimpanan(t);
            }else if(it3 != ListProduk.end()){
                Product * p = ListProduk[item_name]->clone();
                u->setPenyimpanan(p);
            }else if(it4 != ListBuilding.end()){
                Building b = ListBuilding[item_name];
                u->setPenyimpanan(&b);
            }
            n_items--;
        }
        u->cetak_penyimpanan();
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
                int row = (pos[1]-'0')*10 + (pos[2]-'0');
                Tanaman * t = ListTanaman[plantname]->clone();
                t->setUmur(umur);
                p->getladang()->addItem(t,row,col);
                n_tanaman--;
            }
            p->cetakLadang();
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
                int row = (pos[1]-'0')*10 + (pos[2]-'0');
                Hewan * t = animals[animalName]->clone();
                t->setBerat(berat);
                p->getfarm()->addItem(t,row,col);
                n_hewan--;
            }
            p->cetakPeternakan();
            ListUser[nama] = p;
        }
        jumlahPlayer--;
    }
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
