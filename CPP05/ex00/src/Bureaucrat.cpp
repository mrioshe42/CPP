/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 10:31:29 by mrios-he          #+#    #+#             */
/*   Updated: 2024/11/28 14:34:33 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, short grade) : name(name), grade(grade)
{
	try
	{
		if (grade < 1)
			throw std::out_of_range("Grade is too high!");
		else if (grade > 150)
			throw std::out_of_range("Grade is too low!");
	}
	catch (const std::out_of_range &e)
	{
		std::cerr << e.what() << std::endl;
		throw ;
	}
}

Bureaucrat::~Bureaucrat() {}

const std::string &Bureaucrat::getName() const
{
	return (name);
}

short Bureaucrat::getGrade() const
{
	return (grade);
}

void Bureaucrat::incrementGrade()
{
	try
	{
		if (grade - 1 < 1)
			throw std::out_of_range("Grade is too high!");
		grade--;
	}
	catch (const std::out_of_range &e)
	{
		std::cerr << e.what() << std::endl;
		throw ;
	}
}

void Bureaucrat::decrementGrade()
{
	try
	{
		if (grade + 1 > 150)
			throw std::out_of_range("Grade is too low!");
		grade++;
	}
	catch (const std::out_of_range &e)
	{
		std::cerr << e.what() << std::endl;
		throw ;
	}
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return (out);
}
