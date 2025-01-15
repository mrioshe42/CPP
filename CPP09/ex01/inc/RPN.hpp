/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:13:02 by mrios-he          #+#    #+#             */
/*   Updated: 2025/01/10 19:06:01 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP
# include <deque>
# include <string>
# include <sstream>
# include <stdexcept>
# include <iostream>

class RPN
{
	private:
		std::deque<short> _numbers;
		bool isOperator(const std::string& token);
		bool isNumber(const std::string& token);
		short performOperation(short a, short b, const std::string& op);

	public:
		RPN();
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		~RPN();
		short calculate(const std::string& expression);
};

#endif