/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:07:32 by emajuri           #+#    #+#             */
/*   Updated: 2023/10/10 16:35:57 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#define GRADE_HIGHEST 1
#define GRADE_LOWEST 150

#include <string>
#include <iostream>

std::ostream&	operator<<(std::ostream& os, const class Bureaucrat& ref);

class Bureaucrat {
	public:

		Bureaucrat(std::string const& name, int grade);
		~Bureaucrat();

		std::string	getName() const;
		int			getGrade() const;

		void		gradeIncrement();
		void		gradeDecrement();

	private:

		class GradeTooHighException : public std::exception {
			const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			const char* what() const throw();
		};

		std::string const	name;
		int					grade;

		Bureaucrat();
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat&	operator=(const Bureaucrat& other);
};

#endif