#include "User.hpp"
#include "../pcolor/pcolor.c"
int main(){
    Petani p;
    Tanaman* t1 = new Tanaman(1,"ABC","hahuy","plant",5,4);
    Tanaman* t2 = new Tanaman(2,"DEF","hihihiha","plant",7,8);
    Tanaman* t3 = new Tanaman(3,"XYZ","mimimimimimimi","plant",11,12);
    p.setPenyimpanan(0,0,t1);
    p.setPenyimpanan(0,1,t2);
    p.setPenyimpanan(2,2,t3);
    p.tanamTanaman();
    p.cetak_penyimpanan();
    p.cetakLadang();
    //p.ladang(0,0)->print();
    return 0;
}