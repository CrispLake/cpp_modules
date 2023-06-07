/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:25:49 by emajuri           #+#    #+#             */
/*   Updated: 2023/06/07 16:26:43 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CURE_HPP
#define CURE_HPP

#include "Amateria.hpp"

class Cure : public Amateria {
	public:
		Cure();
		Cure(const Cure& other);
		Cure&	operator=(const Cure& other);
		~Cure();

		Amateria*	clone() const;
		void	use(ICharacter& target) const;
};

#endif
