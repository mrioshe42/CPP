/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 10:31:11 by mrios-he          #+#    #+#             */
/*   Updated: 2024/11/28 18:13:57 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
# include <string>
# include <iostream>
# include <stdexcept>
# include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		const std::string name;
		short grade;

	public:
		Bureaucrat(const std::string &name, short grade);
		~Bureaucrat();

		const std::string &getName() const;
		short getGrade() const;
		void incrementGrade();
		void decrementGrade();
		void signForm(Form& form);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif