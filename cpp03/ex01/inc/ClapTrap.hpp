/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:24:07 by emajuri           #+#    #+#             */
/*   Updated: 2023/06/01 19:13:34 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
	private:
		std::string	name;
		int	hp;
		int	ep;
		int	dmg;
	protected:
		std::string	getName() const;
		int	getHp() const;
		int	getEp() const;
		int	getDmg() const;
		void	setName(std::string s);
		void	setHp(int x);
		void	setEp(int x);
		void	setDmg(int x);
	public:
		ClapTrap();
		ClapTrap(const std::string s);
		ClapTrap(const ClapTrap& x);
		ClapTrap& operator=(const ClapTrap& x);
		~ClapTrap();
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif
