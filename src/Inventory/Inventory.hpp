// Inventory.hpp

#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include <vector>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <functional>
using namespace std;

template<class T>
class Inventory {
private:
    vector<vector<T>> contents;
    int rows, cols;
    int neff;

public:
    Inventory(int rows, int cols);

    ~Inventory();

    void addItem(T item, int row, int col);

    template<typename U>
    U* getItem(int row, int col);

    int getRows() const;

    int getCols() const;

    int getNeff() const;

    bool isEmpty();

    bool isFull();

    T& operator()(int i, int j);
};

#endif