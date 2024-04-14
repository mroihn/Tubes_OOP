#ifndef TOKO_HPP
#define TOKO_HPP

#include "../Inventory/Inventory.hpp"  
#include "../InvItems/InvItems.hpp"
#include "../User/User.hpp"
#include "TokoException.hpp"
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
        void addBarang(InvItems* item,int stok);
        void kurangiBarang(string namaBarang, int jumlah);
        void beli(User* pembeli);
        void jual(User* penjual);
};

#endif