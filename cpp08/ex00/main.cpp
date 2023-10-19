/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:09:53 by emajuri           #+#    #+#             */
/*   Updated: 2023/10/17 16:49:44 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <iostream>

int main()
{
    std::vector<int> x;

    x.push_back(5);
    x.push_back(55);
    x.push_back(555);
    x.push_back(544);
    x.push_back(54);
    x.push_back(4);
    x.push_back(45);
    std::vector<int>::iterator tmp;
    tmp = easyfind(x, 4);
    if (tmp != x.end())
        std::cout << *tmp << "\n";
    else
        std::cout << "Not found\n";
    tmp = easyfind(x, 44);
    if (tmp != x.end())
        std::cout << *tmp << "\n";
    else
        std::cout << "Not found\n";
    return 0;
}
