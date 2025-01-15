/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:29:59 by mrios-he          #+#    #+#             */
/*   Updated: 2024/11/29 13:13:07 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
	: name(name), signedStatus(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw std::runtime_error("Grade too high!");
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw std::runtime_error("Grade too low!");
}

AForm::~AForm() {}

AForm::AForm(const AForm& other)
	: name(other.name), signedStatus(other.signedStatus), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
		signedStatus = other.signedStatus;
	return (*this);
}

const std::string& AForm::getName() const
{
	return (name);
}

bool AForm::isSigned() const
{
	return (signedStatus);
}

int AForm::getGradeToSign() const
{
	return (gradeToSign);
}

int AForm::getGradeToExecute() const
{
	return (gradeToExecute);
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > gradeToSign)
		throw std::runtime_error("Grade too low!");
	signedStatus = true;
}

void AForm::checkExecution(const Bureaucrat& executor) const
{
	if (!isSigned())
		throw std::runtime_error("Form is not signed!");
	if (executor.getGrade() > gradeToExecute)
		throw std::runtime_error("Grade too low to execute!");
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
	os << "Form " << form.getName() << ", signed: " << (form.isSigned() ? "yes" : "no")
	   << ", grade to sign: " << form.getGradeToSign()
	   << ", grade to execute: " << form.getGradeToExecute();
	return (os);
}