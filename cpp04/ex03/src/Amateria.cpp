/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Amateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 13:12:12 by emajuri           #+#    #+#             */
/*   Updated: 2023/06/07 15:38:36 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Amateria.hpp"

Amateria::Amateria() : typeStr("empty") {
}

Amateria::Amateria(std::string const& type) : typeStr(type) {
}

Amateria::Amateria(const Amateria& other) {
	typeStr = other.typeStr;
}

Amateria&	Amateria::operator=(const Amateria& other) {
	if (this != &other) {
		typeStr = other.typeStr;
	}
	return (*this);
}

Amateria::~Amateria() {
}

std::string const&	Amateria::getType() const {
	return (typeStr);
}
