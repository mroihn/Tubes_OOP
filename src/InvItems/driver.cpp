//ujicoba  InvItems.hpp

#include <iostream>
#include <vector>
#include <string>
#include "InvItems.hpp"


int main(){

    //1 TEK TEAK_TREE MATERIAL_PLANT 15 5
    Tanaman t(1,"TEK","TEAK_TREE", 15, 5);

    //1 COW COW HERBIVORE 20 6
    Herbivore h(1,"COW","COW", 20, 6);

    //13 SNM SNAKE_MEAT PRODUCT_ANIMAL SNAKE 4 8
    Meat m(13,"SNM", "SNAKE_MEAT", "SNAKE", 4, 8);
    //8 GAP GUAVA PRODUCT_FRUIT_PLANT GUAVA_TREE 4 8
    Fruit f(8, "GAP", "GUAVA", "GUAVA_TREE", 4, 8);

    t.print();
    h.print();
    //Herbivore makan daging
    try{
        h.makan(&m);
        h.print();
    }catch(MakananTidakCocokException e){
        cout << e.what() << endl;
    }
    //Herbivore makan buah
    try{
        h.makan(&f);
        h.print();
    }catch(MakananTidakCocokException e){
        cout << e.what() << endl;
    }


    cout << t.getKode() << endl;

    //cek harga Tanaman t
    cout << t.getPriceItem() << endl;

    //cek lama supaya bisa panen
    cout << t.getDurationToHarvestItem() << endl;

    return 0;
}