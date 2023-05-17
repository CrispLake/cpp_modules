/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:25:56 by emajuri           #+#    #+#             */
/*   Updated: 2023/05/17 11:59:12 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() : name("Unnamed") {
}

Zombie::Zombie(std::string s) : name(s) {
}

Zombie::~Zombie() {
	std::cout << name << " got destroyed\n";
}

void	Zombie::announce( void ) {
	std::cout << name << ": BraiiiiiiinnnzzzZ\n";
}

std::string	Zombie::getName() {
	return (name);
}
