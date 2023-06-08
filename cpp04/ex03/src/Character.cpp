/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:42:14 by emajuri           #+#    #+#             */
/*   Updated: 2023/06/08 16:13:31 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

Character::Character() : name("Unnamed") {
	for (int i = 0; i < 4; i++)
		inventory[i] = nullptr;
}

Character::Character(const std::string Name) : name(Name) {
	for (int i = 0; i < 4; i++)
		inventory[i] = nullptr;
}

Character::Character(const Character& other) {
	name = other.name;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = other.inventory[i]->clone();
}

Character&	Character::operator=(const Character& other) {
	if (this != &other) {
		name = other.name;
		for (int i = 0; i < 4; i++) {
			if (this->inventory[i]) {
				delete this->inventory[i];
			}
			this->inventory[i] = other.inventory[i]->clone();
		}
	}
	return (*this);
}

Character::~Character() {
	for (int i = 0; i < 4; i++) {
		if (inventory[i] != nullptr) {
			delete inventory[i];
		}
	}
}

std::string const&	Character::getName() const {
	return (name);
}

void	Character::equip(AMateria* m) {
	for (int i = 0; i < 4; i++) {
		if (inventory[i] == nullptr)
			inventory[i] = m;
	}
}
