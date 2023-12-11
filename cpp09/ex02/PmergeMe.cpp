/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:33:11 by emajuri           #+#    #+#             */
/*   Updated: 2023/12/11 14:52:58 by emajuri          ###   ########.fr       */
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

PmergeMe& PmergeMe::operator=(PmergeMe const& ref)
{
    (void)ref;
    return (*this);
}

PmergeMe::~PmergeMe()
{}

void PmergeMe::test()
{
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(4);
    vec.push_back(5);
    vec.push_back(3);
    vec.push_back(8);
    vec.push_back(9);
    vec.push_back(2);
    vec.push_back(6);
    vec.push_back(7);
    vec.push_back(10);
    vec.push_back(13);
    vec.push_back(12);

    std::list<std::vector<int>::iterator> chain;
    std::list<std::vector<int>::iterator> pend;

    chain.push_back(vec.begin() + 2);
    chain.push_back(vec.begin() + 4);
    chain.push_back(vec.begin() + 5);
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
    {
        pend.push_back(it);
    }
    std::cout << "Chain: ";
    for (std::list<std::vector<int>::iterator>::iterator it = chain.begin(); it != chain.end(); it++)
    {
        std::cout << **it << " ";
    }
    std::cout << "\nPend: ";
    for (std::list<std::vector<int>::iterator>::iterator it = pend.begin(); it != pend.end(); it++)
    {
        std::cout << **it << " ";
    }
    std::cout << "\n";
    for (std::list<std::vector<int>::iterator>::iterator pend_it = pend.begin(); pend_it != pend.end(); pend_it++)
    {
        std::list<std::vector<int>::iterator>::iterator spot = find_insert_spot(chain.begin(), chain.end(), pend_it);
        std::cout << "item: " << **pend_it << "\n";
        if (spot == chain.end())
        {
            std::cout << "Insert spot: END\n";
            chain.insert(spot, *pend_it);
        }
        else 
        {
            std::cout << "Insert spot: " << **spot << "\n";
            chain.insert(spot, *pend_it);
        }
        std::cout << "Chain: ";
        for (std::list<std::vector<int>::iterator>::iterator it = chain.begin(); it != chain.end(); it++)
        {
            std::cout << **it << " ";
        }
        std::cout << "\n\n";
    }
}

void PmergeMe::sort(const char **argv)
{
    std::cout << "Started vecSort with: ";
    //time start
    if (!vector_sort(argv))
        return;
    // test();
    //time end
    std::cout << "Ended vecSort with: ";
    print_container(m_numbers.begin(), m_numbers.end());
    //time start
    // listSort(argv);
    //time end
}

bool PmergeMe::vector_read(const char **argv)
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

bool PmergeMe::vector_sort(const char **argv)
{
    if (!vector_read(argv))
        return false;
    print_container(m_numbers.begin(), m_numbers.end());
    vector_merge_insertion_sort(m_numbers.begin(), m_numbers.end(), 1);
    return true;
}

void PmergeMe::vector_update(std::list<vec_iterator>::iterator src_begin, std::list<vec_iterator>::iterator src_end, vec_iterator dst_begin, vec_iterator dst_end, std::size_t stride)
{
    std::vector<int> tmp;
    tmp.reserve(distance(dst_begin, dst_end, 1));
    // std::cout << "UPDATE:\n" << "tmp size" << distance(dst_begin, dst_end, 1) << "\n";
    // std::cout << "src size" << list_distance(src_begin, src_end) * stride << "\n";
    // std::cout << "stride: " << stride << "\n";

    vec_iterator tmp_it = tmp.begin();
    vec_iterator src_tmp_it;
    // std::cout << "TMP: ";
    while (src_begin != src_end)
    {
        src_tmp_it = *src_begin;
        for (std::size_t tmp_stride = stride; tmp_stride != 0; tmp_stride--)
        {
            tmp.push_back(*src_tmp_it);
            // std::cout << tmp.back() << " ";
            tmp_it++;
            src_tmp_it++;
        }
        src_begin++;
    }
    // std::cout << "\ndst: ";
    for (vec_iterator tmp_begin = tmp.begin(); tmp_begin != tmp.end(); tmp_begin++)
    {
        *dst_begin = *tmp_begin;
        // std::cout << *dst_begin << " ";
        dst_begin++;
    }
    // std::cout << "\n";
}



