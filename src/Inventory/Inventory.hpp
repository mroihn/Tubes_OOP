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

        // Inventory<T> operator+(const Inventory<T>& other) const {
        //     Inventory<T> result(rows, cols);
        //     for (int i = 0; i < rows; ++i) {
        //         for (int j = 0; j < cols; ++j) {
        //             result(i, j) = contents[i][j] + other(i, j);
        //         }
        //     }
        //     return result;
        // }

        // Inventory<T> operator*(const Inventory<T>& other) const {
        //     if (cols != other.rows) {
        //         throw std::invalid_argument("Number of columns in first Inventory must match number of rows in second Inventory");
        //     }

        //     Inventory<T> result(rows, other.cols);
        //     for (int i = 0; i < rows; ++i) {
        //         for (int j = 0; j < other.cols; ++j) {
        //             for (int k = 0; k < cols; ++k) {
        //                 result(i, j) += contents[i][k] * other(k, j);
        //             }
        //         }
        //     }
        //     return result;
        // }

        void print() const {
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
                    // cout << " ";
                }
                cout << " |" << endl;
            }
            cout << "     ";
            for (int j = 0; j < cols; ++j) {
                cout << "+-----";
            }
            cout << "+" << endl;
        }

};