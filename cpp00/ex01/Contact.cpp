/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:36:26 by emajuri           #+#    #+#             */
/*   Updated: 2023/05/15 14:35:03 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

Contact::Contact() : empty(true){
};

Contact::~Contact() {
};

void	Contact::setFirst(std::string first) {
	first_name = first;
	empty = false;
}

void	Contact::setLast(std::string last) {
	last_name = last;
	empty = false;
}

void	Contact::setNick(std::string nick) {
	nickname = nick;
	empty = false;
}

void	Contact::setNbr(std::string nb) {
	number = nb;
	empty = false;
}

void	Contact::setSecret(std::string secret) {
	dark_secret = secret;
	empty = false;
}

void	Contact::printContact() {
	std::cout << std::setw(16) << std::left << "First name: ";
	std::cout << first_name << '\n';
	std::cout << std::setw(16) << std::left << "Last name: ";
	std::cout << last_name << '\n';
	std::cout << std::setw(16) << std::left << "Nickname: ";
	std::cout << nickname << '\n';
	std::cout << std::setw(16) << std::left << "Phone number: ";
	std::cout << number << '\n';
	std::cout << std::setw(16) << std::left << "Darkest secret: ";
	std::cout << dark_secret << '\n' << '\n';
}

void	Contact::printValue(std::string value) {
	if (value.length() > 10) {
		std::cout << std::setw(10) << std::right << value.substr(0, 9) + '.';
		std::cout << '|';
	}
	else {
		std::cout << std::setw(10) << std::right << value;
		std::cout << '|';
	}
}

void	Contact::printLine(int i) {
	std::cout << '|';
	printValue(std::to_string(i));
	printValue(first_name);
	printValue(last_name);
	printValue(nickname);
	std::cout << '\n';
}

bool	Contact::isEmpty() {
	return (empty);
}
