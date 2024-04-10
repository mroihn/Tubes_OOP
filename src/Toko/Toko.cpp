#include "Toko.hpp"

Toko :: Toko(){
    Tanaman* t1 = new Tanaman(1,"aa","Teak Tree",5,4);
    ListBarang.push_back(t1);
    ListHarga["Teak Tree"] = 1;
    ListStok["Teak Tree"] =1;
    Hewan *t2 = new Hewan(2, "bb", "Cow", 7, 8);
    ListBarang.push_back(t2);
    ListHarga["Cow"] = 1;
    ListStok["Cow"] =1;
    // for (int i = 0; i < ListBarang.size();i++){
    //     cout << ListBarang[i]->getNama() << endl;
    // }
    // ListHarga["Cow"] = 1;
    // ListStok["Cow"] =-1;
    // ListHarga["Sheep"] = 1;
    // ListStok["Sheep"] =-1;
    // ListHarga["Horse"] = 1;
    // ListStok["Horse"] =-1;
    // ListHarga["Rabbit"] = 1;
    // ListStok["Rabbit"] =-1;
    // ListHarga["Snake"] = 1;
    // ListStok["Snake"] =-1;
    // ListHarga["Chicken"] = 1;
    // ListStok["Chicken"] =-1;
    // ListHarga["Duck"] = 1;
    // ListStok["Duck"] =-1;
    // ListHarga["Teak Tree"] = 1;
    // ListStok["Teak Tree"] =-1;
}

void Toko :: cetak_toko(){
    for (int i = 0; i < ListBarang.size(); i++)
    {
        string namaBarang = ListBarang[i]->getNama();
        int harga = ListHarga[namaBarang];
        int stok = ListStok[namaBarang];
        if(stok == -1){
            cout << i+1 << ". " << namaBarang << " - " << harga << endl;
        }
        else{
            cout << i+1 << ". " << namaBarang << " - " << harga << " (" << stok << ")" << endl;
        }
    }
}

void Toko :: addBarang(InvItems *item, int harga, int stok){
    ListBarang.push_back(item);
    string namaBarang = item->getNama();
    ListHarga[namaBarang] = harga;
    ListStok[namaBarang] = stok;
}

void Toko :: kurangiBarang(string namaBarang, int jumlah){
    if(jumlah>ListStok[namaBarang]){
        cout << "gak cukup bos" << endl;
    }
    else if(jumlah == ListStok[namaBarang]){
        int idx = -1;
        for (int i = 0; i < ListBarang.size();i++){
            if(ListBarang[i]->getNama() == namaBarang){
                idx = i;
            }
        }
        if(idx!=-1){
            ListBarang.erase(ListBarang.begin() + idx);
            ListHarga.erase(namaBarang);
            ListStok.erase(namaBarang);
        }
    }
    else{
        ListStok[namaBarang]-=jumlah;
    }
}
