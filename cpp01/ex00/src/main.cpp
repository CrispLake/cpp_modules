/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:29:47 by emajuri           #+#    #+#             */
/*   Updated: 2023/05/17 18:03:18 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Zombie.hpp"

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );

int	main() {
	Zombie z;
	Zombie *y = newZombie("y");
	z.announce();
	y->announce();
	randomChump("x");
	delete y;
	return (0);
}
