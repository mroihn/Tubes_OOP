#ifndef USEREXCEPTION_HPP
#define USEREXCEPTION_HPP
#include <iostream>
using namespace std;

class UserException {
    public :
        virtual string what()=0; //pure virtual
};

class BarisKolomTidakSesuai : public UserException {
    public :
        string what() override{
            return "Input baris dan kolom tidak sesuai dengan ukuran matriks penyimpanan\n";
        }
};

class HarapanKosong : public UserException {
    public:
        string what() override {
            return "Kamu mengambil harapan kosong dari penyimpanan.\nSilahkan masukan slot yang berisi makanan.\n";
        }
};

class BukanMakanan : public UserException {
    public:
        string what() override {
            return "Apa yang kamu lakukan\?\?!! Kamu mencoba untuk memakan itu\?\?!!\nSilahkan masukan slot yang berisi makanan.\n";
        }
};

class WalikotaHanyaSatu : public UserException {
    public:
        string what() override {
            return "Ups!Peran Walikota hanya boleh satu!\n";
        }
};

class SlotTerisi : public UserException {
    public:
        string what() override {
            return "Slot Sudah Terisi. \nPilih slot lain\n";
        }
};

class SlotKosong : public UserException {
    public:
        string what() override {
            return "Slot ini kosong. \nPilih slot lain\n";
        }
};

class LadangFull : public UserException {
    public:
        string what() override {
            return "Ladang Sudah Penuh. \n";
        }
};

class PeternakanFull : public UserException {
    public:
        string what() override {
            return "Peternakan Sudah Penuh. \n";
        }
};

class PenyimpananKosong : public UserException {
    public:
        string what() override {
            return "Penyimpanan saat ini Kosong. \n";
        }
};
#endif
