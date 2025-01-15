/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:12:44 by mrios-he          #+#    #+#             */
/*   Updated: 2025/01/10 19:10:34 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const RPN &other)
{
	this->_numbers = other._numbers;	
}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
		_numbers = other._numbers;
	return (*this);
}

RPN::~RPN()
{
}

bool RPN::isOperator(const std::string &token)
{
	return (token == "+" || token == "-" || token == "*" || token == "/");
}

bool RPN::isNumber(const std::string &token)
{
	if (token.empty() || token.length() > 1)
		return (false);
	return (token[0] >= '0' && token[0] <= '9');
}

short RPN::performOperation(short a, short b, const std::string &op)
{
	if (op == "+")
		return (a + b);
	if (op == "-")
		return (a - b);
	if (op == "*")
		return (a * b);
	if (op == "/")
	{
		if (b == 0)
			throw std::runtime_error("Division by zero");
		return (a / b);
	}
	throw std::runtime_error("Invalid operator");
}

short RPN::calculate(const std::string &expression)
{
	std::istringstream iss(expression);
	std::string token;
	short	a;
	short	b;
	
	while (iss >> token)
	{
		if (isNumber(token))
			_numbers.push_back(static_cast<short>(token[0] - '0'));
		else if (isOperator(token))
		{
			if (_numbers.size() < 2)
				throw std::runtime_error("Not enough operands");
			b = _numbers.back(); 
			_numbers.pop_back();
			a = _numbers.back();
			_numbers.pop_back();
			_numbers.push_back(performOperation(a, b, token));
		}
		else if (token != " ")
			throw std::runtime_error("Invalid token: " + token);
	}
	if (_numbers.size() != 1)
		throw std::runtime_error("Invalid expression");
	return (_numbers.back());
}
