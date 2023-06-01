/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:31:37 by emajuri           #+#    #+#             */
/*   Updated: 2023/06/01 19:14:56 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("NONE"), hp(10), ep(10), dmg(0) {
	std::cout << "Default constructor called\n";
}

ClapTrap::ClapTrap(const std::string s) : name(s), hp(10), ep(10), dmg(0) {
	std::cout << "Name constructor called\n";
}

ClapTrap::ClapTrap(const ClapTrap& x) {
	std::cout << "Copy constructor called\n";
	name = x.name;
	hp = x.hp;
	ep = x.ep;
	dmg = x.dmg;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap &x) {
	std::cout << "Copy assignment operator called\n";
	if (this != &x) {
		name = x.name;
		hp = x.hp;
		ep = x.ep;
		dmg = x.dmg;
	}
	return (*this);
}

ClapTrap::~ClapTrap() {
	std::cout << "Destructor called\n";
}

void	ClapTrap::attack(const std::string& target) {
	if (hp > 0 && ep > 0)
	{
		std::cout << "ClapTrap " << name << " attacks " << target << ", dealing " << dmg << " points of damage!\n";
		ep--;
	}
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (hp > 0 && ep > 0)
	{
		std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!\n";
		hp -= amount;
	}
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (hp > 0 && ep > 0)
	{
		hp += amount;
		std::cout << "ClapTrap " << name << " repairs, healing " << amount << " and has " << hp << "\n";
		ep--;
	}
}

std::string	ClapTrap::getName() const {
	return (name);
}

int	ClapTrap::getHp() const {
	return (hp);
}

int	ClapTrap::getEp() const {
	return (ep);
}

int	ClapTrap::getDmg() const {
	return (dmg);
}

void	ClapTrap::setName(std::string s) {
	name = s;
}

void	ClapTrap::setHp(int x) {
	hp = x;
}

void	ClapTrap::setEp(int x) {
	ep = x;
}

void	ClapTrap::setDmg(int x) {
	dmg = x;
}
