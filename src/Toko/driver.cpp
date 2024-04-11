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
    Tanaman* t1 = new Tanaman(1,"ABC","hahuy",5,4);
    Tanaman* t2 = new Tanaman(2,"DEF","hihihiha",7,8);
    Tanaman* t3 = new Tanaman(3,"XYZ","mimimimimimimi",11,12);
    p.setPenyimpanan(0,0,t1);
    p.setPenyimpanan(0,1,t2);
    p.setPenyimpanan(2,2,t3);
    p.cetak_penyimpanan();
    t.beli(&p);
    t.jual(&p);
}