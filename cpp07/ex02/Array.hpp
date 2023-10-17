/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:58:00 by emajuri           #+#    #+#             */
/*   Updated: 2023/10/17 13:19:16 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <exception>
#include <stdexcept>

template<class T>
class Array
{
    public:

        Array()
        {
            array = NULL;
            len = 0;
        }

        Array(unsigned int n)
        {
            array = new T[n]();
            len = n;
        }

        Array(Array const& ref)
        {
            len = ref.len;
            array = new T[len]();
            for (unsigned int i = 0; i < len; i++)
                array[i] = ref.array[i];
        }

        Array   operator=(Array const& ref)
        {
            if (this != &ref)
            {
                if (array)
                    delete[] array;
                len = ref.len;
                array = new T[len]();
                for (unsigned int i = 0; i < len; i++)
                    array[i] = ref.array[i];
            }
            return (*this);
        }

        ~Array()
        {
            if (array)
                delete[] array;
        }

        T&   operator[](unsigned int i) const
        {
            if (i >= len || i < 0)
                throw (std::out_of_range("Index out of bounds"));
            return (array[i]);
        }

        unsigned int    size() const
        {
            return (len);
        }

    private:
        T*              array;
        unsigned int    len;
};

#endif