/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:10:48 by emajuri           #+#    #+#             */
/*   Updated: 2023/10/13 13:31:40 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <iostream>

Form::Form(
	std::string const& name,
	int minimumGradeToSign,
	int minimumGradeToExecute)
:
	name(name),
	isSigned(false),
	minimumGradeToSign(minimumGradeToSign),
	minimumGradeToExecute(minimumGradeToExecute)
{
	if (minimumGradeToSign < GRADE_HIGHEST || minimumGradeToExecute < GRADE_HIGHEST)
		throw(GradeTooHighException());
	if (minimumGradeToSign > GRADE_LOWEST || minimumGradeToExecute > GRADE_LOWEST)
		throw(GradeTooLowException());
}

Form::~Form()
{}

std::ostream&	operator<<(std::ostream& os, const Form& ref)
{
	os << ref.getName() << "\n";
	os << "Signed: " << (ref.getIsSigned() ? "True\n" : "False\n");
	os << "Minimum grade to sign: " << ref.getMinimumGradeToSign() << "\n";
	os << "Minimum grade to execute: " << ref.getMinimumGradeToExecute() << "\n";
	return (os);
}

std::string	Form::getName() const
{
	return (name);
}

bool	Form::getIsSigned() const
{
	return (isSigned);
}

int	Form::getMinimumGradeToSign() const
{
	return (minimumGradeToSign);
}

int	Form::getMinimumGradeToExecute() const
{
	return (minimumGradeToExecute);
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Too high grade");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Too low grade");
}

void	Form::beSigned(Bureaucrat const& ref)
{
	if (ref.getGrade() > minimumGradeToSign)
		throw(GradeTooLowException());
	isSigned = true;
}
