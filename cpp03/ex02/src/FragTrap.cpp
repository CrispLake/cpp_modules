/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 11:28:20 by emajuri           #+#    #+#             */
/*   Updated: 2023/06/02 12:01:45 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() {
	setName("None");
	setHp(100);
	setEp(100);
	setDmg(30);
	std::cout << "FragTrap default constructor\n";
};

FragTrap::FragTrap(std::string s) {
	setName(s);
	setHp(100);
	setEp(100);
	setDmg(30);
	std::cout << "FragTrap name default constructor\n";
};

FragTrap::FragTrap(const FragTrap& other) {
	std::cout << "FragTrap copy constructor\n";
	setName(other.getName());
	setHp(other.getHp());
	setEp(other.getEp());
	setDmg(other.getDmg());
}

FragTrap&	FragTrap::operator=(const FragTrap& other) {
	std::cout << "FragTrap copy assignment operator\n";
	if (this != &other) {
		setName(other.getName());
		setHp(other.getHp());
		setEp(other.getEp());
		setDmg(other.getDmg());
	}
	return (*this);
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap destructor\n";
}

void	FragTrap::highFivesGuys(void) {
	if (getHp() > 0 && getEp() > 0) {
		std::cout << "Let's celebrate with a high five!\n";
	}
}
