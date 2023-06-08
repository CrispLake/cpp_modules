/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 13:12:12 by emajuri           #+#    #+#             */
/*   Updated: 2023/06/08 13:00:18 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

AMateria::AMateria() : typeStr("empty") {
}

AMateria::AMateria(std::string const& type) : typeStr(type) {
}

AMateria::AMateria(const AMateria& other) {
	typeStr = other.typeStr;
}

AMateria&	AMateria::operator=(const AMateria& other) {
	if (this != &other) {
		typeStr = other.typeStr;
	}
	return (*this);
}

AMateria::~AMateria() {
}

std::string const&	AMateria::getType() const {
	return (typeStr);
}

void	AMateria::use(ICharacter& target) {
	std::cout << target.getName() << " Error\n";
}
