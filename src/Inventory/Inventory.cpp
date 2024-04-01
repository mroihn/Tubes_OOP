#include "Inventory.hpp"
#include "../BahanBaku/BahanBaku.hpp"
using namespace std;
int main(){
    Inventory<int> i(8,7);
    i.print();
    Hewan a(1,"COW", "sapi", "hERB", 4, 3);
    cout << a;
}