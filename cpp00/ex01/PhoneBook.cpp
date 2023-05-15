/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:02:56 by emajuri           #+#    #+#             */
/*   Updated: 2023/05/15 14:45:12 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

PhoneBook::PhoneBook() : current(0), empty(true) {
}

PhoneBook::~PhoneBook() {
}

std::string	PhoneBook::getNonEmptyInput(std::string s) {
}

int	PhoneBook::setContact() {
	std::string	input;
	if	(current > 7)
		current = 0;
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
	return (0);
}

void	PhoneBook::getContact(int i) {
	contacts[i].printContact();
}

int	PhoneBook::list() {
	std::cout << "\nPhonebook:\n";
	for (int i = 0; i <= 7; i++) {
		if (empty) {
			std::cout << "Phonebook is empty. Add some contacts with the ADD command\n\n";
			return (1);
		}
		if (!contacts[i].isEmpty())
			contacts[i].printLine(i);
	}
	return (0);
}

int	PhoneBook::search() {
	std::string	input;
	int	retry = 5;
	if (list())
		return (1);
	while (1) {
		if (!retry) {
			list();
			retry = 5;
		}
		std::cout << "\nGive index of the desired contact: ";
		std::getline(std::cin, input);
		if (std::cin.eof())
			return (-1);
		if (input.length() == 1 && std::isdigit(input[0])) {
			int i = std::stoi(input);
			if (i >= 0 && i <= 7 && !contacts[i].isEmpty()) {
				getContact(i);
				break;
			}
		}
		std::cout << "\nError. Incorrect index\n";
		retry--;
	}
	return (0);
}
