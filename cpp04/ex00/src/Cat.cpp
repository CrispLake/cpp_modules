#include "Cat.hpp"

Cat::Cat() : Animal() {
	std::cout << "Cat constructor called\n";
	type = "Cat";
}

Cat::Cat(const Cat& other) : Animal() {
	std::cout << "Cat copy constructor called\n";
	type = other.type;
}

Cat&	Cat::operator=(const Cat& other) {
	std::cout << "Cat copy assigment operator called\n";
	if (this == &other) {
		type = other.type;
	}
	return (*this);
}

Cat::~Cat() {
	std::cout << "Cat destructor called\n";
}

void	Cat::makeSound() const {
	std::cout << "*Cat sounds*\n";
}
