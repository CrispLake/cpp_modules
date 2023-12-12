/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:46:31 by emajuri           #+#    #+#             */
/*   Updated: 2023/12/12 18:55:34 by emajuri          ###   ########.fr       */
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
    std::ifstream   data("data.csv");
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
    rates = ref.rates;
}

BitcoinExchange&    BitcoinExchange::operator=(BitcoinExchange const& ref)
{
    if (this != &ref)
        rates = ref.rates;
    return (*this);
}

BitcoinExchange::~BitcoinExchange()
{}

float   BitcoinExchange::getRateByDate(std::string const& date) const
{
    std::map<std::string, float>::const_iterator search = rates.find(date);
    if (search == rates.end())
        search = --rates.upper_bound(date);
    return (search->second);
}

bool    BitcoinExchange::isValidDate(std::string line) const
{
    line = getDateFromLine(line);
    if (line < "20090102")
        return (false);
    if (line.length() < 8)
        return (false);

    int year;
    int month;
    int day;
    std::stringstream(line.substr(0, 4)) >> year;
    std::stringstream(line.substr(4, 2)) >> month;
    std::stringstream(line.substr(6, 2)) >> day;
    if (month > 12 || day > 31)
        return (false);
    else if (month == 2 && ((year % 4 == 0 && day > 29) || day > 28))
        return (false);
    else if (day > 30 && (month == 4 || month == 6 || month == 9 || month == 11))
        return (false);
    return (true);
}

bool    BitcoinExchange::isValidValue(std::string line) const
{
    float value;
    std::string valueStr = line.substr(line.find("|") + 2);
    std::stringstream(valueStr) >> value;
    if (value < 0 || value > 1000)
        return (false);
    return (true);
}

bool    BitcoinExchange::isValidLine(std::string line) const
{
    if (line.find("|") == std::string::npos)
    {
        std::cout << "Error: bad input => " << line << "\n";
        return (false);
    }
    if (!isValidDate(line))
    {
        std::cout << "Error: invalid date => " << line << "\n";
        return (false);
    }
    if (!isValidValue(line))
    {
        std::cout << "Error: invalid value => " << line << "\n";
        return (false);
    }
    return (true);
}

std::string BitcoinExchange::getDateFromLine(std::string line) const
{
    line.erase(line.find("|") - 1);
    line.erase(std::remove(line.begin(), line.end(), '-'), line.end());
    return (line);
}

void    BitcoinExchange::Exchange(std::string fileName) const
{
    std::ifstream   file(fileName);
    if (!file)
        throw(std::logic_error("Error: Couldn't open input file"));
    
    float       rate;
    float       value;
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line))
    {
        if (!isValidLine(line))
            continue;
        rate = getRateByDate(getDateFromLine(line));
        std::stringstream(line.c_str() + line.find("|") + 1) >> value;
        std::cout << line.erase(line.find("|") - 1) << " => " << value << " = " << rate * value << "\n";
    }
}
