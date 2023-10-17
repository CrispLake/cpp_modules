/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:44:08 by emajuri           #+#    #+#             */
/*   Updated: 2023/10/16 13:52:54 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <cstddef>
#include <iostream>

template<typename T>
void    iter(T* arr, std::size_t len, T (*f)(T element))
{
    for (std::size_t i = 0; i < len; i++)
        arr[i] = f(arr[i]);
}

template<typename T>
T    f(T x)
{
    return x + 1;
}

template<typename T>
T    f2(T x)
{
    std::cout << x << "\n";
    return x;
}


#endif