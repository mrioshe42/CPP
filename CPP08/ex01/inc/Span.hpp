/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 16:18:35 by mrios-he          #+#    #+#             */
/*   Updated: 2025/01/03 11:41:25 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP
# include <vector>
# include <algorithm>
# include <stdexcept>
# include <climits>
# include <list>
# include <deque>
# include <ctime>
# include <cstdlib>
# include <iostream>

class Span
{
	private:
		unsigned int        _N;
		std::vector<int>   _numbers;
		Span();

	public:
		Span(unsigned int n);
		Span(const Span& other);
		~Span();
		Span& operator=(const Span& other);
		void addNumber(int number);
		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;

		template <typename Iterator>
		void addNumbers(Iterator begin, Iterator end)
		{
			while (begin != end)
			{
				if (_numbers.size() >= _N)
					throw std::runtime_error("Span is full");
				_numbers.push_back(*begin);
				++begin;
			}
		}
};

#endif
