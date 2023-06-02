/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 17:09:35 by emajuri           #+#    #+#             */
/*   Updated: 2023/06/02 12:23:33 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap {
	private:
	public:
		ScavTrap();
		ScavTrap(std::string s);
		ScavTrap(const ScavTrap& x);
		ScavTrap& operator=(const ScavTrap& x);
		~ScavTrap();
		void	attack(const std::string& target);
		void	guardGate();
};

#endif
