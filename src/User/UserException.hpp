#ifndef USEREXCEPTION_HPP
#define USEREXCEPTION_HPP
#include <iostream>
using namespace std;

class UserException {
    public :
        virtual std::string what()=0; //pure virtual
};

class BarisKolomTidakSesuai : public UserException {
    public :
        std::string what() override{
            return "Input baris dan kolom tidak sesuai dengan ukuran matriks penyimpanan\n";
        }
};

class HewanSudahSiapPanen: public UserException {
    public :
        std::string what() override{
            return "Hewan sudah siap panen, tidak usah makan lagi\n";
        }
};

class PenyimpananTidakCukup : public UserException {
    public :
        std::string what() override{
            return "Jumlah Penyimpanan tidak cukup!\n";
        }
};

class HarapanKosong : public UserException {
    public:
        std::string what() override {
            return "Kamu mengambil harapan kosong dari penyimpanan.\nSilahkan masukan slot yang berisi makanan.\n";
        }
};

class BukanHewan : public UserException {
    public:
        std::string what() override {
            return "Apa yang kamu lakukan\?\?!! Itu bukan hewan \?\?!!\nSilahkan masukan slot yang berisi hewan.\n";
        }
};

class BukanMakanan : public UserException {
    public:
        std::string what() override {
            return "Apa yang kamu lakukan\?\?!! Kamu mencoba untuk memakan itu\?\?!!\nSilahkan masukan slot yang berisi makanan.\n";
        }
};

class WalikotaHanyaSatu : public UserException {
    public:
        std::string what() override {
            return "Ups!Peran Walikota hanya boleh satu!\n";
        }
};

class BukanHewan : public UserException {
    public:
        std::string what() override {
            return "Hanya Hewan yang bisa diternak!\n";
        }
};

class BukanTanaman : public UserException {
    public:
        std::string what() override {
            return "Hanya Tanaman yang bisa ditanam!\n";
        }
};

class SlotTerisi : public UserException {
    public:
        std::string what() override {
            return "Slot Sudah Terisi. \nPilih slot lain\n";
        }
};

class SlotKosong : public UserException {
    public:
        std::string what() override {
            return "Slot ini kosong. \nPilih slot lain\n";
        }
};

class LadangFull : public UserException {
    public:
        std::string what() override {
            return "Ladang Sudah Penuh. \n";
        }
};

class LadangEmpty : public UserException {
    public:
        std::string what() override {
            return "Ladang Masih Kosong. \n";
        }
};

class PeternakanFull : public UserException {
    public:
        std::string what() override {
            return "Peternakan Sudah Penuh. \n";
        }
};

class PenyimpananKosong : public UserException {
    public:
        std::string what() override {
            return "Penyimpanan saat ini Kosong. \n";
        }
};


class PeternakanKosong : public UserException {
    public:
        std::string what() override {
            return "Peternakan saat ini Kosong. \n";
        }
};
#endif