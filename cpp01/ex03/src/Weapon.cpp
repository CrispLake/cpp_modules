/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:48:55 by emajuri           #+#    #+#             */
/*   Updated: 2023/05/17 20:10:49 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) {
	_type = type;
}

Weapon::~Weapon() {
}

std::string	Weapon::getType() {
	return (_type);
}

void	Weapon::setType(std::string type) {
	_type = type;
}
