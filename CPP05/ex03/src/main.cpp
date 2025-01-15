/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:36:14 by mrios-he          #+#    #+#             */
/*   Updated: 2024/11/29 16:42:40 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	try
	{
		Bureaucrat bob("Bob", 2);
		ShrubberyCreationForm shrubbery("home");
		RobotomyRequestForm robotomy("Rob");
		PresidentialPardonForm pardon("Charlie");

		std::cout << bob << std::endl;
		std::cout << shrubbery << std::endl;
		std::cout << robotomy << std::endl;
		std::cout << pardon << std::endl;

		bob.signForm(shrubbery);
		bob.signForm(robotomy);
		bob.signForm(pardon);

		bob.executeForm(shrubbery);
		bob.executeForm(robotomy);
		bob.executeForm(pardon);

		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		if (rrf)
		{
			bob.signForm(*rrf);
			bob.executeForm(*rrf);
			delete rrf;
		}
	}
	catch (const std::runtime_error& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
