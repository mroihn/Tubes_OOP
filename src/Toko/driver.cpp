#include"Toko.cpp"
// #include "../Inventory/Inventory.cpp"  
#include "../InvItems/InvItems.cpp"
#include "../User/User.cpp"
#include "../pcolor/pcolor.c"
#include<iostream>

using namespace std;

int main(){
    Toko t;
    // t.cetak_toko();
    // t.kurangiBarang("Cow", 0);
    Walikota p("JohnDoe", make_pair(5,5));
    Peternak k("asep", make_pair(5, 5), make_pair(5, 5));
    Petani z("dono", make_pair(5, 5), make_pair(5, 5));
    Tanaman* t1 = new Material_Plant(1,"ABC","hahuy",5,4);
    Tanaman* t2 = new Fruit_Plant(2,"DEF","hihihiha",7,8);
    Tanaman* t3 = new Fruit_Plant(3,"XYZ","mimimimimimimi",11,12);
     map<string, int> recipe;
    recipe["iron"] = 5;
    recipe["wood"] = 10;
    Building* b = new Building(3,"BBB","rumah",5,recipe);
    p.setPenyimpanan(0,0,t1);
    p.setPenyimpanan(0,1,t2);
    p.setPenyimpanan(2,2,t3);
    p.setPenyimpanan(2,3,b);
    p.cetak_penyimpanan();
    // t.jual(&p);
    t.beli(&p);
    t.jual(&p);
   
    cout << "uang anda " << p.getUang();
    z.cetak_penyimpanan();
    t.cetak_toko();
}