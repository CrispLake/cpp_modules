/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:42:06 by emajuri           #+#    #+#             */
/*   Updated: 2023/11/20 15:48:18 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


//./PmergeMe `jot -r 12 10 99 | tr '\n' ' '`
int main(int argc, char const *argv[])
{
    PmergeMe    sorter;

    if (argc > 1)
        sorter.sort(argv + 1);
    return 0;
}
