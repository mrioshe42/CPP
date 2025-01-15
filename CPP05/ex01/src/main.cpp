/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 10:31:32 by mrios-he          #+#    #+#             */
/*   Updated: 2024/11/28 18:10:50 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat bob("Bob", 2);
		Form taxForm("Tax Form", 3, 5);
		std::cout << bob << std::endl;
		std::cout << taxForm << std::endl;
		bob.signForm(taxForm);
		std::cout << taxForm << std::endl;
		Bureaucrat alice("Jhon", 4);
		alice.signForm(taxForm);
	}
	catch (const std::runtime_error& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}