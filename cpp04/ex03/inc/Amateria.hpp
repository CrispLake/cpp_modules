/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Amateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 13:01:24 by emajuri           #+#    #+#             */
/*   Updated: 2023/06/08 12:27:17 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
class ICharacter;

class Amateria {
	protected:
		std::string	typeStr;

	public:
		Amateria();
		Amateria(const Amateria& other);
		Amateria&	operator=(const Amateria& other);
		virtual ~Amateria();

		Amateria(std::string const& type);

		std::string const& getType() const;

		virtual Amateria*	clone() const = 0;
		virtual void	use(ICharacter& target);
};

#endif
