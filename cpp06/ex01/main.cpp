/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:40:40 by emajuri           #+#    #+#             */
/*   Updated: 2023/10/13 13:45:11 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main()
{
    Data x;

    std::cout << &x << "\n";
    std::cout << Serializer::deserialize(Serializer::serialize(&x)) << "\n";
    return 0;
}
