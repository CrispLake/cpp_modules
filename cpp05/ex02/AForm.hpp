/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:26:51 by emajuri           #+#    #+#             */
/*   Updated: 2023/10/13 13:31:17 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include "Bureaucrat.hpp"

std::ostream&	operator<<(std::ostream& os, const class AForm& ref);

class AForm
{
	public:

		AForm(
			std::string const& name,
			int minimumGradeToSign,
			int minimumGradeToExecute);
		virtual ~AForm();
	
		std::string 	getName() const;
		bool    		getIsSigned() const;
		int 			getMinimumGradeToSign() const;
		int 			getMinimumGradeToExecute() const;

		void		    beSigned(Bureaucrat const& ref);
        void            execute(Bureaucrat const& ref) const;
        virtual void    executeLogic() const = 0;

	private:

		std::string const	name;
		bool				isSigned;
		int const			minimumGradeToSign;
		int const			minimumGradeToExecute;

		class GradeTooHighException : public std::exception
		{
			const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			const char* what() const throw();
		};

		class FormNotSignedExpection : public std::exception
		{
			const char* what() const throw();
		};

		AForm();
		AForm(AForm const& other);
		AForm&	operator=(AForm const& other);
};

#endif