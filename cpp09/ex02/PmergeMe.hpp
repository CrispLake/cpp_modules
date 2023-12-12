/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:30:46 by emajuri           #+#    #+#             */
/*   Updated: 2023/12/12 14:07:48 by emajuri          ###   ########.fr       */
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
        ~PmergeMe();

        void sort(char const **argv);
    
    private:
        typedef std::vector<int>::iterator vec_iterator;
        std::vector<int> m_vector;
        std::deque<int> m_deque;

        PmergeMe(PmergeMe const& ref);
        PmergeMe& operator=(PmergeMe const& ref);
        //Vector specific
        bool vector_sort(char const **argv);
        
        //2nd container specific
        bool deque_sort(char const **argv);

        //Shared
        template<typename T>
        void container_update(typename std::list<T>::iterator src_begin, typename std::list<T>::iterator src_end, T dst_begin, T dst_end, std::size_t stride)
        {
            std::vector<int> tmp;
            tmp.reserve(distance(dst_begin, dst_end, 1));

            std::vector<int>::iterator tmp_it = tmp.begin();
            T src_tmp_it;
            while (src_begin != src_end)
            {
                src_tmp_it = *src_begin;
                for (std::size_t tmp_stride = stride; tmp_stride != 0; tmp_stride--)
                {
                    tmp.push_back(*src_tmp_it);
                    tmp_it++;
                    src_tmp_it++;
                }
                src_begin++;
            }
            for (std::vector<int>::iterator tmp_begin = tmp.begin(); tmp_begin != tmp.end(); tmp_begin++)
            {
                *dst_begin = *tmp_begin;
                dst_begin++;
            }
        }

        template<typename T>
        void container_insertion(std::list<T>& chain, std::list<T>& pend)
        {
            static const std::uint_fast64_t jacobsthal_diff[] = {
                    2u, 2u, 6u, 10u, 22u, 42u, 86u, 170u, 342u, 682u, 1366u,
                    2730u, 5462u, 10922u, 21846u, 43690u, 87382u, 174762u, 349526u, 699050u,
                    1398102u, 2796202u, 5592406u, 11184810u, 22369622u, 44739242u, 89478486u,
                    178956970u, 357913942u, 715827882u, 1431655766u, 2863311530u, 5726623062u,
                    11453246122u, 22906492246u, 45812984490u, 91625968982u, 183251937962u,
                    366503875926u, 733007751850u, 1466015503702u, 2932031007402u, 5864062014806u,
                    11728124029610u, 23456248059222u, 46912496118442u, 93824992236886u, 187649984473770u,
                    375299968947542u, 750599937895082u, 1501199875790166u, 3002399751580330u,
                    6004799503160662u, 12009599006321322u, 24019198012642646u, 48038396025285290u,
                    96076792050570582u, 192153584101141162u, 384307168202282326u, 768614336404564650u,
                    1537228672809129302u, 3074457345618258602u, 6148914691236517206u
                };
            typename std::list<T>::iterator chain_it = chain.begin();
            chain_it++;
            chain_it++;
            typename std::list<T>::iterator pend_it = pend.begin();

            typename std::list<typename std::list<T>::iterator> jacobsthal_iters;
    
            std::size_t dist = list_distance(pend_it, pend.end());
            std::size_t i = 0;
            while (dist >= jacobsthal_diff[i])
            {
                for (std::size_t group_size = jacobsthal_diff[i]; group_size != 0; group_size--)
                {
                    jacobsthal_iters.push_back(chain_it);
                    if (chain_it != chain.end())
                        chain_it++;
                    pend_it++;
                }
                typename std::list<T>::iterator save = pend_it;
                pend_it--;
                while(!jacobsthal_iters.empty())
                {
                    typename std::list<T>::iterator spot = find_insert_spot(chain.begin(), jacobsthal_iters.back(), pend_it);
                    chain.insert(spot, *pend_it);
                    pend_it--;
                    jacobsthal_iters.pop_back();
                }
                pend_it = save;
                dist = list_distance(pend_it, pend.end());
            }
            while (pend_it != pend.end())
            {
                typename std::list<T>::iterator spot = find_insert_spot(chain.begin(), chain.end(), pend_it);
                chain.insert(spot, *pend_it);
                pend_it++;
            }
        }

        template<typename T>
        void merge_insertion_sort(
            T first,
            T last,
            std::size_t stride)
        {
            size_t size = distance(first, last, stride);
            if (size < 2)
                return;

            bool has_extra = size % 2;
            T end = has_extra ? (last - stride) : last;

            swap_pairs(first, end, stride);
            merge_insertion_sort(first, end, stride * 2);

            std::list<T> chain;
            std::list<T> pend;

            chain.push_back((first + stride));
            chain.push_back(first);

            for (T it = first + stride * 2; it < end; it += stride * 2)
            {
                chain.push_back(it);
                pend.push_back((it + stride));
            }

            if (has_extra)
                pend.push_back(end);

            container_insertion(chain, pend);
            container_update(chain.begin(), chain.end(), first, last, stride);
        }

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
