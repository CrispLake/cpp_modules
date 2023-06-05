/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:05:14 by emajuri           #+#    #+#             */
/*   Updated: 2023/06/05 15:37:25 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"


Brain::Brain() {
	std::cout << "Brain constructor\n";
}

Brain::Brain(const Brain& other) {
	std::cout << "Brain copy constructor\n";
	for (int i = 0; i < 100; i++)
		ideas[i] = other.ideas[i];
	latest = other.latest;
}
Brain&	Brain::operator=(const Brain& other) {
	std::cout << "Brain copy assignment operator\n";
	if (this != &other) {
		for (int i = 0; i < 100; i++)
			ideas[i] = other.ideas[i];
		latest = other.latest;
	}
	return (*this);
}
Brain::~Brain() {
	std::cout << "Brain destructor\n";
}

void	Brain::setIdea(std::string idea) {
	ideas[latest] = idea;
	latest++;
}

void	printIdeas() {
	for (int i = 0; i < 100; i++)
		std::cout << ideas[i];
}
