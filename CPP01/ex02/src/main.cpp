/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:18:20 by mrios-he          #+#    #+#             */
/*   Updated: 2024/11/20 18:18:21 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	std::string     str = "HI THIS IS BRAIN";
	std::string*    stringPTR = &str;
	std::string&    stringREF = str;

	std::cout << "Memory addresses:" << std::endl;
	std::cout << "str address:\t\t" << &str << std::endl;
	std::cout << "stringPTR address:\t" << stringPTR << std::endl;
	std::cout << "stringREF address:\t" << &stringREF << std::endl;
	std::cout << "\nValues:" << std::endl;
	std::cout << "str value:\t\t" << str << std::endl;
	std::cout << "stringPTR value:\t" << *stringPTR << std::endl;
	std::cout << "stringREF value:\t" << stringREF << std::endl;
	return (0);
}
