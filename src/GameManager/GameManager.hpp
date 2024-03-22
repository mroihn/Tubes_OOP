#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "../BahanBaku/BahanBaku.hpp"

using namespace std;

class GameManager{
    private:
        vector<Hewan> animals;
        vector<Tanaman> ListTanaman;
    public:
        void bacaConfigHewan(string filename);
        void bacaConfigTanaman(string filename);
        void bacaConfigProduk(string filename);
        void bacaConfigRecipe(string filename);
        void printLogo();
};