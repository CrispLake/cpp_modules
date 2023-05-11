/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:36:26 by emajuri           #+#    #+#             */
/*   Updated: 2023/05/11 23:58:40 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "iomanip"
#include "iostream"
#include <string>

Contact::Contact() {
};

Contact::~Contact() {
};

void	Contact::setFirst(std::string first) {
	first_name = first;
}

void	Contact::setLast(std::string last) {
	last_name = last;
}

void	Contact::setNick(std::string nick) {
	nickname = nick;
}

void	Contact::setNbr(std::string nb) {
	number = nb;
}

void	Contact::setSecret(std::string secret) {
	dark_secret = secret;
}

void	Contact::printValue(std::string value) {
	if (value.length() > 10)
		std::cout << std::setw(10) << std::right << value.substr(0, 9) << '.' << '|';
	else
		std::cout << std::setw(10) << std::right << value << '|';
}

void	Contact::printLine(Contact contact, int i)
{
	std::cout << '|';
	printValue(std::to_string(i));
	printValue(contact.first_name);
	printValue(contact.last_name);
	printValue(contact.nickname);
	std::cout << '\n';
}
