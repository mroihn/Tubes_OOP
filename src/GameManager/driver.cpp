#include "GameManager.hpp"
#include "GameManager.cpp"
#include "../InvItems/InvItems.cpp"
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

    Tanaman *t = Tanaman::getlistTanaman()["APPLE_TREE"]->clone();
    Tanaman *t2 = Tanaman::getlistTanaman()["APPLE_TREE"]->clone();
    t->setUmur(20);
    t2->setUmur(20);
    pair<int,int> n(5,5);
    Petani p("Bagas", n,n);
    p.getladang().addItem(t);
    p.getladang().addItem(t2);
    p.panenTanaman();

    g.bacaState("../../data/state.txt");
}