#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
	try {
		Bureaucrat	x("Matias", 150);
		Bureaucrat	d("Keijo", 1);
		// Bureaucrat	y("Jonne", 190);
		// Bureaucrat	z("Kalle", 0);
		std::cout << x;
		std::cout << d.getName() << " " << d.getGrade() << "\n";
		// x.gradeDecrement();
		x.gradeIncrement();
		std::cout << x;
		// d.gradeIncrement();
		d.gradeDecrement();
		std::cout << d;
	}
	catch (std::exception &e) {
		std::cout << e.what() << "\n";
}
	return 0;
}
