/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:29:26 by emajuri           #+#    #+#             */
/*   Updated: 2023/05/17 12:49:33 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

Zombie*	zombieHorde( int N, std::string name ) {
	Zombie	*z = new Zombie[N];
	for (int i = 0; i < N; i++)
		z[i].setName(name);
	return (z);
}
