/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:22:55 by emajuri           #+#    #+#             */
/*   Updated: 2023/06/01 21:05:06 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

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


	std::cout << "\nScavTraps\n\n";
	x = ClapTrap("x");
	y = ClapTrap("y");
	ScavTrap scav1("Scav1");
	scav1.attack("x");
	x.takeDamage(20);
	x.attack("scav1");
	scav1.guardGate();
	for (int i = 0; i < 50; i++)
		scav1.beRepaired(1);
	scav1.attack("y");
	ScavTrap scav2("Scav2");
	std::cout << "scav2 drowns\n";
	scav2.takeDamage(100);
	scav2.beRepaired(50);
}
