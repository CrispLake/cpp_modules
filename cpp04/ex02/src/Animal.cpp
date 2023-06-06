/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:43:06 by emajuri           #+#    #+#             */
/*   Updated: 2023/06/05 12:43:09 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal") {
	std::cout << "Animal constructor called\n";
}

Animal::Animal(const Animal& other) {
	std::cout << "Animal copy constructor called\n";
	type = other.type;
}

Animal&	Animal::operator=(const Animal& other) {
	std::cout << "Animal copy assigment operator called\n";
	if (this == &other) {
		type = other.type;
	}
	return (*this);
}

Animal::~Animal() {
	std::cout << "Animal destructor called\n";
}

void	Animal::makeSound() const {
	std::cout << "*Animal sounds*\n";
}

std::string	Animal::getType() const {
	return (type);
}
