/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:11:49 by emajuri           #+#    #+#             */
/*   Updated: 2023/06/07 16:23:57 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "Amateria.hpp"

class Ice : public Amateria {
	public:
		Ice();
		Ice(const Ice& other);
		Ice&	operator=(const Ice& other);
		~Ice();

		Amateria*	clone() const;
		void	use(ICharacter& target) const;
};

#endif
