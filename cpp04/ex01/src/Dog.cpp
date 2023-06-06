/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:44:41 by emajuri           #+#    #+#             */
/*   Updated: 2023/06/06 10:31:43 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal() {
	std::cout << "Dog constructor called\n";
	type = "Dog";
}

Dog::Dog(const Dog& other) : Animal() {
	std::cout << "Dog copy constructor called\n";
	type = other.type;
	copyBrain(other.brain);
}

Dog&	Dog::operator=(const Dog& other) {
	std::cout << "Dog copy assigment operator called\n";
	if (this == &other) {
		type = other.type;
		copyBrain(other.brain);
	}
	return (*this);
}

Dog::~Dog() {
	std::cout << "Dog destructor called\n";
}

void	Dog::makeSound() const {
	std::cout << "*Dog sounds*\n";
}

void	Dog::copyBrain(const Brain* otherBrain) {
	brain = new Brain;
	for (int i = 0; i < 100; i++) {
		brain[i] = otherBrain[i];
	}
}
