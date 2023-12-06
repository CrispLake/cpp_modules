/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:30:46 by emajuri           #+#    #+#             */
/*   Updated: 2023/12/06 16:28:30 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>
#include <list>

class PmergeMe
{
    public:
        PmergeMe();
        PmergeMe(PmergeMe const& ref);
        PmergeMe& operator=(PmergeMe const& ref);
        ~PmergeMe();

        void sort(const char **argv);
    
    private:
        typedef std::vector<int>::iterator vec_iterator;
        std::vector<int> m_numbers;

        //Vector specific
        bool vector_read(const char **argv);
        bool vector_sort(const char **argv);
        void vector_merge_insertion_sort(vec_iterator const first, vec_iterator const last, std::size_t stride);

        //2nd container specific
        bool listSort(const char **argv);

        //Shared
        template<typename T>
        void print_container(T begin, T end)
        {
            while (begin != end)
            {
                std::cout << *begin << " ";
                begin++;
            }
            std::cout << "\n";
        }

        template<typename T>
        std::size_t distance(T begin, T end, std::size_t stride) const
        {
            std::size_t len = 0;

            while (begin < end)
            {
                len++;
                begin += stride;
            }
            return len;
        }
        
        template<typename T>
        bool compare(T a, T b) const
        {
            return a < b;
        }

        template<typename T>
        void swap_pairs(T begin, T end, std::size_t stride)
        {
            for (T it = begin; it < end; it += stride * 2)
            {
                std::cout << "|" << *it << " < " << *(it + stride) << "|\n";
                if (compare(*it, *(it + stride)))
                    swap_all_pairs(it, it + stride);
            }
        }

        template<typename T>
        void swap_all_pairs(T first, T second)
        {
            int tmp;
            T end = second;
            while (first != end)
            {
                tmp = *first;
                *first = *second;
                *second = tmp;
                first++;
                second++;
            }
        }

        template<typename T>
        void move_all(std::list<vec_iterator>::iterator src_begin, std::list<vec_iterator>::iterator src_end, T dst_begin, T dst_end, std::size_t stride)
        {
            std::vector<int> tmp;
            tmp.reserve(distance(dst_begin, dst_end, 1));

            vec_iterator tmp_it = tmp.begin();
            vec_iterator src_tmp;
            while (src_begin != src_end)
            {
                src_tmp = *src_begin;
                for (std::size_t tmp_stride = stride; tmp_stride != 0; tmp_stride--)
                {
                    *tmp_it = *src_tmp;
                    tmp_it++;
                    src_tmp++;
                }
                src_begin++;
            }
            for (vec_iterator tmp_it = tmp.begin(); tmp_it != tmp.end(); tmp_it++)
            {
                *dst_begin = *tmp_it;
                dst_begin++;
            }
        }
};