//ujicoba  InvItems.hpp

#include <iostream>
#include <vector>
#include <string>
#include "InvItems.hpp"
#include "InvItems.cpp"


int main(){

    //1 TEK TEAK_TREE MATERIAL_PLANT 15 5
    Tanaman t(1,"TEK","TEAK_TREE","MATERIAL_PLANT", 15, 5);

    //1 COW COW HERBIVORE 20 6
    Hewan h(1,"COW","COW","HERBIVORE", 20, 6);

    t.print();
    h.print();

    cout << t.getKode() << endl;

    //cek harga Tanaman t
    cout << t.getPriceItem() << endl;

    //cek lama supaya bisa panen
    cout << t.getDurationToHarvestItem() << endl;

    return 0;
}