/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:42:14 by emajuri           #+#    #+#             */
/*   Updated: 2023/06/20 13:27:36 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

Character::Character() : name("Unnamed"), trash(NULL) {
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

Character::Character(const std::string Name) : name(Name), trash(NULL) {
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

Character::Character(const Character& other) : trash(NULL) {
	name = other.name;
	for (int i = 0; i < 4; i++) {
		if (other.inventory[i])
			inventory[i] = other.inventory[i]->clone();
	}
}

Character&	Character::operator=(const Character& other) {
	if (this != &other) {
		name = other.name;
		for (int i = 0; i < 4; i++) {
			if (inventory[i]) {
				delete inventory[i];
			}
			if (other.inventory[i])
				inventory[i] = other.inventory[i]->clone();
			else
				inventory[i] = NULL;

		}
		if (trash != NULL) {
			delete trash;
		}
		trash = NULL;
	}
	return (*this);
}

Character::~Character() {
	for (int i = 0; i < 4; i++) {
		if (inventory[i] != NULL) {
			delete inventory[i];
		}
	}
	if (trash != NULL)
		delete trash;
}

std::string const&	Character::getName() const {
	return (name);
}

void	Character::equip(AMateria* m) {
	for (int i = 0; i < 4; i++) {
		if (inventory[i] == NULL) {
			inventory[i] = m;
			break;
		}
	}
}

void	Character::unequip(int idx) {
	if (idx < 4 && idx > -1 && inventory[idx] != NULL) {
		if (trash == NULL)
			trash = new TrashCan(inventory[idx]);
		else
			trash->push(inventory[idx]);
		inventory[idx] = NULL;
	}
}

void	Character::use(int idx, ICharacter& target) {
	if (idx < 4 && idx > -1 && inventory[idx] != NULL)
		inventory[idx]->use(target);
}
