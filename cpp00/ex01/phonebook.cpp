/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:46:13 by emajuri           #+#    #+#             */
/*   Updated: 2023/05/10 19:24:30 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <cstring>
#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

void	print_size(std::string s, int size)
{
	std::string sub;
	if (s.length() > 10)
	{
		sub = s.substr(0, 9);
		std::cout << std::setw(size - 1) << std::right << sub << '.' << '|';
	}
	else
		std::cout << std::setw(size) << std::right << s << '|';
}

void	print_contact(Contact contact)
{
	std::cout << std::setw(16) << std::left << "First name: ";
	std::cout << contact.first_name << '\n';
	std::cout << std::setw(16) << std::left << "Last name: ";
	std::cout << contact.last_name << '\n';
	std::cout << std::setw(16) << std::left << "Nickname: ";
	std::cout << contact.nickname << '\n';
	std::cout << std::setw(16) << std::left << "Phone number: ";
	std::cout << contact.number << '\n';
	std::cout << std::setw(16) << std::left << "Darkest secret: ";
	std::cout << contact.secret << '\n' << '\n';
}

void	print_line(Contact contact, int i)
{
	if (contact.first_name == "")
		return;
	std::cout << '|';
	std::cout << std::setw(10) << std::right << i << '|';
	print_size(contact.first_name, 10);
	print_size(contact.last_name, 10);
	print_size(contact.nickname, 10);
	std::cout << '\n';
}

void	add_contact(Contact *contact)
{
	std::cout << "First name: ";
	std::cin >> contact->first_name;
	std::cout << "Last name: ";
	std::cin >> contact->last_name;
	std::cout << "Nickname: ";
	std::cin >> contact->nickname;
	std::cout << "Phone number: ";
	std::cin >> contact->number;
	std::cout << "Darkest secret: ";
	std::cin >> contact->secret;
}

void	list_contacts(PhoneBook phonebook)
{
	int	i;

	i = 0;
	std::cout << '\n' << "Phonebook:" << '\n';
	while (i <= 7)
	{
		if (phonebook.contacts[i].first_name == "")
			break;
		print_line(phonebook.contacts[i], i);
		i++;
	}
}

void	search_contact(PhoneBook phonebook)
{
	int	input;
	int	count;

	input = 0;
	count = 0;
	while (1)
	{
		std::cout << '\n' << "Input index of the desired contact: ";
		std::cin >> input;
		if (std::cin.eof())
			break;
		else if (!std::cin)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else if (0 <= input && input <= 7 && phonebook.contacts[input].first_name != "")
		{
			print_contact(phonebook.contacts[input]);
			break;
		}
		if (count > 5)
		{
			list_contacts(phonebook);
			count = 0;
		}
		std::cout << '\n' << "Give an index from the phonebook";
		count++;
	}
}

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
