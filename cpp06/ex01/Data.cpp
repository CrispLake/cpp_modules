/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:33:48 by emajuri           #+#    #+#             */
/*   Updated: 2023/10/13 13:36:10 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data() : x(5), y(10)
{}

Data::Data(Data const& ref) : x(ref.x), y(ref.y)
{}

Data::~Data()
{}