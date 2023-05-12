/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:46:13 by emajuri           #+#    #+#             */
/*   Updated: 2023/05/12 16:46:40 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"


int	main(void)
{
	int	cur;
	PhoneBook phonebook;
	std::string input;

	std::cout << "Phonebook is empty\n";
	cur = 0;
	while (1)
	{
		std::cout << "Use the following commands to modify/search the phonebook or exit the program:\n" << "ADD\n" << "SEARCH\n" << "EXIT\n";
		std::cin >> input;
		if (std::cin.eof())
			break;
		if (input == "ADD")
		{
			if (cur == 7)
				cur = 0;
			add_contact(&phonebook.contacts[cur]);
			cur++;
		}
		else if (input == "SEARCH")
		{
			if (phonebook.contacts[0].first_name == "")
			{
				std::cout << '\n' << "Phonebook is empty. Add contacts with the ADD command\n";
				continue;
			}
			list_contacts(phonebook);
			search_contact(phonebook);
		}
		else if (input == "EXIT" || input == "")
			break;
		else
			std::cout << '\n' << input << " is incorrect command. Try again" << '\n';
	}
}
