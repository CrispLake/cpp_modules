/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:02:31 by emajuri           #+#    #+#             */
/*   Updated: 2023/11/07 17:01:14 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

int main(int argc, char const *argv[])
{
    RPN calculator;

    if (argc != 2)
    {
        std::cout << "Error: Invalid amount of arguments\n";
        return (1);
    }
    calculator.calculate(argv[1]);
    return (0);
}
