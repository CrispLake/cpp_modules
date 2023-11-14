/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:30:46 by emajuri           #+#    #+#             */
/*   Updated: 2023/11/14 18:18:47 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>

class PmergeMe
{
    public:
        PmergeMe();
        PmergeMe(PmergeMe const& ref);
        PmergeMe&   operator=(PmergeMe const& ref);
        ~PmergeMe();

        void    sort(const char **argv);
    
    private:
        typedef std::vector<int>::iterator vec_iterator;
        std::vector<int> m_numbers;

        //Vector specific
        bool    vector_read(const char **argv);
        bool    vector_sort(const char **argv);
        void    vector_merge_insertion_sort(
                                    vec_iterator first,
                                    vec_iterator last,
                                    std::size_t stride);

        //2nd container specific
        bool    listSort(const char **argv);

        //Shared
        template<typename T>
        void    print_container(T begin, T end)
        {
            while (begin < end)
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
        bool    compare(T a, T b) const
        {
            return a < b;
        }

        template<typename T>
        void    swap_pairs(T begin, T end, std::size_t stride)
        {
            for (T it = begin; it < end; it += stride * 2)
            {
                if (compare(*it, *(it + stride)))
                    std::swap(*it, *(it + stride));
            }
        }

};