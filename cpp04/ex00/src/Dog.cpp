#include "Dog.hpp"

Dog::Dog() : Animal() {
	std::cout << "Dog constructor called\n";
	type = "Dog";
}

Dog::Dog(const Dog& other) : Animal() {
	std::cout << "Dog copy constructor called\n";
	type = other.type;
}

Dog&	Dog::operator=(const Dog& other) {
	std::cout << "Dog copy assigment operator called\n";
	if (this == &other) {
		type = other.type;
	}
	return (*this);
}

Dog::~Dog() {
	std::cout << "Dog destructor called\n";
}

void	Dog::makeSound() const {
	std::cout << "*Dog sounds*\n";
}
