/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:22:55 by emajuri           #+#    #+#             */
/*   Updated: 2023/06/01 14:39:04 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main() {
	ClapTrap x("x");
	ClapTrap y("y");

	x.attack("y");
	y.takeDamage(0);
	y.beRepaired(1);
	y.beRepaired(0);
	y.beRepaired(0);
	y.beRepaired(0);
	y.beRepaired(0);
	y.beRepaired(0);
	y.beRepaired(0);
	y.beRepaired(0);
	y.beRepaired(0);
	y.beRepaired(0);
	y.attack("x");
	std::cout << "x falls of a cliff\n";
	x.takeDamage(10);
	x.beRepaired(1);
	x.takeDamage(0);
}
