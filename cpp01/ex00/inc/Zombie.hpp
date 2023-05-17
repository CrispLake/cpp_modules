/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:24:18 by emajuri           #+#    #+#             */
/*   Updated: 2023/05/17 11:52:36 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class Zombie {
private:
	std::string	name;
public:
	Zombie();
	Zombie(std::string s);
	~Zombie();
	void	announce( void );
	std::string	getName();
};
