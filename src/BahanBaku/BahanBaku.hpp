#include <string>

using namespace std;

class BahanBaku{
    protected:
        int id;
        string kode_huruf;
        string nama;
        string type;
        int harvest_price;
        int price;
    public:
        BahanBaku() {}
        BahanBaku(int id, string kode_huruf, string nama, string type, int harvest_price, int price)
        : id(id), kode_huruf(kode_huruf), nama(nama), type(type), harvest_price(harvest_price), price(price) {}
        string getKode(){
            return kode_huruf;
        }
        friend ostream& operator<<(ostream& os, BahanBaku& b){
            os << b.kode_huruf;
            return os;
        }
};


class Hewan: public BahanBaku{
    public:
        Hewan(){}
        Hewan(int id, string kode_huruf, string nama, string type, int harvest_price, int price): 
        BahanBaku(id,kode_huruf,nama, type, harvest_price, price){}
        void print(){
            cout << id << " " << kode_huruf << " " << nama << " " << type << " " << harvest_price << " " << price << std::endl;
        }
        // friend ostream& operator<<(ostream& os, Hewan b){
        //     os << b.kode_huruf;
        //     return os;
        // }
};

class Tanaman: public BahanBaku{
    public:
        Tanaman(){}
        Tanaman(int id, string kode_huruf, string nama, string type, int harvest_price, int price): 
        BahanBaku(id,kode_huruf,nama, type, harvest_price, price){}
        void print(){
            cout << id << " " << kode_huruf << " " << nama << " " << type << " " << harvest_price << " " << price << std::endl;
        }
};