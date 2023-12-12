/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:33:11 by emajuri           #+#    #+#             */
/*   Updated: 2023/12/12 14:07:58 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <time.h>

PmergeMe::PmergeMe()
{}

PmergeMe::~PmergeMe()
{}

void PmergeMe::sort(char const **argv)
{
    std::cout << "Before: ";
    clock_t start = clock();
    if (!vector_sort(argv))
        return;
    clock_t end = clock();
    std::cout << "After: ";
    print_container(m_vector.begin(), m_vector.end());
    double vec_time = 1000.0 * (end - start) / CLOCKS_PER_SEC;
    start = clock();
    if (!deque_sort(argv))
        return;
    end = clock();
    if (std::is_sorted(m_vector.begin(), m_vector.end()))
    {
        std::cout << "SORTED\n";
    }
    else
    {
        std::cout << "NOT SORTED !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
        return;
    }
    if (std::is_sorted(m_deque.begin(), m_deque.end()))
    {
        std::cout << "SORTED\n";
    }
    else
    {
        std::cout << "NOT SORTED !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
        return;
    }
    unsigned int range = m_vector.size();
    double other_time = 1000.0 * (end - start) / CLOCKS_PER_SEC;
    std::cout << "Time to process a range of " << range << " elements with std::vector : " << vec_time << " ms\n";
    std::cout << "Time to process a range of " << range << " elements with std::deque : " << other_time << " ms\n";
}

bool PmergeMe::vector_sort(char const **argv)
{
    if (!container_read(argv, m_vector))
        return false;
    print_container(m_vector.begin(), m_vector.end());
    merge_insertion_sort(m_vector.begin(), m_vector.end(), 1);
    return true;
}

bool PmergeMe::deque_sort(char const **argv)
{
    if (!container_read(argv, m_deque))
        return false;
    merge_insertion_sort(m_deque.begin(), m_deque.end(), 1);
    return true;
}
