/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:30:46 by emajuri           #+#    #+#             */
/*   Updated: 2023/11/14 17:11:33 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>

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

        //Shared
        template <typename T>
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
        
        template <typename T>
        bool    compare(T a, T b) const
        {
            return a < b;
        }

        //Vector specific
        bool    vector_read(const char **argv);
        bool    vector_sort(const char **argv);
        void    vector_merge_insertion_sort(
                                    vec_iterator first,
                                    vec_iterator last,
                                    std::size_t stride);
        void    vector_print();

        //2nd container specific
        bool    listSort(const char **argv);
};