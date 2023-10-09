/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:56:49 by emajuri           #+#    #+#             */
/*   Updated: 2023/10/09 14:23:46 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{}

Intern::~Intern()
{}

typedef AForm* (*FormFactory)(std::string const&);

template<typename T>
AForm*   create(std::string const& target)
{
    return (new T(target));
}

AForm*  Intern::makeForm(std::string const& form, std::string const& target)
{
    std::string forms[3] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
    FormFactory functions[3] = {create<PresidentialPardonForm>, create<RobotomyRequestForm>, create<ShrubberyCreationForm>};

    for (int i = 0; i < 3; i++)
        if (forms[i] == form)
            return (functions[i](target));
    std::cout << "Form doesn't exist\n";
    return (NULL);
}