/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:33:11 by emajuri           #+#    #+#             */
/*   Updated: 2023/11/14 17:20:17 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <vector>
#include <iostream>
#include <sstream>
#include <limits>
#include <algorithm>

PmergeMe::PmergeMe()
{}

PmergeMe::PmergeMe(PmergeMe const& ref)
{
    (void)ref;
}

PmergeMe&   PmergeMe::operator=(PmergeMe const& ref)
{
    (void)ref;
    return (*this);
}

PmergeMe::~PmergeMe()
{}

void    PmergeMe::sort(const char **argv)
{
    std::cout << "Started vecSort\n";
    //time start
    if (!vector_sort(argv))
        return;
    //time end
    std::cout << "Ended vecSort\n";
    //time start
    // listSort(argv);
    //time end
}

bool    PmergeMe::vector_read(const char **argv)
{
    long nb;
    while (*argv)
    {
        std::stringstream(*argv) >> nb;
        if (nb < 0 || nb > std::numeric_limits<int>::max())
        {
            std::cout << "Error\n";
            return false;
        }
        m_numbers.push_back(static_cast<int>(nb));
        argv++;
    }
    return true;
}

bool    PmergeMe::vector_sort(const char **argv)
{
    if (!vector_read(argv))
        return false;
    vector_merge_insertion_sort(m_numbers.begin(), m_numbers.end(), 1);
    vector_print();
    return true;
}

void    PmergeMe::vector_print()
{
    for (vec_iterator it = m_numbers.begin(); it < m_numbers.end(); it++)
        std::cout << "|" << *it << "| ";
    std::cout << "\n";
}

void    PmergeMe::vector_merge_insertion_sort(
    vec_iterator first,
    vec_iterator last,
    std::size_t stride)
{
    size_t size = distance(first, last, stride);
    if (size < 2)
        return;

    vec_iterator end = size % 2 == 0 ? last : std::prev(last);

    for (vec_iterator it = first; it < end; it += stride * 2)
    {
        if (compare(*it, *(it + stride)))
            std::swap(*it, *(it + stride));
    }
}
