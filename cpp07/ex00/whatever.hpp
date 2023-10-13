/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:37:45 by emajuri           #+#    #+#             */
/*   Updated: 2023/10/13 16:46:39 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template<typename T>
void    swap(T& a, T& b)
{
    T tmp;
    tmp = a;
    a = b;
    b = tmp;
}

template<typename T>
T   min(T a, T b)
{
    if (a < b)
        return (a);
    return (b);
}

template<typename T>
T   max(T a, T b)
{
    if (a > b)
        return (a);
    return (b);
}

#endif
