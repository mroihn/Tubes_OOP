#include<iostream>
#include"./GameManager/GameManager.hpp"
using namespace std;

int main(){
    GameManager game;

    game.printLogo();

    cout<<"Pilih opsi memulai game"<<endl;
    cout<<"1. Baca dari berkas"<<endl;
    cout<<"2. Tanpa baca"<<endl;
    cout<<"\n";

    cout<<"Ketik (1/2)"<<endl;
    int pilihan;
    cin>>pilihan;

    if(pilihan == 1){
        game.bacaConfigHewan("../config/animal.txt");
        game.bacaConfigTanaman("../config/plant.txt");
    }
}
