#include "GameManager.hpp"
#include "GameManager.cpp"
#include "../InvItems/InvItems.cpp"
#include "../Inventory/Inventory.cpp"
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
    g.bacaState("../../data/state.txt");
}