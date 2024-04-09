#ifndef INVITEMS_EXCEPTION_HPP
#define INVITEMS_EXCEPTION_HPP

#include <exception>
using namespace std;

struct MakananTidakCocokException : public exception  {
	const char* what() const throw() {
		return "Makanan Tidak Cocok, Berikan makanan lain!";
	}
};


#endif