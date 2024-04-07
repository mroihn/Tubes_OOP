// ini adalah driver.cpp
#include "Inventory.hpp"
#include "../InvItems/InvItems.hpp"
#include "../InvItems/InvItems.cpp"

int main(){
    Inventory<InvItems*> inv(5,8);

    Tanaman t(1,"TEK","TEAK_TREE", 15, 5);

    Hewan h(1,"COW","COW", 20, 6);

    inv.addItem(&t, 0, 0);

    inv.addItem(&h, 1, 1);

    // di koordinat 0,0 which is nyimpen tanaman t, kita tes bisakah akses fungsi parent yakni getKode()
    // ya, bisa
    cout << (inv.getItem<Tanaman>(0,0))->getKode() << endl;

    //di koordinat 0,0 which is nyimpen tanaman t, kita tes bisakah akses fungsi children yang
    // diturunkan dari kelas parent yakni print()
    (inv.getItem<Tanaman>(0,0))->print();

    // contoh kode kalau petani mau nanam tanaman ke ladang, kalian kan harus validasi kalau item adalah
    // tanaman kan, nah contohnya gini, misal si petani ngambil hewan (1,1)
    try {
        auto item = inv.getItem<Tanaman>(1,1);
        if (item != nullptr) {
            item->print();
        } else {
            throw std::runtime_error("Objek tidak ditemukan atau tipe tidak cocok.");
        }
    } catch (const std::exception& e) {
        std::cerr << "Terjadi kesalahan: " << e.what() << std::endl;
    }

    return 0;
}