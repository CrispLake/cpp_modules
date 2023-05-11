/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:31:49 by emajuri           #+#    #+#             */
/*   Updated: 2023/05/11 23:54:23 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact {
	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string number;
		std::string dark_secret;
	public:
		Contact();
		void	setFirst(std::string first);
		void	setLast(std::string last);
		void	setNick(std::string nick);
		void	setNbr(std::string nb);
		void	setSecret(std::string secret);
		void	printValue(std::string value);
		void	printLine(Contact contact, int i);
		~Contact();
};

#endif
