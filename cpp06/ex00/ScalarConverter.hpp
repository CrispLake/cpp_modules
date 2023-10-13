/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:18:03 by emajuri           #+#    #+#             */
/*   Updated: 2023/10/13 13:27:38 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter
{
    public:

        static void convert(std::string str);

    private:
        ScalarConverter();
        ScalarConverter(ScalarConverter const& ref);
        ScalarConverter& operator=(ScalarConverter const& ref);
        ~ScalarConverter();
};

#endif