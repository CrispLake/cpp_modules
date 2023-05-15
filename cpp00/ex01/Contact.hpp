/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:31:49 by emajuri           #+#    #+#             */
/*   Updated: 2023/05/15 14:16:40 by emajuri          ###   ########.fr       */
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
		bool	empty;
		void	printValue(std::string value);
	public:
		Contact();
		void	setFirst(std::string first);
		void	setLast(std::string last);
		void	setNick(std::string nick);
		void	setNbr(std::string nb);
		void	setSecret(std::string secret);
		void	setValue(std::string variable, std::string value);
		void	printLine(int i);
		void	printContact();
		bool	isEmpty();
		~Contact();
};

#endif
