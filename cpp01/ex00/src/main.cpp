/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:29:47 by emajuri           #+#    #+#             */
/*   Updated: 2023/05/17 12:06:27 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

int	main() {
	Zombie z;
	Zombie *y = newZombie("y");
	z.announce();
	y->announce();
	randomChump("x");
	delete y;
	return (0);
}
