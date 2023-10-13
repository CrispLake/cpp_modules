/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:19:35 by emajuri           #+#    #+#             */
/*   Updated: 2023/10/13 16:22:55 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <string>
#include <limits>
#include <sstream>
#include <cctype>
#include <cmath>

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
    if (len == 0)
        return (NONE);
    if (str[0] == '\'' && len == 3)
    {
        if (!std::isprint(str[1]) || str[1] == ' ' || str[2] != '\'')
            return (NONE);
        return (CHAR);
    }
    if (str == "-inff" || str == "+inff" || str == "nanf")
        return (FLOAT);
    if (str == "-inf" || str == "+inf" || str == "nan")
        return (DOUBLE);
    if (!std::isdigit(str[0]))
        if (str[0] != '+' && str[0] != '-')
            return (NONE);
    for (int i = 1; i < len; i++)
    {
        if (str[i] == '.' && i != len - 1)
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

static void    convertChar(char c)
{
    std::cout << "char: '" << c << "'\n";
    std::cout << "int: " << static_cast<int>(c) << "\n";
    std::cout << "float: " << static_cast<float>(c) << "\n";
    std::cout << "double: " << static_cast<double>(c) << "\n";
}

static void    convertInt(std::stringstream &ss)
{
    int nb;
    
    if (!(ss >> nb))
    {
        std::cout << "invalid input\n";
        return;
    }
    if (std::numeric_limits<char>::min() <= nb && nb <= std::numeric_limits<char>::max())
    {
        char c = static_cast<char>(nb);
        if (std::isprint(c) && c != ' ')
            std::cout << "char: '" << c << "'\n";
        else
            std::cout << "char: Non displayable\n";
    }
    else
        std::cout << "char: impossible\n";
    std::cout << "int: " << nb << "\n";
    std::cout << "float: " << static_cast<float>(nb) << "\n";
    std::cout << "double: " << static_cast<double>(nb) << "\n";
}

template<typename T>
static void    handleInfAndNan(T nb)
{
    std::cout << "char: impossible\n";
    std::cout << "int: impossible\n";
    if (isinf(nb))
    {
        std::cout << "float: " << (nb >= 0 ? "+inff" : "-inff") << "\n";
        std::cout << "double: " << (nb >= 0 ? "+inf" : "-inf") << "\n";
    }
    else
    {
        std::cout << "float: nanf\n";
        std::cout << "float: nan\n";
    }
}

static void    convertFloat(std::stringstream &ss)
{
    float   nb;
    
    if (!(ss >> nb))
    {
        std::cout << "invalid input\n";
        return;
    }
    if (isinf(nb) || isnan(nb))
    {
        handleInfAndNan<float>(nb);
        return;
    }
    if (std::numeric_limits<char>::min() <= nb && nb <= std::numeric_limits<char>::max()
        && !std::isinf(nb) && !std::isnan(nb))
    {
        char c = static_cast<char>(nb);
        if (std::isprint(c) && c != ' ')
            std::cout << "char: '" << c << "'\n";
        else
            std::cout << "char: Non displayable\n";
    }
    else
        std::cout << "char: impossible\n";
    if (std::numeric_limits<int>::min() <= nb && nb <= std::numeric_limits<int>::max()
        && !std::isinf(nb) && !std::isnan(nb))
    {
        std::cout << "int: " << static_cast<int>(nb) << "\n";
    }
    else
        std::cout << "int: impossible\n";
    std::cout << "float: " << nb << "\n";
    std::cout << "double: " << static_cast<double>(nb) << "\n";
}

static void    convertDouble(std::stringstream &ss)
{
    double  nb;
    
    if (!(ss >> nb))
    {
        std::cout << "invalid input\n";
        return;
    }
    if (isinf(nb) || isnan(nb))
    {
        handleInfAndNan<double>(nb);
        return;
    }
    if (std::numeric_limits<char>::min() <= nb && nb <= std::numeric_limits<char>::max()
        && !std::isinf(nb) && !std::isnan(nb))
    {
        char c = static_cast<char>(nb);
        if (std::isprint(c) && c != ' ')
            std::cout << "char: '" << c << "'\n";
        else
            std::cout << "char: Non displayable\n";
    }
    else
        std::cout << "char: impossible\n";
    if (std::numeric_limits<int>::min() <= nb && nb <= std::numeric_limits<int>::max()
        && !std::isinf(nb) && !std::isnan(nb))
    {
        std::cout << "int: " << static_cast<int>(nb) << "\n";
    }
    else
        std::cout << "int: impossible\n";
    if (std::numeric_limits<float>::min() <= nb && nb <= std::numeric_limits<float>::max())
    {
        std::cout << "float: " << static_cast<float>(nb) << "\n";
    }
    else
        std::cout << "float: impossible\n";
    std::cout << "double: " << nb << "\n";
}

void ScalarConverter::convert(std::string str)
{
    type    t = analyze(str);
    if (t == FLOAT)
        str.erase(str.length() - 1, 1);
    if (str == "+inff")
        str = "+inf";
    if (str == "-inff")
        str = "-inf";
    if (str == "nanf")
        str = "nan";
    std::stringstream   ss(str);
    switch (t)
    {
        case CHAR:
            convertChar(str[1]);
            break;
        case INT:
            convertInt(ss);
            break;
        case FLOAT:
            convertFloat(ss);
            break;
        case DOUBLE:
            convertDouble(ss);
            break;
        default:
            std::cout << "invalid input\n";
    }
}