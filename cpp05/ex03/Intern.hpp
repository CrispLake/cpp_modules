/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:55:44 by emajuri           #+#    #+#             */
/*   Updated: 2023/10/09 13:09:16 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"

class Intern
{
    public:

        AForm*  makeForm(std::string const& form, std::string const& target);

        Intern();
        ~Intern();

    private:

        Intern(Intern const& other);
        Intern& operator=(Intern const& other);
};

#endif