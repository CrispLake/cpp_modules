/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:32:27 by emajuri           #+#    #+#             */
/*   Updated: 2023/10/24 13:18:29 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>

template<class T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
    public:
        typedef typename Container::iterator iterator;

        MutantStack()
        {}
        MutantStack(MutantStack const& ref) : std::stack<T, Container>(ref)
        {}
        MutantStack&    operator=(MutantStack const& ref)
        {
            if (this != &ref)
                std::stack<T, Container>::operator=(ref);
            return (*this);
        }
        ~MutantStack()
        {}

        iterator    begin()
        {
            return (this->c.begin());
        }
        iterator    end()
        {
            return (this->c.end());
        }
};

#endif