/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:02:56 by emajuri           #+#    #+#             */
/*   Updated: 2023/05/12 17:06:42 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <cctype>
#include <string>

PhoneBook::PhoneBook() {
}

PhoneBook::~PhoneBook() {
}

int	PhoneBook::setContact() {
	std::string	input;

	empty = false;
	std::cout << "First name: ";
	std::getline(std::cin, input);
	contacts[current].setFirst(input);
	std::cout << "Last name: ";
	std::getline(std::cin, input);
	contacts[current].setLast(input);
	std::cout << "Nickname: ";
	std::getline(std::cin, input);
	contacts[current].setNick(input);
	std::cout << "Phone number: ";
	std::getline(std::cin, input);
	contacts[current].setNbr(input);
	std::cout << "Darkest secret: ";
	std::getline(std::cin, input);
	contacts[current].setSecret(input);
	if (std::cin.eof())
		return (-1);
	current++;
	if	(current > 7)
		current = 0;
	return (0);
}

void	PhoneBook::getContact(int i) {
	contacts[i].printContact();
}

void	PhoneBook::list() {
	int	i;

	i = 0;
	std::cout << "\nPhonebook:\n";
	while (i <= 7)
	{
		if (empty)
		{
			std::cout << "Phonebook is empty. Add some contacts with the ADD command\n\n";
			break;
		}
		contacts[i].printLine(i);
		i++;
	}
}

int	PhoneBook::searchPhoneBook() {
	std::string	input;
	int	index;
	list();
	std::cout << "\nGive index of the desired contact: ";
	std::getline(std::cin, input);
	if (std::cin.eof())
		return (-1);
	if (input.length() > 1 && std::isdigit(input[0]))
		std::cout << "\nGive index from the PhoneBook\n";
	else
		index = std::stoi(input);
	return (0);
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
		if
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
