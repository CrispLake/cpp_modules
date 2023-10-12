/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:19:35 by emajuri           #+#    #+#             */
/*   Updated: 2023/10/12 15:27:53 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <string>
#include <limits>
#include <exception>
#include <sstream>
#include <cctype>

enum type
{
    NONE,
    CHAR,
    INT,
    FLOAT,
    DOUBLE
};

static type analyze(std::string const& str)
{
    int    len = str.length();
    if (len == 1)
    {
        if (std::isdigit(str[0]))
            return (INT);
        if (!std::isprint(str[0]) || str[0] == ' ')
            return (NONE);
        return (CHAR);
    }
    if (str == "-inff" || str == "+inff" || str == "nanf")
        return (FLOAT);
    if (str == "-inf" || str == "+inf" || str == "nan")
        return (DOUBLE);
    if (!std::isdigit(str[0]))
        if (str[0] != '+' || str[0] != '-')
            return (NONE);
    for (int i = 1; i < len; i++)
    {
        if (str[i] == '.')
        {
            for (int j = i + 1; j < len; j++)
            {
                if (j == len - 1 && str[j] == 'f')
                    return (FLOAT);
                if (!std::isdigit(str[j]))
                    return (NONE);
            }
            return (DOUBLE);
        }
        if (!std::isdigit(str[i]))
            return (NONE);
    }
    return (INT);
}

void ScalarConverter::convert(std::string str)
{
    type t = analyze(str);
    std::stringstream   y(str);
    switch (t)
    {
        case CHAR:
            std::cout << "char\n";
            break;
        case INT:
            std::cout << "int\n";
            break;
        case FLOAT:
            std::cout << "float\n";
            break;
        case DOUBLE:
            std::cout << "double\n";
            break;
        default:
            std::cout << "wrong input\n";
    }
}