/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:44:48 by emajuri           #+#    #+#             */
/*   Updated: 2023/05/12 16:50:51 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
	private:
		Contact	contacts[8];
		int	current = 0;
		bool	empty = true;
		void	getContact(int i);
	public:
		PhoneBook();
		int	setContact();
		void	list();
		int	searchPhoneBook();
		~PhoneBook();
};

#endif
