/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:28:18 by emajuri           #+#    #+#             */
/*   Updated: 2023/10/19 14:38:49 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    Span y(6);

    try
    {
        std::cout << y.shortestSpan() << "\n";
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    y.addNumber(1);
    try
    {
        std::cout << y.longestSpan() << "\n";
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    y.addNumber(5);
    y.addNumber(3);
    y.addNumber(2);
    y.addNumber(4);
    y.addNumber(6);

    std::cout << y.shortestSpan() << "\n";
    std::cout << y.longestSpan() << "\n";

    Span x(20000);
    std::vector<int> z;
    z.resize(20001);
    std::srand(std::time(NULL));

    std::generate(z.begin(), z.end(), std::rand);
    try
    {
        x.addRange(z.begin(), z.end());
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    std::cout << x.longestSpan() << "\n";
    std::cout << x.shortestSpan() << "\n";
}