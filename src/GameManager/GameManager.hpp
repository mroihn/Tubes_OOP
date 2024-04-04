#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "../InvItems/InvItems.hpp"

using namespace std;

class GameManager{
    private:
        vector<Hewan> animals;
        vector<Tanaman> ListTanaman;
        vector<Product> ListProduk;
        vector<Building> ListBuilding;
    public:
        void bacaConfigHewan(string filename);
        void bacaConfigTanaman(string filename);
        void bacaConfigProduk(string filename);
        void bacaConfigRecipe(string filename);
        void printLogo();
};