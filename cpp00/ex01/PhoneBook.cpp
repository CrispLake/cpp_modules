/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:02:56 by emajuri           #+#    #+#             */
/*   Updated: 2023/05/12 00:01:36 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "iostream"

PhoneBook::PhoneBook() {
	current = 0;
	empty = 1;
}

PhoneBook::~PhoneBook() {
}

void	PhoneBook::setContact() {
	std::string	input;

	empty = 0;
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
	current++;
	if	(current > 7)
		current = 0;
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
		printLine(contacts[i], i);
		i++;
	}
}

