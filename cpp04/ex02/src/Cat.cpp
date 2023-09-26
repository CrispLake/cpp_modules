/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:44:39 by emajuri           #+#    #+#             */
/*   Updated: 2023/09/26 15:29:43 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal() {
	std::cout << "Cat constructor called\n";
	type = "Cat";
	brain = new Brain;
}

Cat::Cat(const Cat& other) : Animal() {
	std::cout << "Cat copy constructor called\n";
	type = other.type;
	brain = new Brain(*other.brain);
}

Cat&	Cat::operator=(const Cat& other) {
	std::cout << "Cat copy assigment operator called\n";
	if (this == &other) {
		type = other.type;
		if (brain)
			delete brain;
		brain = new Brain(*other.brain);
	}
	return (*this);
}

Cat::~Cat() {
	std::cout << "Cat destructor called\n";
	delete brain;
}

void	Cat::makeSound() const {
	std::cout << "*Cat sounds*\n";
}

Brain*	Cat::getBrain() const {
	return (brain);
}
