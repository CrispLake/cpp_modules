/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:27:19 by emajuri           #+#    #+#             */
/*   Updated: 2023/10/19 14:36:28 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>

class Span
{
    public:
        Span(unsigned int size);
        Span(Span const& ref);
        Span&    operator=(Span const& ref);
        ~Span();

        void    addNumber(int nb);
        int     shortestSpan();
        int     longestSpan();

        template<typename T>
        void    addRange(T begin, T end)
        {
            while (begin != end)
            {
                addNumber(*begin);
                begin++;
            }
        }

    private:
        Span();

        std::vector<int>    vec;
        unsigned int        size;
        bool                sorted;
};

#endif