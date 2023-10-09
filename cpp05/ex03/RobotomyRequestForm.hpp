/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:41:49 by emajuri           #+#    #+#             */
/*   Updated: 2023/10/06 16:05:06 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <string>

class   RobotomyRequestForm : public AForm
{
    public:

        RobotomyRequestForm(std::string const& target);
        ~RobotomyRequestForm();

        void    executeLogic() const;

    private:

        const std::string target;

        RobotomyRequestForm();
        RobotomyRequestForm(RobotomyRequestForm const& other);
        RobotomyRequestForm&  operator=(RobotomyRequestForm const& other);
};

#endif