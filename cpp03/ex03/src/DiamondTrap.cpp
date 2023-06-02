/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 12:37:44 by emajuri           #+#    #+#             */
/*   Updated: 2023/06/02 14:02:23 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() {
	std::cout << "DiamondTrap default constructor\n";
	name = "NONE";
	setName("NONE_clap_name");
	setHp(FragTrap::getHp());
	setEp(50);
	setDmg(FragTrap::getDmg());
}

DiamondTrap::DiamondTrap(std::string s) {
	std::cout << "DiamondTrap name default constructor\n";
	name = s;
	setName(s + "_clap_name");
	setHp(FragTrap::getHp());
	setEp(50);
	setDmg(FragTrap::getDmg());
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) {
	std::cout << "DiamondTrap copy constructor\n";
	name = other.name;
	setName(getName());
	setHp(getHp());
	setEp(getEp());
	setDmg(getDmg());
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& other) {
	std::cout << "DiamondTrap copy assigment operator\n";
	if (this == &other) {
		name = other.name;
		setName(getName());
		setHp(getHp());
		setEp(getEp());
		setDmg(getDmg());
	}
	return (*this);
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap destructor\n";
}

void	DiamondTrap::attack(std::string target) {
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI() {
	std::cout << "I am " << name << " (" << getName() << ")\n";
}

int	DiamondTrap::getEp() {
	return(ScavTrap::getEp());
}
