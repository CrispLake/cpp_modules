#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat	Matias("Matias", 150);
	Bureaucrat	Keijo("Keijo", 1);
	std::cout << Matias;
	std::cout << Keijo.getName() << " " << Keijo.getGrade() << "\n";

	std::cout << "\nIncrement and decrement\n";
	try
	{
		Matias.gradeIncrement();
		std::cout << Matias;
		Keijo.gradeDecrement();
		std::cout << Keijo;
	}
	catch (std::exception &e) {std::cout << e.what() << "\n";}

	std::cout << "\nOver increment and decrement\n";
	try
	{
		Matias.gradeDecrement();
		Matias.gradeDecrement();
	}
	catch (std::exception &e) {std::cout << e.what() << "\n";}

	try
	{
		Keijo.gradeIncrement();
		Keijo.gradeIncrement();
	}
	catch (std::exception &e) {std::cout << e.what() << "\n";}


	std::cout << "\nCreating class with too high or too low grade\n";
	try {Bureaucrat	Kalle("Kalle", 0);}
	catch (std::exception &e) {std::cout << e.what() << "\n";}

	try {Bureaucrat	Jonne("Jonne", 190);}
	catch (std::exception &e) {std::cout << e.what() << "\n";}

	std::cout << "\n\nFORM:\n";

	Bureaucrat	cantSign("!Signer", 82);
	Bureaucrat	canSign("Signer", 72);
	Bureaucrat	canExecute("Executer", 31);
	Form	x("Test", 80, 40);
	std::cout << x;
	std::cout << x.getName() << x.getIsSigned() << x.getMinimumGradeToSign() << x.getMinimumGradeToExecute() << "\n";

	std::cout << "\nCreating class with too high or too low grade\n";
	try {Form tooHigh("High", 0, 1);}
	catch (std::exception &e) {std::cout << e.what() << "\n";}
	try {Form tooHigh("High", 1, 0);}
	catch (std::exception &e) {std::cout << e.what() << "\n";}
	try {Form tooLow("Low", 1, 155);}
	catch (std::exception &e) {std::cout << e.what() << "\n";}
	try {Form tooLow("Low", 155, 4);}
	catch (std::exception &e) {std::cout << e.what() << "\n";}

	std::cout << "\nSigning the form\n";
	cantSign.signForm(x);

    canSign.signForm(x);

	return 0;
}
