/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 09:56:00 by mrios-he          #+#    #+#             */
/*   Updated: 2024/11/30 15:41:15 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <string>
# include <iostream>
# include <cstdlib>
# include <limits>
# include <cmath>

class ScalarConverter
{
	private:
		ScalarConverter(); 
		ScalarConverter(const ScalarConverter&);
		~ScalarConverter();	
		static bool isChar(const std::string& literal);
		static bool isInt(const std::string& literal);
		static bool isFloat(const std::string& literal);
		static bool isDouble(const std::string& literal);
		
	public:
		static void convert(const std::string& literal);
};

#endif