/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:01:33 by emajuri           #+#    #+#             */
/*   Updated: 2023/10/17 13:58:50 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

int main()
{
    Array<int> x(10);
    try
    {
        std::cout << x.size() << "\n";
        for (int i = 0; i < 10; i++)
            std::cout << x[i] << " ";
        std::cout << "\n";
        x[5] = 222;
        for (int i = 0; i < 10; i++)
            std::cout << x[i] << " ";
        std::cout << "\n";
        std::cout << x[50] << "\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        x[-5];
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);
}
