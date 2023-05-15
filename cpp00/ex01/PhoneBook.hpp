/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:44:48 by emajuri           #+#    #+#             */
/*   Updated: 2023/05/15 14:45:25 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
	private:
		Contact	contacts[8];
		int	current;
		bool	empty;
		void	getContact(int i);
		std::string	getNonEmptyInput(std::string s);
	public:
		PhoneBook();
		int	setContact();
		int	list();
		int	search();
		~PhoneBook();
};

#endif
