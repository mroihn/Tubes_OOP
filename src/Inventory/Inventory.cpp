// #include "Inventory.hpp"

// template<class T>
// Inventory<T>(int rows, int cols) : rows(rows), cols(cols) {
//     contents.resize(rows, vector<T>(cols)); // Menggunakan T sebagai tipe langsung di dalam vektor
// }
// template<class T>
// void Inventory::addItem(T item, int row, int col) {
//     if (row >= 0 && row < rows && col >= 0 && col < cols) {
//         contents[row][col] = item; // Menyimpan referensi yang sudah ada
//     } else {
//         cerr << "Posisi tidak valid." << endl;
//     }
// }

// template<typename U>
// U* getItem(int row, int col) {
//     if (row >= 0 && row < rows && col >= 0 && col < cols) {
//         // Pastikan bahwa tipe U adalah subclass dari InvItems
//         U* item = dynamic_cast<U*>(contents[row][col]);
//         if (item) {
//             return item;
//         } else {
//             std::cerr << "Tipe tidak valid atau tidak cocok." << endl;
//             return nullptr;
//         }
//     } else {
//         cerr << "Posisi tidak valid." << endl;
//         return nullptr;
//     }
// }