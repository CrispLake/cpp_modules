/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:10:48 by emajuri           #+#    #+#             */
/*   Updated: 2023/10/05 12:51:25 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <iostream>

AForm::AForm(
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

AForm::~AForm()
{}

std::ostream&	operator<<(std::ostream& os, const AForm& ref)
{
	os << ref.getName() << "\n";
	os << "Signed: " << (ref.getIsSigned() ? "True\n" : "False\n");
	os << "Minimum grade to sign: " << ref.getMinimumGradeToSign() << "\n";
	os << "Minimum grade to execute: " << ref.getMinimumGradeToExecute() << "\n";
	return (os);
}

std::string	AForm::getName() const
{
	return (name);
}

bool	AForm::getIsSigned() const
{
	return (isSigned);
}

int	AForm::getMinimumGradeToSign() const
{
	return (minimumGradeToSign);
}

int	AForm::getMinimumGradeToExecute() const
{
	return (minimumGradeToExecute);
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Too high grade");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Too low grade");
}

const char* AForm::FormNotSignedExpection::what() const throw()
{
	return ("Form has not been signed");
}

void	AForm::beSigned(Bureaucrat const& ref)
{
	if (ref.getGrade() > minimumGradeToSign)
		throw(GradeTooLowException());
	isSigned = true;
}

void    AForm::execute(Bureaucrat const& ref) const
{
    if (!isSigned)
        throw(FormNotSignedExpection());
    if (ref.getGrade() > minimumGradeToExecute)
        throw(GradeTooLowException());
    executeLogic();
}
