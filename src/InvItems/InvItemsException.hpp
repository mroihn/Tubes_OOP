#ifndef INVITEMS_EXCEPTION_HPP
#define INVITEMS_EXCEPTION_HPP

#include <exception>
using namespace std;

class InvItemsException{
    public :
        virtual string what()=0; //pure virtual
};
class HerbivoreMakanDaging : public InvItemsException  {
	public:
	string what() {
		return "Herbivore tidak bisa makan daging, berikan makanan lain!";
	}
};
class CarnivoreMakanBuah : public InvItemsException  {
	public:
	string what() {
		return "Carnivore tidak bisa makan buah, berikan makanan lain!";
	}
};
class ItemBukanMakanan : public InvItemsException  {
	public:
	string what() {
		return "Item ini bukan Makanan!";
	}
};
class MakananTidakCocokException : public InvItemsException  {
	public:
	string what() {
		return "Makanan tidak cocok, berikan jenis makanan lain!";
	}
};


#endif