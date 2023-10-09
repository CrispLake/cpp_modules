/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:41:49 by emajuri           #+#    #+#             */
/*   Updated: 2023/10/06 16:00:11 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <string>

class   ShrubberyCreationForm : public AForm
{
    public:

        ShrubberyCreationForm(std::string const& target);
        ~ShrubberyCreationForm();

        void    executeLogic() const;

    private:

        const std::string target;

        ShrubberyCreationForm();
        ShrubberyCreationForm(ShrubberyCreationForm const& other);
        ShrubberyCreationForm&  operator=(ShrubberyCreationForm const& other);
};

#endif