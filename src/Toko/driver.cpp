#include"Toko.cpp"
#include "../Inventory/Inventory.cpp"  
#include "../InvItems/InvItems.cpp"
#include<iostream>

using namespace std;

int main(){
    Toko t;
    t.cetak_toko();
    t.kurangiBarang("Cow", 0);
    t.cetak_toko();
}