/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:46:31 by emajuri           #+#    #+#             */
/*   Updated: 2023/11/06 16:34:14 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <stdexcept>

BitcoinExchange::BitcoinExchange()
{
    std::ifstream   data("databck.csv");
    if (!data)
        throw(std::logic_error("Error: Couldn't open data.csv"));

    std::string line;
    float       price;
    std::getline(data, line);
    while (std::getline(data, line))
    {
        if (line.find(",") == std::string::npos)
            continue;
        std::stringstream(line.c_str() + line.find(",") + 1) >> price;
        line.erase(line.find(","));
        line.erase(std::remove(line.begin(), line.end(), '-'), line.end());
        rates.insert(std::map<std::string, float>::value_type(line, price));
    }
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const& ref)
{
    (void)ref;
}

BitcoinExchange&    BitcoinExchange::operator=(BitcoinExchange const& ref)
{
    (void)ref;
    return (*this);
}

BitcoinExchange::~BitcoinExchange()
{}

float   BitcoinExchange::getRateByDate(std::string const& date)
{
    std::map<std::string, float>::iterator search = rates.find(date);
    if (search == rates.end())
        search = --rates.upper_bound(date);
    return (search->second);
}

bool    BitcoinExchange::isValidDate(std::string line)
{
    line.erase(line.find("|"));
    line.erase(std::remove(line.begin(), line.end(), '-'), line.end());
    if (line < "20090102" || line > "20220329")
        return (false);
    return (true);
}

bool    BitcoinExchange::isValidLine(std::string line)
{
    if (line.find("|") == std::string::npos)
    {
        std::cout << "Error: bad input =>" << line << "\n";
        return (false);
    }
    if (!isValidDate(line))
        return (false);
    // std::stringstream(line.c_str() + line.find(",") + 1) >> price;
    // rates.insert(std::map<std::string, float>::value_type(line, price));

    return (true);
}

std::string BitcoinExchange::getDateFromLine(std::string line)
{
    return (line);
}

void    BitcoinExchange::Exchange(std::string fileName)
{
    std::ifstream   file(fileName);
    if (!file)
        throw(std::logic_error("Error: Couldn't open input file"));
    
    std::string line;
    std::getline(std::cin, line);
    while (std::getline(std::cin, line))
    {
        if (!isValidLine(line))
            continue;
    }
}
