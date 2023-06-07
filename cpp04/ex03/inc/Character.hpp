/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:38:07 by emajuri           #+#    #+#             */
/*   Updated: 2023/06/07 17:12:59 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include "ICharacter.hpp"

class Character {
	private:
		std::string	name;
		Amateria*	inventory[4];
	public:
		Character();
		Character(std::string Name);
		Character(const Character& other);
		Character&	operator=(const Character& other);
		~Character();
		std::string const&	getName() const;
		void	equip(Amateria* m);
		void	unequip(int idx);
		void	use(int idx, ICharacter& target);
};

#endif
