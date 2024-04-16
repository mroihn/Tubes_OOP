#ifndef TOKOEXCEPTION_HPP
#define TOKOEXCEPTION_HPP
#include <iostream>
using namespace std;

class TokoException{
    public :
        virtual string what()=0; //pure virtual
};

class StokBarangKurang : public TokoException {
    public :
        string what() override{
            return "Stok barang kurang\n";
        }
};

class SlotPembeliTidakCukup  : public TokoException {
    public :
        string what() override{
            return "Slot penyimpanan pembeli tidak cukup\n";
        }
};

class UangPembeliTidakCukup  : public TokoException {
    public :
        string what() override{
            return "Uang pembeli tidak cukup\n";
        }
};

class RoleBeliTidakSesuai  : public TokoException {
    public :
        string what() override{
            return "Tidak bisa membeli bangunan dengan role ini\n";
        }
};

class RoleJualTidakSesuai  : public TokoException {
    public :
        string what() override{
            return "Tidak bisa menjual bangunan dengan role ini\n";
        }
};

class PilihanBarangTidakAda  : public TokoException {
    public :
        string what() override{
            return "Barang yang dipilih tidak ada\n";
        }
};

class ItemPenjualTidakCukup  : public TokoException {
    public :
        string what() override{
            return "Item di inventory penjual tidak cukup\n";
        }
};

#endif