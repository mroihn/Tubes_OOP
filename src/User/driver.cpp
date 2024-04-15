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
    // p.setPenyimpanan(0,0,t1);
    // p.setPenyimpanan(0,1,t2);
    // p.setPenyimpanan(2,2,t3);
    // p.tanamTanaman();
    // p.cetak_penyimpanan();
    // p.cetakLadang();
    // p.tanamTanaman();
    // p.cetak_penyimpanan();
    // p.cetakLadang();
    // //p.ladang(0,0)->print();

    
    //  Walikota u("JohnDoe", n);

    // // Menambahkan beberapa item ke penyimpanan u
    // u.setPenyimpanan(0, 0, new Fruit(1, "FRT1", "Apple", "Local", 1, 5));
    // u.setPenyimpanan(0, 1, new Material(2, "MAT1", "Wood", "Oak", 1, 3));
    // u.setPenyimpanan(1, 1, new Meat(3, "MET1", "Beef", "Local", 2, 10));

    // // Memanggil metode makan untuk menguji fungsinya
    // u.makan(); 

    //uji peternak
    // Peternak p1("peternak1",n,n);
    // p1.setPenyimpanan(0,0,new Meat(1,"SHM","SHEEP_MEAT","SHEEP",16,5));
    // p1.setPenyimpanan(0,1,new Meat(2,"AYM","Daging Ayam","Local",1,3));
    // p1.setPenyimpanan(1,1,new Fruit(3,"KMB","Daging Kambing","Local",14,10));
    // p1.setPenyimpanan(2,2,new Carnivore(4,"SNK","SNAKE", 13, 4));

    // p1.ternak();
    // cout << "makan" << endl;
    // p1.kasihMakan();
    // cout << "driver cetakpenyimpanan" << endl;
    // p1.cetak_penyimpanan();
    // cout << "driver cetakternak" << endl;
    // p1.cetakPeternakan();

    //uji pajak petani
    // Petani p("Budi",n,n);
    // p.setPenyimpanan(0,0,new Meat(1,"SHM","SHEEP_MEAT","SHEEP",16,5));
    // p.setPenyimpanan(0,1,new Meat(2,"AYM","Daging Ayam","Local",1,3));
    // p.setPenyimpanan(1,1,new Fruit(3,"KMB","Daging Kambing","Local",14,10));
    // p.setPenyimpanan(2,3,new Fruit_Plant(4,"APL", "Apple", 10, 5));

    // p.tanamTanaman();
    // cout << p.pungutpajak() << endl;

    //uji pajak peternak    
    Peternak p("Budi", n, n);
    p.setPenyimpanan(0,0,new Meat(1,"SHM","SHEEP_MEAT","SHEEP",16,5));
    p.setPenyimpanan(0,1,new Meat(2,"AYM","Daging Ayam","Local",1,3));
    p.setPenyimpanan(1,1,new Fruit(3,"KMB","Daging Kambing","Local",14,10));
    p.setPenyimpanan(2,3,new Fruit_Plant(4,"APL", "Apple", 10, 5));
    p.setPenyimpanan(2,4, new Carnivore(5,"KCG", "kucing", 20, 5));
    p.ternak();
    cout << p.pungutpajak() << endl;
    //cek uang apakah berkurang
    cout << p.getUang() << endl;

    return 0;
}