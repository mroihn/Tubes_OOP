#ifndef INVITEMS_EXCEPTION_HPP
#define INVITEMS_EXCEPTION_HPP

#include <exception>
using namespace std;

class InvItemsException{
    public :
        virtual string what()=0; //pure virtual
};
struct MakananTidakCocokException : public InvItemsException  {
	string what() {
		return "Makanan Tidak Cocok, Berikan makanan lain!";
	}
};


#endif