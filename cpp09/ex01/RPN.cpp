/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:02:52 by emajuri           #+#    #+#             */
/*   Updated: 2023/11/28 12:05:48 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <string>
#include <iostream>

RPN::RPN()
{}

RPN::RPN(RPN const& ref)
{
    numbers = ref.numbers;
}

RPN&    RPN::operator=(RPN const& ref)
{
    if (this != &ref)
        numbers = ref.numbers;
    return (*this);
}

RPN::~RPN()
{}

bool    RPN::validate(std::string calc) const
{
    std::string const   AllowedChars = "+-/* 1234567890";
    if (calc.find_first_not_of(AllowedChars) != std::string::npos)
        return (false);
    for (std::string::iterator it = calc.begin(); it != calc.end(); it++)
    {
        if (*it == ' ')
            continue;
        if (it + 1 != calc.end() && *(it + 1) != ' ')
            return (false);
    }
    return (true);
}

int RPN::getTop()
{
    int top = numbers.top();
    numbers.pop();
    return (top);
}

void    RPN::calculate(std::string calc)
{
    if (!validate(calc))
    {
        std::cout << "Error: Invalid calculation\n";
        return;
    }
    for (std::string::iterator it = calc.begin(); it != calc.end(); it++)
    {
        if (*it == ' ')
            continue;
        if (std::isdigit(*it))
        {
            numbers.push(*it - '0');
            continue;
        }
        int nb1 = getTop();
        if (numbers.empty())
        {
            std::cout << "Error: Too many symbols\n";
            return;
        }
        int nb2 = getTop();
        if (*it == '+')
            numbers.push(nb2 + nb1);
        if (*it == '-')
            numbers.push(nb2 - nb1);
        if (*it == '/')
        {
            if (nb1 == 0)
            {
                std::cout << "Error: Cannot do division by zero\n";
                return;
            }
            numbers.push(nb2 / nb1);
        }
        if (*it == '*')
            numbers.push(nb2 * nb1);
    }
    if (numbers.size() != 1)
    {
        std::cout << "Error: Too little symbols\n";
        return;
    }
    std::cout << numbers.top() << "\n";
}