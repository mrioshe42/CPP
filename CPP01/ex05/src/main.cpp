/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:19:24 by mrios-he          #+#    #+#             */
/*   Updated: 2024/11/20 18:19:25 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl harl;
	
	if (argc != 2)
	{
		std::cout << "Usage: ./harl <level>" << std::endl;
		std::cout << "Levels: DEBUG, INFO, WARNING, ERROR" << std::endl;
		return (1);
	}
	harl.complain(argv[1]);
	return (0);
}
