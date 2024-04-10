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
            return "Input baris dan kolom tidak sesuai dengan ukuran matriks penyimpanan";
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

#endif
