/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:44:08 by emajuri           #+#    #+#             */
/*   Updated: 2023/10/25 15:34:05 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <cstddef>
#include <iostream>

template<typename T, typename F>
void    iter(T* arr, std::size_t len, F f)
{
    for (std::size_t i = 0; i < len; i++)
        f(arr[i]);
}

template<typename T>
void    f(T& x)
{
    x += 1;
}

template<typename T>
void    f2(T& x)
{
    std::cout << x << "\n";
}


#endif