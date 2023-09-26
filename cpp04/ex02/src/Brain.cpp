/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:05:14 by emajuri           #+#    #+#             */
/*   Updated: 2023/09/26 15:30:29 by emajuri          ###   ########.fr       */
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
	if (latest == 100)
		latest = 0;
	ideas[latest] = idea;
	latest++;
}

void	Brain::printIdeas() {
	for (int i = 0; i < 100; i++)
		if (!ideas[i].empty())
			std::cout << ideas[i] << "\n";
}
