/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:31:05 by emajuri           #+#    #+#             */
/*   Updated: 2023/11/06 15:12:31 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "BitcoinExchange.hpp"

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        std::cout << "Invalid argument count\n";
        return (1);
    }
    (void)argv;
    try
    {
        BitcoinExchange btc;
        // btc.Exchange(argv[1]);
        // std::cout << btc.getRateByDate("20090204") << "\n";
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    
    return(0);
}
