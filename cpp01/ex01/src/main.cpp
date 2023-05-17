/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:29:47 by emajuri           #+#    #+#             */
/*   Updated: 2023/05/17 18:10:12 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
Zombie*	zombieHorde( int N, std::string name );

int	main() {
	int	s = 5;
	Zombie *z = zombieHorde(s, "z");
	Zombie *x = zombieHorde(s, "x");
	for (int i = 0; i < s; i++)
		z[i].announce();
	for (int i = 0; i < s; i++)
		x[i].announce();
	delete[] z;
	delete[] x;
	return (0);
}
