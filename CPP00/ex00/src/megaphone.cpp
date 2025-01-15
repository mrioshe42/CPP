/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:59:28 by mrios-he          #+#    #+#             */
/*   Updated: 2024/11/19 10:42:28 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#define DEFAULT_MSG "* LOUD AND UNBEARABLE FEEDBACK NOISE *"

int main(int argc, char **argv)
{
	if (argc > 1)
	{
		std::string output;
		for (int i = 1; i < argc; i++)
        {
            if (i > 1)
                output += " ";
            for (int j = 0; argv[i][j]; j++)
                output += toupper(argv[i][j]);
        }
		std::cout << output << std::endl;
		return 0;
	}
	else
		std::cout << DEFAULT_MSG << std::endl;
	return 0;
}
