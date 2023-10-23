/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:43:51 by emajuri           #+#    #+#             */
/*   Updated: 2023/10/23 12:55:21 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main()
{
    char arr[5] = {'a', 'b', 'c', 'd', 'e'};

    iter<char>(arr, 5, f<char>);
    iter<char>(arr, 5, f2<char>);

    int array[10] = {4, 2, 1, 6, 3, 7, 8, 9, 3, 5};
    iter<int>(array, 10, f<int>);
    iter<int>(array, 10, f2<int>);
    return 0;
}
