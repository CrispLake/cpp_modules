/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:32:33 by emajuri           #+#    #+#             */
/*   Updated: 2023/10/19 14:40:51 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <stdexcept>

Span::Span(unsigned int size) : size(size), sorted(false)
{}

Span::Span(Span const& ref)
{
    vec = ref.vec;
    size = ref.size;
    sorted = ref.sorted;
}

Span&   Span::operator=(Span const& ref)
{
    if (this != &ref)
    {
        vec = ref.vec;
        size = ref.size;
        sorted = ref.sorted;
    }
    return (*this);
}

Span::~Span()
{}

void    Span::addNumber(int nb)
{
    if (vec.size() < size)
    {
        vec.push_back(nb);
        sorted = false;
    }
    else
    {
        throw(std::length_error("Span is full"));
    }
}

int Span::shortestSpan()
{
    if (vec.size() < 2)
        throw(std::logic_error("Too little values in span"));
    if (!sorted)
    {
        std::sort(vec.begin(), vec.end());
        sorted = true;
    }
    long tmp;
    long shortest = 9999999999999999;
    for (std::vector<int>::iterator it = vec.begin(); it + 1 != vec.end(); ++it)
    {
        tmp = *(it + 1) - *it;
        if (tmp < shortest)
            shortest = tmp;
    }
    return (shortest);
}

int Span::longestSpan()
{
    if (vec.size() < 2)
        throw(std::logic_error("Too little values in span"));
    if (!sorted)
    {
        std::sort(vec.begin(), vec.end());
        sorted = true;
    }
    return (vec.back() - vec.front());
}