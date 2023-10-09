/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:41:49 by emajuri           #+#    #+#             */
/*   Updated: 2023/10/06 16:41:02 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string const& target)
: AForm("ShrubberyCreationForm", 145, 137), target(target)
{}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

void    ShrubberyCreationForm::executeLogic() const
{
    std::string tree(
    "            * *    \n"
    "        *    *  *\n"
    "    *  *    *     *  *\n"
    "    *     *    *  *    *\n"
    "* *   *    *    *    *   *\n"
    "*     *  *    * * .#  *   *\n"
    "*   *     * #.  .# *   *\n"
    "*     \"#.  #: #\" * *    *\n"
    "*   * * \"#. ##\"       *\n"
    "*       \"###\n"
    "            ##\n"
    "            ##.\n"
    "            .##:\n"
    "            :###\n"
    "            ;###\n"
    "            ,####.\n"
    "/\\/\\/\\/\\/\\/.######.\\/\\/\\/\\/\\\n"
);

    std::ofstream   file(target + "_shrubbery");
    if (file)
        file << tree << "\n" << tree;
}