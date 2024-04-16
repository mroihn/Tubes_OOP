#ifndef GAMEMANAGER_HPP
#define GAMEMANAGER_HPP

#include <iostream>
#include <fstream>
#include <sstream>
// #include <string>
#include <vector>
#include <map>
#include "../InvItems/InvItems.hpp"
#include "../Inventory/Inventory.hpp"
#include "../User/User.hpp"
#include "../Toko/Toko.hpp"
#include "GameManagerException.hpp"

using namespace std;

class GameManager{
    private:
        map<string,Building*> ListBuilding;
        map<string,User*> ListUser;
        Toko toko;
        User *Pemenang;
        bool cekMenang;
        int max_uang;
        int max_berat;
        pair<int,int> inventorySize;
        pair<int,int> fieldSize;
        pair<int,int> farmSize;
    public:
        void bacaConfigHewan(string filename);
        void bacaConfigTanaman(string filename);
        void bacaConfigProduk(string filename);
        void bacaConfigRecipe(string filename);
        void bacaConfigMisc(string filename);
        void bacaState(string filename);
        void mulaiTanpaBaca();
        void simpan(string fileloc);
        void printLogo();
        void play();
        bool isWin(map<string,User*> ListUser);
        void cetakPemenang();
        void cetakCommand();
};

#endif