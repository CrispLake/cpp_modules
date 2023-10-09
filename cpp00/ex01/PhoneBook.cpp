/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:02:56 by emajuri           #+#    #+#             */
/*   Updated: 2023/10/09 15:57:05 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

PhoneBook::PhoneBook() : current(0), empty(true) {
}

PhoneBook::~PhoneBook() {
}

std::string	PhoneBook::getNonEmptyInput(std::string s) {
	std::string	input;
	while(std::cout << s && std::getline(std::cin, input) && input.empty())
		std::cout << "Error. Can't accept empty field\n";
	if (!std::cin)
		input.clear();
	return (input);
}

int	PhoneBook::setContact() {
	std::string	input;
	if	(current > 7)
		current = 0;
	empty = false;
	input = getNonEmptyInput("First name: ");
	if (input.empty())
		return (-1);
	contacts[current].setFirst(input);
	input = getNonEmptyInput("Last name: ");
	if (input.empty())
		return (-1);
	contacts[current].setLast(input);
	input = getNonEmptyInput("Nickname: ");
	if (input.empty())
		return (-1);
	contacts[current].setNick(input);
	input = getNonEmptyInput("Phone number: ");
	if (input.empty())
		return (-1);
	contacts[current].setNbr(input);
	input = getNonEmptyInput("Darkest secret: ");
	if (input.empty())
		return (-1);
	contacts[current].setSecret(input);
	current++;
	return (0);
}

void	PhoneBook::getContact(int i) {
	contacts[i].printContact();
}

int	PhoneBook::list() {
	if (empty) {
		std::cout << "Phonebook is empty. Add some contacts with the ADD command\n\n";
		return (1);
	}
	std::cout << "\nPhonebook:\n";
	std::cout << '|' << std::setw(10) << std::right << "Index" << '|';
	std::cout << std::setw(10) << std::right << "First name" << '|';
	std::cout << std::setw(10) << std::right << "Last name" << '|';
	std::cout << std::setw(10) << std::right << "Nickname" << "|\n";
	for (int i = 0; i <= 7; i++) {
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
