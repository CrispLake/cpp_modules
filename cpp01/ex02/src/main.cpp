/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:29:47 by emajuri           #+#    #+#             */
/*   Updated: 2023/05/17 14:42:38 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main() {
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;

	std::cout << &string << '\n';
	std::cout << stringPTR << '\n';
	std::cout << &stringREF << '\n';
	std::cout << '\n';
	std::cout << string << '\n';
	std::cout << *stringPTR << '\n';
	std::cout << stringREF << '\n';

	return (0);
}
