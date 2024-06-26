#include<iostream>
#include"./GameManager/GameManager.hpp"
using namespace std;

int main(){
    GameManager game;

    game.printLogo();

    game.bacaConfigHewan("./config/animal.txt");
    game.bacaConfigTanaman("./config/plant.txt");
    game.bacaConfigProduk("./config/product.txt");
    game.bacaConfigRecipe("./config/recipe.txt");
    game.bacaConfigMisc("./config/misc.txt");
    
    while(true){
        try{
            cout << "Apakah Anda ingin memuat state? (y/n) ";
            string pilihan;
            cin>>pilihan;

            if(pilihan == "y"){
                cout << "Masukkan lokasi berkas state: ";
                string fileloc;
                cin >> fileloc;
                game.bacaState(fileloc);
            }
            else{
                game.mulaiTanpaBaca();
            }
            break;
        }catch(GameManagerException& e){
             for (int i = 0; i < e.what().length(); ++i) {
                print_red(e.what()[i]);
            }
        }
    }
    game.cetakCommand();
    game.play();
    game.cetakPemenang();
}
