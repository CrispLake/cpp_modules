/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:41:49 by emajuri           #+#    #+#             */
/*   Updated: 2023/10/06 16:19:53 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <string>

class   PresidentialPardonForm : public AForm
{
    public:

        PresidentialPardonForm(std::string const& target);
        ~PresidentialPardonForm();

        void    executeLogic() const;

    private:

        const std::string target;

        PresidentialPardonForm();
        PresidentialPardonForm(PresidentialPardonForm const& other);
        PresidentialPardonForm&  operator=(PresidentialPardonForm const& other);
};

#endif