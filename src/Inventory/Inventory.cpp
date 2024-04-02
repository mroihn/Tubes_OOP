// ini adalah Inventory.cpp
#include "Inventory.hpp"
#include "../InvItems/InvItems.hpp"

int main(){
    Inventory<InvItems> i(8,7);

    Tanaman t(1,"TEK","TEAK_TREE","MATERIAL_PLANT", 15, 5);
    Hewan h(1,"COW","COW","HERBIVORE", 20, 6);

    i.push(t, 0, 0);
    i.push(h, 0, 1);

    i.print();

    //periksa apakah seorang petani bisa mem-pop hewan di 0,1
    //buat pop yang hanya bisa pop tanaman
    i.pop<Tanaman>(0,1);

    //periksa apakah seorang peternak bisa mem-pop tanaman di 0,0
    //buat pop yang hanya bisa pop tanaman
    i.pop<Hewan>(0,1);

    //pura-puranya petani mau tau, berapa sih harga di penyimpanan (0,0)
    cout << "harga dari item di 0,0 adalah: ";
    cout << i.getPrice(0, 0) << endl;
}