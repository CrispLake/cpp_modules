/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 19:01:02 by emajuri           #+#    #+#             */
/*   Updated: 2023/06/01 21:01:40 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
	std::cout << "ScavTrap constructor called\n";
	setName("NONE");
	setHp(100);
	setEp(50);
	setDmg(20);
}

ScavTrap::ScavTrap(std::string s) {
	std::cout << "ScavTrap name constructor called\n";
	setName(s);
	setHp(100);
	setEp(50);
	setDmg(20);
}

ScavTrap::ScavTrap(const ScavTrap& x) {
	std::cout << "ScavTrap copy constructor called\n";
	setName(x.getName());
	setHp(x.getHp());
	setEp(x.getEp());
	setDmg(x.getDmg());
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& x) {
	std::cout << "ScavTrap copy assignment operator called\n";
	if (this != &x) {
		setName(x.getName());
		setHp(x.getHp());
		setEp(x.getEp());
		setDmg(x.getDmg());
	}
	return (*this);
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor called\n";
}

void	ScavTrap::attack(const std::string& target)
{
	if (getHp() > 0 && getEp() > 0) {
		std::cout << "ScavTrap " << getName() << " attacks " << target << ", dealing " << getDmg() << " points of damage!\n";
		setEp(getEp() - 1);
	}
}

void	ScavTrap::guardGate() {
	if (getHp() > 0 && getEp() > 0) {
		std::cout << "ScavTrap " << getName() << " is now in gate keeper mode\n";
	}
}
