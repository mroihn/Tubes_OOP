#ifndef GAMEMANAGER_EXCEPTION_HPP
#define GAMEMANAGER_EXCEPTION_HPP

#include <iostream>
using namespace std;

class GameManagerException{
    public :
        virtual string what()=0; //pure virtual
};

class RoleTidakSesuai : public GameManagerException {
    public :
        string what() override{
            return "Tidak dapat menjalankan command dengan role ini\n";
        }
};


#endif