/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:26:51 by emajuri           #+#    #+#             */
/*   Updated: 2023/10/05 14:49:55 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include "Bureaucrat.hpp"

std::ostream&	operator<<(std::ostream& os, const class Form& ref);

class Form
{
	public:

		Form(
			std::string const& name,
			int minimumGradeToSign,
			int minimumGradeToExecute);
		~Form();
	
		std::string	getName() const;
		bool		getIsSigned() const;
		int			getMinimumGradeToSign() const;
		int			getMinimumGradeToExecute() const;

		void		beSigned(Bureaucrat const& ref);

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

		Form();
		Form(Form const& other);
		Form&	operator=(Form const& other);
};

#endif