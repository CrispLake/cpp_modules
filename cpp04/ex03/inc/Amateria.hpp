/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 13:01:24 by emajuri           #+#    #+#             */
/*   Updated: 2023/06/08 19:21:54 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
class ICharacter;

class AMateria {
	public:
		AMateria();
		AMateria(const AMateria& other);
		AMateria&	operator=(const AMateria& other);
		virtual ~AMateria();

		AMateria(std::string const& type);

		std::string const& getType() const;

		virtual AMateria*	clone() const = 0;
		virtual void	use(ICharacter& target);

	protected:
		std::string	typeStr;
};

#endif
