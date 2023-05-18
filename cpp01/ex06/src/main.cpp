/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:41:01 by emajuri           #+#    #+#             */
/*   Updated: 2023/05/18 18:26:07 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int	main(int argc, char **argv) {
	std::string input;
	Harl	x;
	int	i = 0;
	input.clear();
	if (argc == 2)
		input = argv[1];
	input == "DEBUG" ?  i = 1 :
	(input == "INFO" ? i = 2 :
	(input == "WARNING" ? i = 3 :
	(input == "ERROR" ? i = 4 :
	i = 0)));
	switch (i) {
		case 1:
			std::cout << "[ DEBUG ]\n";
			x.complain("debug");
			std::cout << "\n";
		case 2:
			std::cout << "[ INFO ]\n";
			x.complain("info");
			std::cout << "\n";
		case 3:
			std::cout << "[ WARNING ]\n";
			x.complain("warning");
			std::cout << "\n";
		case 4:
			std::cout << "[ ERROR ]\n";
			x.complain("error");
			std::cout << "\n";
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]\n";
	}
	return (0);
}
