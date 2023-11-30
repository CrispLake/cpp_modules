/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:33:11 by emajuri           #+#    #+#             */
/*   Updated: 2023/11/30 13:50:47 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <vector>
#include <iostream>
#include <sstream>
#include <limits>
#include <algorithm>
#include <cmath>

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
    std::cout << "Started vecSort with: ";
    //time start
    if (!vector_sort(argv))
        return;
    //time end
    std::cout << "Ended vecSort with: ";
    print_container(m_numbers.begin(), m_numbers.end());
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
    print_container(m_numbers.begin(), m_numbers.end());
    vector_merge_insertion_sort(m_numbers.begin(), m_numbers.end(), 1);
    return true;
}

void    PmergeMe::vector_merge_insertion_sort(
    vec_iterator const first,
    vec_iterator const last,
    std::size_t stride)
{
    size_t size = distance(first, last, stride);
    if (size < 2)
        return;

    std::cout << "Size: " << size << "\n";
    for (vec_iterator it = first; it < last; it += stride)
        std::cout << *it << " ";
    std::cout << "\n";

    bool has_extra = size % 2;
    std::cout << "has extra: " << (has_extra ? "True\n" : "False\n");
    vec_iterator end = has_extra ? (last - stride) : last;
    std::cout << "Last: " << *last << " | last - 1: " << *(last - stride) << " | End: " << *end << "\n";

    swap_pairs(first, end, stride);
    std::cout << "\n\n";
    vector_merge_insertion_sort(first, end, stride * 2);

    std::cout << "Size: " << size << "\n";
    for (vec_iterator it = first; it < last; it += stride)
        std::cout << *it << " ";
    std::cout << "\n";

    std::vector<int> chain;
    std::vector<int> pend;

    chain.push_back(*(first + stride));
    chain.push_back(*first);

    for (vec_iterator it = first + stride * 2; it < end; it += stride * 2)
    {
        chain.push_back(*it);
        pend.push_back(*(it + stride));
    }

    if (has_extra)
        pend.push_back(*end);

    std::cout << "Recursive call: " << log2(stride) << "\n";
    print_container(chain.begin(), chain.end());
    std::cout << "      ";
    print_container(pend.begin(), pend.end());

    vec_iterator chain_it = chain.begin() + 2;
    vec_iterator pend_it = pend.begin();

    //implement insertion sort
    //TEMP ->
    (void)chain_it;
    for (vec_iterator it = pend_it; it < pend.end(); it++)
    {
        chain.insert(chain.begin(), *it);
    }
    // <- TEMP

    std::cout << "End result\n";
    print_container(chain.begin(), chain.end());
    std::cout << "\n\n";
}
