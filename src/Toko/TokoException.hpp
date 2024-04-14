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

class UangTidakCukup  : public TokoException {
    public :
        string what() override{
            return "Uang pembeli tidak cukup\n";
        }
};

#endif