/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:41:45 by emajuri           #+#    #+#             */
/*   Updated: 2023/05/18 17:30:36 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug( void ) {
	std::cout << "I love having extra bacon for my "
	<< "7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n";
}

void	Harl::info( void ) {
	std::cout << "I cannot believe adding extra bacon costs more money."
	<< " You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}

void	Harl::warning( void ) {
	std::cout << "I think I deserve to have some extra bacon for free. "
	<< "I’ve been coming for years whereas you started working here since last month.\n";
}

void	Harl::error( void ) {
	std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}

typedef void (Harl::*p) ();
void	Harl::complain( std::string level ) {
	Harl x;
	p p_debug = &Harl::debug;
	p p_info = &Harl::info;
	p p_warning = &Harl::warning;
	p p_error = &Harl::error;
	level == "debug" ? (x.*p_debug) () :
	(level == "info" ? (x.*p_info) () : 
	(level == "warning" ? (x.*p_warning) () : 
	(level == "error" ? (x.*p_error) () : 
	void())));
}
