/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:42:37 by emajuri           #+#    #+#             */
/*   Updated: 2023/11/07 15:58:20 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <map>

class BitcoinExchange
{
    public:
        BitcoinExchange();
        BitcoinExchange(BitcoinExchange const& ref);
        BitcoinExchange&    operator=(BitcoinExchange const& ref);
        ~BitcoinExchange();

        void        Exchange(std::string file) const;
        float       getRateByDate(std::string const& date) const;

    private:
        std::map<std::string, float> rates;

        std::string getDateFromLine(std::string line) const;
        bool        isValidLine(std::string line) const;
        bool        isValidDate(std::string line) const;
        bool        isValidValue(std::string line) const;
};