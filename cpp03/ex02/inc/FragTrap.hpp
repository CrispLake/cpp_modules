/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 11:28:39 by emajuri           #+#    #+#             */
/*   Updated: 2023/06/02 12:01:40 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
	private:
	public:
		FragTrap();
		FragTrap(std::string s);
		FragTrap(const FragTrap& other);
		FragTrap&	operator=(const FragTrap& other);
		~FragTrap();
		void	highFivesGuys(void);
};

#endif
