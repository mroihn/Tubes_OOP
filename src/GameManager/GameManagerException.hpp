#ifndef GAMEMANAGER_EXCEPTION_HPP
#define GAMEMANAGER_EXCEPTION_HPP

#include <iostream>
using namespace std;

class GameManagerException{
    public :
        virtual string what()=0; //pure virtual
};



class MasukkanSalah : public GameManagerException {
    public :
        string what() override{
            return "Masukkan tidak sesuai periksa lagi!\n";
        }
};


#endif