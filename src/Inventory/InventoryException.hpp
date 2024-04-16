#ifndef INVENTORYEXCEPTION_HPP
#define INVENTORYEXCEPTION_HPP
#include <iostream>
using namespace std;

class InventoryException{
    public :
        virtual string what()=0; //pure virtual
};

class PenyimpananPenuh : public InventoryException{
    public :
        string what() override{
            return "Penyimpanan Penuh!\n";
        }
};

class BarisKolomTidakSesuai : public InventoryException {
    public :
        std::string what() override{
            return "Input baris dan kolom tidak sesuai dengan ukuran matriks penyimpanan\n";
        }
};

class SlotTerisi : public InventoryException {
    public:
        std::string what() override {
            return "Slot Sudah Terisi. \nPilih slot lain\n";
        }
};

#endif