/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:36:26 by emajuri           #+#    #+#             */
/*   Updated: 2023/05/11 19:47:00 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

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
