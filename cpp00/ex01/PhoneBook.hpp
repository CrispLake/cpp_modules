/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:44:48 by emajuri           #+#    #+#             */
/*   Updated: 2023/05/11 23:34:43 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
	private:
		Contact	contacts[8];
		int	current;
		int	empty;
	public:
		PhoneBook();
		void	setContact();
		void	list();
		void	getContact(Contact contact, int i);
		~PhoneBook();
};

#endif
