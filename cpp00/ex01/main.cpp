/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:46:13 by emajuri           #+#    #+#             */
/*   Updated: 2023/05/15 18:33:49 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"


int	main() {
	int	cur;
	PhoneBook phonebook;
	std::string input;

	std::cout << "Phonebook is empty\n";
	cur = 0;
	while (1) {
		if (std::cin.eof()) {
			std::cout << '\n';
			break;
		}
		std::cout << "Use the following commands to modify/search the phonebook or exit the program:\n" << "ADD\n" << "SEARCH\n" << "EXIT\n";
		std::getline(std::cin, input);
		if (std::cin.eof())
			break;
		if (input == "ADD")
			phonebook.setContact();
		else if (input == "SEARCH")
			phonebook.search();
		else if (input == "EXIT")
			break;
		else
			std::cout << '\n' << input << " is incorrect command. Try again" << '\n';
	}
	return (0);
}
