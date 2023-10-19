/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:08:22 by emajuri           #+#    #+#             */
/*   Updated: 2023/10/17 16:42:42 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <iterator>

template<typename T>
typename T::iterator  easyfind(T& container, int match)
{
    return (std::find(container.begin(), container.end(), match));
}

#endif