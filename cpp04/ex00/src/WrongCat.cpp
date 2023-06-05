/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:44:47 by emajuri           #+#    #+#             */
/*   Updated: 2023/06/05 12:44:48 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
	std::cout << "WrongCat constructor called\n";
	type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal() {
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

void	WrongCat::makeSound() const {
	std::cout << "*WrongCat sounds*\n";
}
