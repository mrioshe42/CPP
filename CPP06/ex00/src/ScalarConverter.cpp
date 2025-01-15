/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 09:56:14 by mrios-he          #+#    #+#             */
/*   Updated: 2024/11/30 16:19:29 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

bool ScalarConverter::isChar(const std::string& literal)
{
	return (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'');
}

bool ScalarConverter::isInt(const std::string& literal)
{
	if (literal.empty())
		return (false);
	size_t i = 0;
	if (literal[0] == '-' || literal[0] == '+')
		i++;
	for (; i < literal.length(); i++)
		if (!isdigit(literal[i]))
			return (false);
	return (true);
}

bool ScalarConverter::isFloat(const std::string& literal)
{
	if (literal.empty())
		return (false);
	return (literal[literal.length() - 1] == 'f');
}

bool ScalarConverter::isDouble(const std::string& literal)
{
	size_t dots = 0;

	if (literal.empty())
		return false;
	for (size_t i = 0; i < literal.length(); i++)
	{
		if (literal[i] == '.')
			dots++;
		if (dots > 1)
			return (false);
	}
	return (dots == 1);
}

static char parseChar(const std::string& literal)
{
	if (literal.length() == 1)
		return (literal[0]);
	if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'')
		return (literal[1]);
	if (literal.length() == 2 && literal[0] == '\\')
	{
		switch(literal[1])
		{
			case 'n':
				return ('\n');
			case 't':
				return ('\t');
			case '0':
				return ('\0');
			default:
				return literal[1];
		}
	}
	return ('\0');
}

void ScalarConverter::convert(const std::string& literal)
{
	char c;
	char* endptr;
	double value;

	if (literal.length() <= 3)
	{
		c = parseChar(literal);
		if (c != '\0')
		{ 
			std::cout << "char: ";
			if (isprint(c))
				std::cout << "'" << c << "'";
			else
				std::cout << "Non displayable";
			std::cout << std::endl;
			std::cout << "int: " << static_cast<int>(c) << std::endl;
			std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
			std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
			return ;
		}
	}
	
	if (isChar(literal))
	{
		c = literal[1];
		std::cout << "char: '" << c << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
		return ;
	}
	
	if (literal == "nan" || literal == "nanf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return ;
	}

	if (literal == "+inf" || literal == "-inf" || literal == "+inff" || literal == "-inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << (literal[0] == '-' ? "-" : "+") << "inff" << std::endl;
		std::cout << "double: " << (literal[0] == '-' ? "-" : "+") << "inf" << std::endl;
		return ;
	}
	value = strtod(literal.c_str(), &endptr);
	
	if (value >= 32 && value <= 126)
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;

	if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min() || isnan(value))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;

	std::cout << "float: " << static_cast<float>(value);
	if (static_cast<float>(value) == static_cast<int>(value))
		std::cout << ".0";
	std::cout << "f" << std::endl;

	std::cout << "double: " << value;
	if (value == static_cast<int>(value))
		std::cout << ".0";
	std::cout << std::endl;
}