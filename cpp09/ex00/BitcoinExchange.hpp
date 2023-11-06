/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:42:37 by emajuri           #+#    #+#             */
/*   Updated: 2023/11/06 15:06:31 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <map>

class BitcoinExchange
{
    //YYYYMMDD
    public:
        BitcoinExchange();
        BitcoinExchange(BitcoinExchange const& ref);
        BitcoinExchange&    operator=(BitcoinExchange const& ref);
        ~BitcoinExchange();

        void        Exchange(std::string file);
        float       getRateByDate(std::string const& date);

    private:
        std::map<std::string, float> rates;

        std::string getDateFromLine(std::string line);
        bool        isValidLine(std::string line);
        bool        isValidDate(std::string line);
};