/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 16:18:07 by mrios-he          #+#    #+#             */
/*   Updated: 2025/01/03 11:51:17 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span()
{
	_N = 0;
}

Span::Span(unsigned int n)
{
	_N = n;
}

Span::Span(const Span& other)
{
	_N = other._N;
	_numbers = other._numbers;
}

Span::~Span()
{
}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		_N = other._N;
		_numbers = other._numbers;
	}
	return (*this);
}

void Span::addNumber(int number)
{
	if (_numbers.size() >= _N)
		throw std::runtime_error("Span is full");
	_numbers.push_back(number);
}

unsigned int Span::shortestSpan() const
{
	if (_numbers.size() <= 1)
		throw std::runtime_error("Not enough numbers to find span");

	std::vector<int> sorted(_numbers);
	std::sort(sorted.begin(), sorted.end());

	unsigned int minSpan = static_cast<unsigned int>(-1);
	for (size_t i = 1; i < sorted.size(); ++i)
	{
		unsigned int span = static_cast<unsigned int>(sorted[i] - sorted[i - 1]);
		if (span < minSpan)
			minSpan = span;
	}
	return (minSpan);
}

unsigned int Span::longestSpan() const
{
	if (_numbers.size() <= 1)
		throw std::runtime_error("Not enough numbers to find span");

	std::vector<int>::const_iterator min = std::min_element(_numbers.begin(), _numbers.end());
	std::vector<int>::const_iterator max = std::max_element(_numbers.begin(), _numbers.end());

	return static_cast<unsigned int>(*max - *min);
}
