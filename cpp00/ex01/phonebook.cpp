/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:02:56 by emajuri           #+#    #+#             */
/*   Updated: 2023/05/11 19:56:20 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "iostream"

PhoneBook::PhoneBook() {
	current = 0;
}

PhoneBook::~PhoneBook() {
}

void	PhoneBook::addContact() {
	std::string	input;

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
}

void	PhoneBook::list() {
	int	i;

	i = 0;
	std::cout << '\n' << "Phonebook:" << '\n';
	while (i <= 7)
	{
		if (contacts[i].first_name == "")
			break;
		print_line(phonebook.contacts[i], i);
		i++;
	}
}

