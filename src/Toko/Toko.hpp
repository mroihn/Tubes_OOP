#ifndef TOKO_HPP
#define TOKO_HPP

#include "../Inventory/Inventory.hpp"  
#include "../InvItems/InvItems.hpp"
#include <vector>
#include <map>

using namespace std;

class Toko{
    private:
        map<string, int> ListHarga;
        map<string, int> ListStok;
        vector<InvItems*> ListBarang;
    public:
        Toko();
        void cetak_toko();
        void addBarang(InvItems* item,int harga,int stok);
        void kurangiBarang(string namaBarang, int jumlah);
        void beli();
        void jual();
};

#endif