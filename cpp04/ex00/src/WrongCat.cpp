#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
	std::cout << "WrongCat constructor called\n";
	type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& other) : Animal() {
	std::cout << "WrongCat copy constructor called\n";
	type = other.type;
}

WrongCat&	WrongCat::operator=(const WrongCat& other) {
	std::cout << "WrongCat copy assigment operator called\n";
	if (this == &other) {
		type = other.type;
	}
	return (*this);
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called\n";
}

void	WrongCat::makeSound() {
	std::cout << "*WrongCat sounds*\n";
}
