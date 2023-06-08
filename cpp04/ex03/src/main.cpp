/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 13:12:23 by emajuri           #+#    #+#             */
/*   Updated: 2023/06/08 16:32:14 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AMateria.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "Cure.hpp"

int main() {
	Character x("x");
	AMateria* ice = new Ice();
	AMateria* ice2 = new Ice();
	x.equip(ice);
	x.equip(ice2);
	x.unequip(1);
	std::cout << "end\n";
	return (0);
}
