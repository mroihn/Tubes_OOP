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
        int id, harvest_price, price;
        string kode_huruf, nama, type;

        if (iss >> id >> kode_huruf >> nama >> type >> harvest_price >> price) {
            Hewan hewan(id, kode_huruf, nama, type, harvest_price, price);
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
        int id, harvest_price, price;
        string kode_huruf, nama, type;

        if (iss >> id >> kode_huruf >> nama >> type >> harvest_price >> price) {
            Tanaman tanaman(id, kode_huruf, nama, type, harvest_price, price);
            ListTanaman.push_back(tanaman);
        }
    }
    file.close();

    for (auto& tanaman : ListTanaman) {
        tanaman.print();
    }
}

//testing
int main(){
    GameManager g;
    g.bacaConfigHewan("../config/animal.txt");
    g.bacaConfigTanaman("../config/plant.txt");
}