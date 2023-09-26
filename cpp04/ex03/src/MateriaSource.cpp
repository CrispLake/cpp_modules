/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 18:31:48 by emajuri           #+#    #+#             */
/*   Updated: 2023/06/20 13:28:09 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++)
		inv[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other) {
	for (int i = 0; i < 4; i++) {
		if (other.inv[i])
			this->inv[i] = other.inv[i]->clone();
		else
			this->inv[i] = NULL;
	}
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& other) {
	if (this != &other) {
		for (int i = 0; i < 4; i++) {
			if (this->inv[i]) {
				delete this->inv[i];
			}
			if (other.inv[i])
				this->inv[i] = other.inv[i]->clone();
			else
				this->inv[i] = NULL;
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++) {
		if (inv[i] != NULL) {
			delete inv[i];
		}
	}
}

void	MateriaSource::learnMateria(AMateria* m) {
	for (int i = 0; i < 4; i++) {
		if (inv[i] == NULL) {
			inv[i] = m;
			break;
		}
	}
}

AMateria*	MateriaSource::createMateria(std::string const& type) {
	for (int i = 0; i < 4; i++) {
		if (inv[i] != NULL && inv[i]->getType() == type) {
			return (inv[i]->clone());
		}
	}
	return (0);
}
