/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:33:11 by emajuri           #+#    #+#             */
/*   Updated: 2023/11/14 18:40:32 by emajuri          ###   ########.fr       */
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
    // print_container(m_numbers.begin(), m_numbers.end());
    return true;
}

#include <cmath>
void    PmergeMe::vector_merge_insertion_sort(
    vec_iterator first,
    vec_iterator last,
    std::size_t stride)
{
    for (vec_iterator it = first; it < last; it += stride)
        std::cout << *it << " ";
    std::cout << "\n\n";

    size_t size = distance(first, last, stride);
    if (size < 2)
        return;

    bool has_extra = size % 2;
    vec_iterator end = has_extra ? last : last - stride;

    swap_pairs(first, end, stride);
    vector_merge_insertion_sort(first, end, stride * 2);

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
        pend.push_back(*last);

    std::cout << "Recursive call: " << log2(stride) << "\n";
    print_container(chain.begin(), chain.end());
    std::cout << "      ";
    print_container(pend.begin(), pend.end());
    std::cout << "\n\n";

    // vec_iterator chain_it = chain.begin() + 2;
    // vec_iterator pend_it = pend.begin();

}
