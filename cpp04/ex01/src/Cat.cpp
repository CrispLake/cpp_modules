/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:44:39 by emajuri           #+#    #+#             */
/*   Updated: 2023/06/05 15:56:52 by emajuri          ###   ########.fr       */
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
	copyBrain(other.brain);
}

Cat&	Cat::operator=(const Cat& other) {
	std::cout << "Cat copy assigment operator called\n";
	if (this == &other) {
		type = other.type;
		copyBrain(other.brain);
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

void	Cat::copyBrain(const Brain* otherBrain) {
	brain = new Brain;
	for (int i = 0; i < 100; i++) {
		brain[i] = otherBrain[i];
	}
}
