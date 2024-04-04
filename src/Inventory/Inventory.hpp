#include <vector>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <functional>
using namespace std;

template<class T>
class Inventory{
    private:
        vector<vector<T>> contents; // Menggunakan T sebagai tipe langsung di dalam vektor
        int rows, cols;
        int neff
    public:
        Inventory(int rows, int cols) : rows(rows), cols(cols) {
            contents.resize(rows, vector<T>(cols)); // Menggunakan T sebagai tipe langsung di dalam vektor
        }

        ~Inventory(){
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols; j++) {
                        delete contents[i][j];
                }
            }
        }

        void addItem(T item, int row, int col) {
            if (row >= 0 && row < rows && col >= 0 && col < cols) {
                contents[row][col] = item; // Menyimpan referensi yang sudah ada
            } else {
                cerr << "Posisi tidak valid." << endl;
            }
        }

        template<typename U>
        U* getItem(int row, int col) {
            if (row >= 0 && row < rows && col >= 0 && col < cols) {
                // Pastikan bahwa tipe U adalah subclass dari InvItems
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

        int getRows() const {
            return rows;
        }

        int getCols() const {
            return cols;
        }

        int getNeff() const {
            return neff;
        }

        bool isEmpty(){
            return(neff==0);
        }

        bool isFull(){
            return(neff==rows*cols);
        }
        
        T& operator()(int i, int j) const {
            return contents[i][j];
        }
};