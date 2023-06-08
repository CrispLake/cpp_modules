/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:27:00 by emajuri           #+#    #+#             */
/*   Updated: 2023/06/08 13:03:04 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include <iostream>
#include "ICharacter.hpp"

Cure::Cure() {
}

Cure::Cure(const Cure& other) {
	typeStr = other.typeStr;
}

Cure&	Cure::operator=(const Cure& other) {
	if (this != &other)
		typeStr = other.typeStr;
	return (*this);
}

Cure::~Cure() {
}

AMateria*	Cure::clone() const {
	return (new Cure(*this));
}

void	Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *\n";
}
