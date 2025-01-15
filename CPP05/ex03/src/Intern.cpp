/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 10:54:12 by mrios-he          #+#    #+#             */
/*   Updated: 2024/11/29 16:56:01 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other)
{
	(void)other;
}

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return (*this);
}

Intern::~Intern() {}

AForm* Intern::createShrubberyCreationForm(const std::string& target)
{
	return (new ShrubberyCreationForm(target));
}

AForm* Intern::createRobotomyRequestForm(const std::string& target)
{
	return (new RobotomyRequestForm(target));
}

AForm* Intern::createPresidentialPardonForm(const std::string& target)
{
	return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const
{
	typedef AForm* (*FormCreator)(const std::string& target);
	struct FormType
	{
		std::string name;
		FormCreator creator;
	};
	FormType formTypes[] =
	{
		{"shrubbery creation", &Intern::createShrubberyCreationForm},
		{"robotomy request", &Intern::createRobotomyRequestForm},
		{"presidential pardon", &Intern::createPresidentialPardonForm}
	};
	for (size_t i = 0; i < sizeof(formTypes) / sizeof(FormType); ++i)
	{
		if (formTypes[i].name == formName)
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (formTypes[i].creator(target));
		}
	}
	std::cout << "Error: Form name \"" << formName << "\" does not exist." << std::endl;
	return (NULL);
}