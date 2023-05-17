/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:48:51 by emajuri           #+#    #+#             */
/*   Updated: 2023/05/17 19:24:31 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon {
	private:
		std::string	_type;
	public:
		Weapon(std::string type);
		~Weapon();
		std::string	getType();
		void	setType(std::string type);
};

#endif
