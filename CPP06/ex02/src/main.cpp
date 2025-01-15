/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 13:01:40 by mrios-he          #+#    #+#             */
/*   Updated: 2024/11/30 16:27:54 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identify.hpp"

int main()
{
	Base* ptr = generate();
	
	std::cout << "Using pointer identify: ";
	identify(ptr);
	
	std::cout << "Using reference identify: ";
	identify(*ptr);
	
	delete ptr;
	return 0;
}