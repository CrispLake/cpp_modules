/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TrashCan.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:45:26 by emajuri           #+#    #+#             */
/*   Updated: 2023/06/08 17:31:13 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRASHCAN_HPP
#define TRASHCAN_HPP

#include "AMateria.hpp"

class TrashCan {
	public:
		TrashCan();
		TrashCan(AMateria* m);
		TrashCan(const TrashCan& other);
		TrashCan&	operator=(const TrashCan& other);
		~TrashCan();

		void	push(AMateria* m);

	private:
		TrashCan*	next;
		AMateria*	materia;
};

#endif
