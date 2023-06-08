/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:38:07 by emajuri           #+#    #+#             */
/*   Updated: 2023/06/08 18:07:52 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include "ICharacter.hpp"
#include "TrashCan.hpp"

class Character : public ICharacter {
	public:
		Character();
		Character(std::string Name);
		Character(const Character& other);
		Character&	operator=(const Character& other);
		~Character();

		std::string const&	getName() const;

		void	equip(AMateria* m);
		void	unequip(int idx);
		void	use(int idx, ICharacter& target);

	private:
		std::string	name;
		AMateria*	inventory[4];
		TrashCan*	trash;
};

#endif
