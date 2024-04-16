#include "GameManager.hpp"
#include "GameManager.cpp"
#include "../InvItems/InvItems.cpp"
#include "../Toko/Toko.cpp"
// #include "../Inventory/Inventory.cpp"
#include "../User/User.cpp"
#include "../pcolor/pcolor.c"
// #include "../InvItems/InvItems.cpp"


using namespace std;

int main(){
    GameManager g;
    g.bacaConfigHewan("../../config/animal.txt");
    g.bacaConfigTanaman("../../config/plant.txt");
    g.bacaConfigProduk("../../config/product.txt");
    g.bacaConfigRecipe("../../config/recipe.txt");
    g.bacaConfigMisc("../../config/misc.txt");
    //g.driver();

    Tanaman *t = Tanaman::getlistTanaman()["APPLE_TREE"]->clone();
    Tanaman *t2 = Tanaman::getlistTanaman()["APPLE_TREE"]->clone();
    t->setUmur(20);
    t2->setUmur(20);
    pair<int,int> n(5,5);
    Petani p("Bagas", n,n);
    p.getladang()+t;
    p.getladang()+t2;
    p.panen();

    Hewan *h = Hewan::getListHewan()["CHICKEN"]->clone();
    Hewan *h2 = Hewan::getListHewan()["CHICKEN"]->clone();
    h->print();
    h->setBerat(20);
    h2->setBerat(20);
    // pair<int,int> n(5,5);
    // Peternak a("Nayla", n,n);
    // a.cetakPeternakan();
    Peternak pt("Jotaro", n,n);
    cout << pt.getBerat() << endl;
    pt.cetakPeternakan();
    pt.getfarm()+h;
    pt.getfarm()+h2;
    pt.panen();

    // //testing tambahBangunan()
    // Walikota u("JohnDoe", n);

    // // Menambahkan beberapa item ke penyimpanan u
    // u.setPenyimpanan(0, 0, new Fruit(1, "FRT1", "Apple", "Local", 1, 5));
    // u.setPenyimpanan(0, 1, new Material(2, "MAT1", "SANDAL_WOOD", "Oak", 3, 3));
    // u.setPenyimpanan(1, 3, new Material(2, "MAT2", "TEAK_WOOD", "Oak", 1, 4));
    // u.setPenyimpanan(1, 1, new Meat(3, "MET1", "Beef", "Local", 2, 10));


    // // // Memanggil metode makan untuk menguji fungsinya 
    // u.cetak_penyimpanan();
    // u.tambahBangunan();
    // u.cetak_penyimpanan();

    g.bacaState("../../data/state.txt");
    g.simpan("../../data/simpan.txt");
}