// Inventory.hpp

#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include <vector>
#include <iostream>
#include <iomanip>
#include <sstream>
// #include <string>
#include "../User/UserException.hpp"
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

    void deleteItem(T item);

    template<typename U>
    U* getItem(int row, int col);

    int getRows() const;

    int getCols() const;

    int getNeff() const;

    void incNeff();
    
    void decNeff();
    
    bool isEmpty();

    bool isFull();

    T& operator()(int i, int j);

    Inventory<T>& operator+(const T& item);
};

#endif