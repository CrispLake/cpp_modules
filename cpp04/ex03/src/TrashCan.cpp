/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TrashCan.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:57:46 by emajuri           #+#    #+#             */
/*   Updated: 2023/06/20 13:28:26 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TrashCan.hpp"

TrashCan::TrashCan() : next(NULL), materia(NULL) {
}

TrashCan::TrashCan(AMateria* m) : next(NULL), materia(m) {
}

TrashCan::TrashCan(const TrashCan& other) {
	next = other.next;
	materia = other.materia;
}

TrashCan&	TrashCan::operator=(const TrashCan& other) {
	if (this != &other) {
		next = other.next;
		materia = other.materia;
	}
	return (*this);
}

TrashCan::~TrashCan() {
	if (materia != NULL)
		delete materia;
	if (next != NULL)
		delete next;
}

void	TrashCan::push(AMateria* m) {
	TrashCan* tmp = this;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new TrashCan(m);
}
