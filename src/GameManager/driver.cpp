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
    // g.driver();

    // Tanaman *t = Tanaman::getlistTanaman()["APPLE_TREE"]->clone();
    // Tanaman *t2 = Tanaman::getlistTanaman()["APPLE_TREE"]->clone();
    // t->setUmur(20);
    // t2->setUmur(20);
    pair<int,int> n(5,5);
    // Petani p("Bagas", n,n);
    // p.getladang().addItem(t);
    // p.getladang().addItem(t2);
    // p.panenTanaman();

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
    pt.getfarm().addItem(h);
    pt.getfarm().addItem(h2);
    pt.panen();


    g.bacaState("../../data/state.txt");
    g.simpan("../../data/simpan.txt");
}