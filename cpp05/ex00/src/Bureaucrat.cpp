/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:10:48 by emajuri           #+#    #+#             */
/*   Updated: 2023/10/04 18:05:14 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() : name("Unnamed"), grade(GRADE_LOWEST) {
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name) {
	if (grade < GRADE_HIGHEST)
		throw(GradeTooHighException());
	if (grade > GRADE_LOWEST)
		throw(GradeTooLowException());
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) {
	name = other.name;
	grade = other.grade;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other){
		name = other.name;
		grade = other.grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat() {
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& ref) {
	os << ref.getName() << ", bureaucrat grade " << ref.getGrade() << ".\n";
	return (os);
}

std::string	Bureaucrat::getName() const {
	return (name);
}

int	Bureaucrat::getGrade() const {
	return (grade);
}

void	Bureaucrat::gradeIncrement() {
	if (grade - 1 < GRADE_HIGHEST)
		throw(GradeTooHighException());
	grade--;
}

void	Bureaucrat::gradeDecrement() {
	if (grade + 1 > GRADE_LOWEST)
		throw(GradeTooLowException());
	grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Too high grade");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Too low grade");
}
