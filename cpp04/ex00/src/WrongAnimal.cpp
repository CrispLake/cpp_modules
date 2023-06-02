#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
	std::cout << "WrongAnimal constructor called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
	std::cout << "WrongAnimal copy constructor called\n";
	type = other.type;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& other) {
	std::cout << "WrongAnimal copy assigment operator called\n";
	if (this == &other) {
		type = other.type;
	}
	return (*this);
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called\n";
}

void	WrongAnimal::makeSound() const {
	std::cout << "*WrongAnimal sounds*\n";
}

std::string	WrongAnimal::getType() const {
	return (type);
}
