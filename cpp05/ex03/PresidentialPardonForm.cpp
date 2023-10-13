/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:41:49 by emajuri           #+#    #+#             */
/*   Updated: 2023/10/13 13:30:46 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(std::string const& target)
: AForm("PresidentialPardonForm", 25, 5), target(target)
{}

PresidentialPardonForm::~PresidentialPardonForm()
{}

void    PresidentialPardonForm::executeLogic() const
{
    std::cout << target << " has been pardoned by Zaphod Beeblebrox\n";
}