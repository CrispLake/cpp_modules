/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:14:59 by emajuri           #+#    #+#             */
/*   Updated: 2023/06/08 19:24:59 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include <iostream>
#include "ICharacter.hpp"

Ice::Ice() : AMateria("ice") {
}

Ice::Ice(const Ice& other) {
	typeStr = other.typeStr;
}

Ice&	Ice::operator=(const Ice& other) {
	if (this != &other)
		typeStr = other.typeStr;
	return (*this);
}

Ice::~Ice() {
}

AMateria*	Ice::clone() const {
	return (new Ice(*this));
}

void	Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}
