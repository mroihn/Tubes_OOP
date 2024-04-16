// Inventory.cpp

#include "Inventory.hpp"
#include "InventoryException.hpp"

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
    if (row < 0 || row > rows || col < 0 || col > cols) {
        throw BarisKolomTidakSesuai();
    }
    if(contents[row][col]!= nullptr){
        throw SlotTerisi();
    }
    contents[row][col] = item;
    neff++;
}

template<class T>
void Inventory<T>::deleteItem(T item) {
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(contents[i][j]==item){
                delete contents[i][j];
                contents[i][j]=nullptr;
                // printf("Item ditambahkan di %d, %d\n", i,j);
                neff--;
                return;
            }
        }
    }
    cout << "Item Tidak ada di penyimpanan\n";
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
void Inventory<T>::incNeff(){
    neff++;
}

template<class T>
void Inventory<T>::decNeff(){
    neff--;
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
    if(i<0 || j<0 || i>rows-1 || j>cols-1){
        throw BarisKolomTidakSesuai();
    }
    return contents[i][j];
}

template<class T>
Inventory<T>& Inventory<T>::operator+(const T& item) {
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(contents[i][j]==nullptr){
                contents[i][j]=item;
                neff++;
                return *this;
            }
        }
    }
    throw PenyimpananPenuh();
}