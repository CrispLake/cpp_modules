/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TrashCan.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:57:46 by emajuri           #+#    #+#             */
/*   Updated: 2023/06/08 17:37:24 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TrashCan.hpp"

TrashCan::TrashCan() : next(nullptr), materia(nullptr) {
}

TrashCan::TrashCan(AMateria* m) : next(nullptr), materia(m) {
}

TrashCan::TrashCan(const TrashCan& other) {
	next = other.next;
	materia = other.materia;
}

TrashCan&	TrashCan::operator=(const TrashCan& other) {
	if (this != other) {
		next = other.next;
		materia = other.materia;
	}
	return (*this);
}

TrashCan::~TrashCan() {
	if (materia != nullptr)
		delete materia;
	if (next != nullptr)
		delete next;
}

void	TrashCan::push(AMateria* m) {
	TrashCan* tmp = this;
	while (tmp->next != nullptr)
		tmp = tmp->next;
	tmp->next = new TrashCan(m);
}
