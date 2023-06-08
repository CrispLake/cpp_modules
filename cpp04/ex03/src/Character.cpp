/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:42:14 by emajuri           #+#    #+#             */
/*   Updated: 2023/06/08 19:26:18 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

Character::Character() : name("Unnamed"), trash(nullptr) {
	for (int i = 0; i < 4; i++)
		inventory[i] = nullptr;
}

Character::Character(const std::string Name) : name(Name), trash(nullptr) {
	for (int i = 0; i < 4; i++)
		inventory[i] = nullptr;
}

Character::Character(const Character& other) : trash(nullptr) {
	name = other.name;
	for (int i = 0; i < 4; i++) {
		if (other.inventory[i])
			this->inventory[i] = other.inventory[i]->clone();
	}
}

Character&	Character::operator=(const Character& other) {
	if (this != &other) {
		name = other.name;
		for (int i = 0; i < 4; i++) {
			if (this->inventory[i]) {
				delete this->inventory[i];
			}
			if (other.inventory[i])
				this->inventory[i] = other.inventory[i]->clone();
			else
				this->inventory[i] = nullptr;

		}
		if (this->trash != nullptr) {
			delete this->trash;
		}
		this->trash = nullptr;
	}
	return (*this);
}

Character::~Character() {
	for (int i = 0; i < 4; i++) {
		if (inventory[i] != nullptr) {
			delete inventory[i];
		}
	}
	if (this->trash != nullptr)
		delete this->trash;
}

std::string const&	Character::getName() const {
	return (name);
}

void	Character::equip(AMateria* m) {
	for (int i = 0; i < 4; i++) {
		if (inventory[i] == nullptr) {
			inventory[i] = m;
			break;
		}
	}
}

void	Character::unequip(int idx) {
	if (idx < 4 && idx > -1 && inventory[idx] != nullptr) {
		if (trash == nullptr)
			trash = new TrashCan(inventory[idx]);
		else
			trash->push(inventory[idx]);
		inventory[idx] = nullptr;
	}
}

void	Character::use(int idx, ICharacter& target) {
	if (idx < 4 && idx > -1 && inventory[idx] != nullptr)
		inventory[idx]->use(target);
}
