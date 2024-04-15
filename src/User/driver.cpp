#include "User.hpp"
#include "User.cpp"
#include "../pcolor/pcolor.c"
#include "../InvItems/InvItems.cpp"
int main(){
    pair<int,int> n(5,5);
    // Petani p("Budi",n,n);
    // Tanaman* t1 = new Material_Plant(1,"ABC","hahuy",5,4);
    // Tanaman* t2 = new Fruit_Plant(2,"DEF","hihihiha",7,8);
    // Tanaman* t3 = new Fruit_Plant(3,"XYZ","mimimimimimimi",11,12);
    // Meat* m1 = new Meat(3, "MET1", "Beef", "Local", 2, 10);
    // p.setPenyimpanan(0,0,t1);
    // p.setPenyimpanan(0,1,t2);
    // p.setPenyimpanan(2,2,m1);
    // p.tanamTanaman();
    // p.cetak_penyimpanan();
    // p.cetakLadang();
    // p.tanamTanaman();
    // p.cetak_penyimpanan();
    // p.cetakLadang();
    //p.ladang(0,0)->print();

    
     Walikota u("JohnDoe", n);

    // Menambahkan beberapa item ke penyimpanan u
    u.setPenyimpanan(0, 0, new Fruit(1, "FRT1", "Apple", "Local", 1, 5));
    u.setPenyimpanan(0, 1, new Material(2, "MAT1", "Wood", "Oak", 1, 3));
    u.setPenyimpanan(1, 1, new Meat(3, "MET1", "Beef", "Local", 2, 10));

    // // Memanggil metode makan untuk menguji fungsinya
    u.makan(); 

    

    return 0;
}