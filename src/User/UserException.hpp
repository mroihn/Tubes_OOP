#ifndef USEREXCEPTION_HPP
#define USEREXCEPTION_HPP
#include <iostream>
using namespace std;

class UserException {
    public :
        virtual std::string what()=0; //pure virtual
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

class SlotKosong : public UserException {
    public:
        std::string what() override {
            return "Slot ini kosong. \nPilih slot lain\n";
        }
};

class RoleTidakSesuai : public UserException {
    public :
        string what() override{
            return "Tidak dapat menjalankan command dengan role ini\n";
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

class TidakAdaResep : public UserException {
    public:
        std::string what() override {
            return "Kamu tidak punya resep bangunan tersebut! \n";
        }
};

class UangTidakCukup : public UserException {
    public:
        std::string what() override {
            return "Uang tidak cukup! \n";
        }
};
class TanamanBelumSiapPanen : public UserException {
    public:
        std::string what() override {
            return "Belum ada tanaman yang siap untuk dipanen! \n";
        }
};
class HewanBelumSiapPanen : public UserException {
    public:
        std::string what() override {
            return "Belum ada hewan yang siap untuk dipanen! \n";
        }
};
#endif