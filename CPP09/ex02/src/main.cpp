/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:13:37 by mrios-he          #+#    #+#             */
/*   Updated: 2025/01/13 13:07:38 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char** argv)
{
	PmergeMe sorter;
	
	if (!sorter.processInput(argc, argv))
	{
		std::cerr << "Error" << std::endl;
		return (1);
	}
	sorter.displayBefore();
	sorter.sort();
	return (0);
}