void PmergeMe::vector_insertion(std::list<vec_iterator>& chain, std::list<vec_iterator>& pend)
{
    static const std::uint_fast64_t jacobsthal_diff[] = {
        2u, 2u, 6u, 10u, 22u, 42u, 86u, 170u, 342u, 682u, 1366u,
        2730u, 5462u, 10922u, 21846u, 43690u, 87382u, 174762u, 349526u, 699050u,
        1398102u, 2796202u, 5592406u, 11184810u, 22369622u, 44739242u, 89478486u,
        178956970u, 357913942u, 715827882u, 1431655766u, 2863311530u, 5726623062u,
        11453246122u, 22906492246u, 45812984490u, 91625968982u, 183251937962u,
        366503875926u, 733007751850u, 1466015503702u, 2932031007402u, 5864062014806u,
        11728124029610u, 23456248059222u, 46912496118442u, 93824992236886u, 187649984473770u,
        375299968947542u, 750599937895082u, 1501199875790165u, 3002399751580331u,
        6004799503160661u, 12009599006321322u, 24019198012642644u, 48038396025285288u,
        96076792050570576u, 192153584101141152u, 384307168202282304u, 768614336404564608u,
        1537228672809129216u, 3074457345618258432u, 6148914691236516864u
    };

    std::list<vec_iterator>::iterator chain_it = chain.begin();
    chain_it++;
    chain_it++;
    std::list<vec_iterator>::iterator pend_it = pend.begin();

    std::list<std::list<vec_iterator>::iterator> jacobsthal_iters;
    
    std::size_t dist = list_distance(pend_it, pend.end());
    std::size_t i = 0;
    // std::cout << "\ndist: " << dist << "pend: " << pend.size() << "chain: " << chain.size() << "\n";
    while (dist >= jacobsthal_diff[i])
    {
        for (std::size_t group_size = jacobsthal_diff[i]; group_size != 0; group_size--)
        {
            jacobsthal_iters.push_back(chain_it);
            if (chain_it != chain.end())
                chain_it++;
            pend_it++;
        }
        std::list<vec_iterator>::iterator save = pend_it;
        pend_it--;
        while(!jacobsthal_iters.empty())
        {
            // find_insert_spot(chain.begin(), chain.end(), pend_it);
            std::list<vec_iterator>::iterator spot = find_insert_spot(chain.begin(), jacobsthal_iters.back(), pend_it);
            chain.insert(spot, *pend_it);
            pend_it--;
            jacobsthal_iters.pop_back();
        }
        pend_it = save;
        dist = list_distance(pend_it, pend.end());
    }
    while (pend_it != pend.end())
    {
        std::list<vec_iterator>::iterator spot = find_insert_spot(chain.begin(), chain.end(), pend_it);
        chain.insert(spot, *pend_it);
        pend_it++;
    }
}

void PmergeMe::vector_merge_insertion_sort(
    vec_iterator first,
    vec_iterator last,
    std::size_t stride)
{
    size_t size = distance(first, last, stride);
    if (size < 2)
        return;

    // std::cout << "Size: " << size << "\n";
    // for (vec_iterator it = first; it < last; it += stride)
    //     std::cout << *it << " ";
    // std::cout << "\n";

    bool has_extra = size % 2;
    // std::cout << "has extra: " << (has_extra ? "True\n" : "False\n");
    vec_iterator end = has_extra ? (last - stride) : last;
    // std::cout << "Last: " << *last << " | last - 1: " << *(last - stride) << " | End: " << *end << "\n";

    swap_pairs(first, end, stride);
    // std::cout << "\n\n";
    vector_merge_insertion_sort(first, end, stride * 2);

    // std::cout << "Size: " << size << "\n";
    // for (vec_iterator it = first; it < last; it += stride)
    //     std::cout << *it << " ";
    // std::cout << "\n";

    std::list<vec_iterator> chain;
    std::list<vec_iterator> pend;

    chain.push_back((first + stride));
    chain.push_back(first);

    for (vec_iterator it = first + stride * 2; it < end; it += stride * 2)
    {
        chain.push_back(it);
        pend.push_back((it + stride));
    }

    if (has_extra)
        pend.push_back(end);

    // std::cout << "Recursive call: " << log2(stride) << "\n";
    // for (std::list<vec_iterator>::iterator it = chain.begin(); it != chain.end(); it++)
    //     std::cout << **it << " ";
    // std::cout << "\n";
    // std::cout << "      ";
    // for (std::list<vec_iterator>::iterator it = pend.begin(); it != pend.end(); it++)
    //     std::cout << **it << " ";
    // std::cout << "\n";

    //implement insertion sort
    vector_insertion(chain, pend);
    // TEMP ->
    // for (std::list<vec_iterator>::iterator it = pend_it; it != pend.end(); it++)
    // {
    //     chain.insert(chain.begin(), *it);
    // }
    // <- TEMP

    // std::cout << "End result\n";
    // for (std::list<vec_iterator>::iterator it = chain.begin(); it != chain.end(); it++)
    //     std::cout << **it << " ";
    // std::cout << "\n";
    // std::cout << "\n\n";
    vector_update(chain.begin(), chain.end(), first, last, stride);
}