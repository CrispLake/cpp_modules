#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    Bureaucrat  canDoAll("Cat", 1);
    Bureaucrat  cannotDoAll("dog", 150);
    ShrubberyCreationForm   shrub("target");
    RobotomyRequestForm     robo("target");
    PresidentialPardonForm  pres("target");

    std::cout << "Trying to execute non signed\n\n";
    canDoAll.executeForm(shrub);
    canDoAll.executeForm(robo);
    canDoAll.executeForm(pres);

    std::cout << "\n\nSigning all the forms\n\n";
    canDoAll.signForm(shrub);
    canDoAll.signForm(robo);
    canDoAll.signForm(pres);

    std::cout << "\n\nExecuting all the forms\n\n";
    canDoAll.executeForm(shrub);
    std::cout << "\n";
    canDoAll.executeForm(robo);
    std::cout << "\n";
    canDoAll.executeForm(pres);

    std::cout << "\n\nExecuting all the forms without rights\n\n";
    cannotDoAll.executeForm(shrub);
    cannotDoAll.executeForm(robo);
    cannotDoAll.executeForm(pres);
	return 0;
}
