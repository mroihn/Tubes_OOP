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
            Hewan hewan(id, kode_huruf, nama, type, weight_to_harvest, price);
            animals.push_back(hewan);
        }
    }
    file.close();

    for (auto& hewan : animals) {
        hewan.print();
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
            Tanaman tanaman(id, kode_huruf, nama, type, duration_to_harvest, price);
            ListTanaman.push_back(tanaman);
        }
    }
    file.close();
    //test print to see if the config has been read
    for (auto& tanaman : ListTanaman) {
        tanaman.print();
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
            Product produk(id, kode_huruf, nama, type, origin, added_weight, price);
            ListProduk.push_back(produk);
        }
    }
    file.close();
    //test print to see if the config has been read
    for (auto& produk : ListProduk) {
        produk.print();
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
            ListBuilding.push_back(building);
        }
        recipe.clear();
    }
    file.close();

    //test print to see if the config has been read
    for (auto& building : ListBuilding) {
        building.print();
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
