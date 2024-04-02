// ini adalah Inventory.hpp

#include <vector>
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

template<class T>
class Inventory{
    private:
        vector<vector<T>> contents;
        int rows, cols;
    public:
        Inventory(int rows, int cols) : rows(rows), cols(cols){
            contents.resize(rows, vector<T>(cols));
        }

        int getRows() const {
            return rows;
        }

        int getCols() const {
            return cols;
        }

        T& operator()(int i, int j) {
            return contents[i][j];
        }

        const T& operator()(int i, int j) const {
            return contents[i][j];
        }

        void print() {
            // label
            cout << "        ";
            for(int i=0; i<cols; i++){
                cout << char('A'+i) << "     ";
            }
            cout << endl;
            for (int i = 0; i < rows; ++i) {
                cout << "     ";
                for (int j = 0; j < cols; ++j) {
                    cout << "+-----";
                }
                cout << "+" << endl;
                cout << "  " << setw(2) << setfill('0') << i+1;
                for (int j = 0; j < cols; ++j) {
                    cout << " | ";
                    cout << setw(3) << setfill('0') << contents[i][j];
                }
                cout << " |" << endl;
            }
            cout << "     ";
            for (int j = 0; j < cols; ++j) {
                cout << "+-----";
            }
            cout << "+" << endl;
        }

        void push(T item, int i, int j){
            if(contents[i][j].getKode()==""){
                contents[i][j] = item;
                cout << "Berhasil mem-push " << contents[i][j] << " ke Inventory" <<endl;
                return;
            }
            else{
                cout << "blok ini sudah terisi" << endl;
            }

        }

        template<typename U>
        void pop(int i, int j){
            if(i >= 0 && i < rows && j >= 0 && j < cols){
                if(typeid(contents[i][j]) == typeid(U)){ // Memeriksa apakah jenis objek cocok dengan U
                    if(contents[i][j].getKode() != ""){
                        cout << "Menghapus " << contents[i][j] << " dari Inventory" << endl;
                        contents[i][j] = T();
                        cout << "Penyimpanan Terkini, sbb: " << endl;
                        print();
                    }
                    else{
                        cout << "Tidak ada item di posisi (" << i << ", " << j << ") dalam Inventory" << endl;
                    }
                }
                else{
                    cout << "Tidak dapat menghapus objek yang tidak sesuai dengan jenis yang diinginkan" << endl;
                }
            }
            else{
                cout << "Posisi (" << i << ", " << j << ") tidak valid" << endl;
            }
        }

        int getPrice(int i, int j){
            return contents[i][j].getPriceItem();
        }
};