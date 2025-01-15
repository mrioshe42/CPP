/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:21:27 by mrios-he          #+#    #+#             */
/*   Updated: 2024/11/28 18:13:39 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		Form(const std::string& name, int gradeToSign, int gradeToExecute);
		~Form();

		const std::string& getName() const;
		bool isSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;

		void beSigned(const Bureaucrat& bureaucrat);

	private:
		const std::string name;
		bool signedStatus;
		const int gradeToSign;
		const int gradeToExecute;

		Form();
		Form(const Form& other);
		Form& operator=(const Form& other);
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif