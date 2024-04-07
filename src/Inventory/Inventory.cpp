// Inventory.cpp

#include "Inventory.hpp"

template<class T>
Inventory<T>::Inventory(int rows, int cols) : rows(rows), cols(cols), neff(0) {
    contents.resize(rows, vector<T>(cols));
}

template<class T>
Inventory<T>::~Inventory() {
    // Tidak perlu melakukan apa-apa di sini karena tidak ada alokasi dinamis yang perlu dibersihkan secara manual
}

template<class T>
void Inventory<T>::addItem(T item, int row, int col) {
    if (row >= 0 && row < rows && col >= 0 && col < cols) {
        contents[row][col] = item;
        neff++;
    } else {
        cerr << "Posisi tidak valid." << endl;
    }
}

template<class T>
template<typename U>
U* Inventory<T>::getItem(int row, int col) {
    if (row >= 0 && row < rows && col >= 0 && col < cols) {
        U* item = dynamic_cast<U*>(contents[row][col]);
        if (item) {
            return item;
        } else {
            std::cerr << "Tipe tidak valid atau tidak cocok." << endl;
            return nullptr;
        }
    } else {
        cerr << "Posisi tidak valid." << endl;
        return nullptr;
    }
}

template<class T>
int Inventory<T>::getRows() const {
    return rows;
}

template<class T>
int Inventory<T>::getCols() const {
    return cols;
}

template<class T>
int Inventory<T>::getNeff() const {
    return neff;
}

template<class T>
bool Inventory<T>::isEmpty() {
    return (neff == 0);
}

template<class T>
bool Inventory<T>::isFull() {
    return (neff == rows * cols);
}

template<class T>
T& Inventory<T>::operator()(int i, int j) {
    return contents[i][j];
}