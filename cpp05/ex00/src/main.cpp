#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat	Matias("Matias", 150);
	Bureaucrat	Keijo("Keijo", 1);
	std::cout << Matias;
	std::cout << Keijo.getName() << " " << Keijo.getGrade() << "\n";

	std::cout << "\nIncrement and decrement\n";
	try {
		Matias.gradeIncrement();
		std::cout << Matias;
		Keijo.gradeDecrement();
		std::cout << Keijo;
	}
	catch (std::exception &e) {std::cout << e.what() << "\n";}

	std::cout << "\nOver increment and decrement\n";
	try {
		Matias.gradeDecrement();
		Matias.gradeDecrement();
	}
	catch (std::exception &e) {std::cout << e.what() << "\n";}

	try {
		Keijo.gradeIncrement();
		Keijo.gradeIncrement();
	}
	catch (std::exception &e) {std::cout << e.what() << "\n";}


	std::cout << "\nCreating class with too high or too low grade\n";
	try {Bureaucrat	Kalle("Kalle", 0);}
	catch (std::exception &e) {std::cout << e.what() << "\n";}

	try {Bureaucrat	Jonne("Jonne", 190);}
	catch (std::exception &e) {std::cout << e.what() << "\n";}

	return 0;
}
