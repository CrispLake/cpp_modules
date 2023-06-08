/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 13:12:23 by emajuri           #+#    #+#             */
/*   Updated: 2023/06/08 16:04:15 by emajuri          ###   ########.fr       */
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
	x.equip(ice);
	std::cout << "end\n";
	delete ice;
	return (0);
}
