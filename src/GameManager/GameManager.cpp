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

    for (auto& tanaman : ListTanaman) {
        tanaman.print();
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
