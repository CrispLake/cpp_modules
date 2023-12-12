/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:30:46 by emajuri           #+#    #+#             */
/*   Updated: 2023/12/12 13:34:47 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>
#include <list>
#include <deque>
#include <cctype>
#include <sstream>

class PmergeMe
{
    public:
        PmergeMe();
        PmergeMe(PmergeMe const& ref);
        PmergeMe& operator=(PmergeMe const& ref);
        ~PmergeMe();

        void sort(char const **argv);
    
    private:
        typedef std::vector<int>::iterator vec_iterator;
        std::vector<int> m_vector;
        std::deque<int> m_deque;

        //Vector specific
        bool container_read(char const **argv);
        bool vector_sort(char const **argv);
        void vector_update(std::list<vec_iterator>::iterator src_begin, std::list<vec_iterator>::iterator src_end, vec_iterator dst_begin, vec_iterator dst_end, std::size_t stride);
        void vector_insertion(std::list<vec_iterator>& chain, std::list<vec_iterator>& pend);
        void vector_merge_insertion_sort(vec_iterator first, vec_iterator last, std::size_t stride);
        
        //2nd container specific
        bool deque_sort(char const **argv);

        //Shared

        template<typename T>
        bool container_read(char const **argv, T& container)
        {
            long nb;
            while (*argv)
            {
                for (unsigned int i = 0; (*argv)[i]; i++)
                {
                    if (!std::isdigit((*argv)[i]))
                    {
                        std::cout << "Error\n";
                        return false;
                    }
                }
                std::stringstream(*argv) >> nb;
                if (nb < 0 || nb > std::numeric_limits<int>::max())
                {
                    std::cout << "Error\n";
                    return false;
                }
                container.push_back(static_cast<int>(nb));
                argv++;
            }
            return true;
        }

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
        std::size_t list_distance(T begin, T end) const
        {
            std::size_t len = 0;
            while (begin != end)
            {
                len++;
                begin++;
            }
            return len;
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
        T get_iter(T begin, std::size_t pos)
        {
            while (pos--)
                begin++;
            return begin;
        }

        template<typename T>
        T find_insert_spot(T begin, T end, T item)
        {
            std::size_t begin_pos = 0;
            std::size_t end_pos = list_distance(begin, end);
            while (begin_pos < end_pos)
            {
                std::size_t mid_pos = (end_pos + begin_pos) / 2;
                if (**item == **get_iter(begin, mid_pos))
                    return get_iter(begin, mid_pos);
                else if (compare(**get_iter(begin, mid_pos), **item))
                    begin_pos = mid_pos + 1;
                else
                    end_pos = mid_pos;
            }
            return get_iter(begin, begin_pos);
        }
};
