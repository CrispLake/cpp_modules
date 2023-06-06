/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:44:41 by emajuri           #+#    #+#             */
/*   Updated: 2023/06/06 11:12:20 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal() {
	std::cout << "Dog constructor called\n";
	type = "Dog";
	brain = new Brain;
}

Dog::Dog(const Dog& other) : Animal() {
	std::cout << "Dog copy constructor called\n";
	type = other.type;
	brain = new Brain(*other.brain);
}

Dog&	Dog::operator=(const Dog& other) {
	std::cout << "Dog copy assigment operator called\n";
	if (this == &other) {
		type = other.type;
		*brain = *other.brain;
	}
	return (*this);
}

Dog::~Dog() {
	std::cout << "Dog destructor called\n";
	delete brain;
}

void	Dog::makeSound() const {
	std::cout << "*Dog sounds*\n";
}

Brain*	Dog::getBrain() const {
	return (brain);
}
