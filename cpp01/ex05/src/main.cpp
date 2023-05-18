/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:41:01 by emajuri           #+#    #+#             */
/*   Updated: 2023/05/18 17:30:19 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int	main() {
	Harl	x;
	x.complain("debug");
	std::cout << "\n";
	x.complain("info");
	std::cout << "\n";
	x.complain("warning");
	x.complain("warning");
	std::cout << "\n";
	x.complain("error");
	x.complain("error");
	x.complain("error");
	x.complain("error");
	return (0);
}
