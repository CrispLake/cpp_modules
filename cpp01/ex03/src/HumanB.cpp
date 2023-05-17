/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 19:02:22 by emajuri           #+#    #+#             */
/*   Updated: 2023/05/17 20:06:16 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name) : _name(name) {
}

HumanB::~HumanB() {
}

void	HumanB::attack() {
	std::cout << _name + " attacks with their " + _weapon->getType() << '\n';
}

void	HumanB::setWeapon(Weapon &weapon) {
	_weapon = &weapon;
}
