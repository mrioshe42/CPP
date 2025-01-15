/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 12:33:44 by mrios-he          #+#    #+#             */
/*   Updated: 2024/11/23 13:15:13 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(int argc, char **argv)
{
	unsigned int damage = 5;
	unsigned int repair = 3;
	ClapTrap clap("ClapTrap");
	
	if (argc == 3)
	{
		if (atoi(argv[1]) >= 0)
			damage = atoi(argv[1]);
		if (atoi(argv[2]) >= 0)
			repair = atoi(argv[2]);
	}
	clap.attack("Enemy");
	clap.takeDamage(damage);
	clap.beRepaired(repair);
	clap.attack("Enemy");
	clap.takeDamage(damage);
	clap.beRepaired(repair);
	clap.attack("Enemy");
	clap.takeDamage(damage);
	clap.beRepaired(repair);
	clap.attack("Enemy");
	clap.takeDamage(damage);
	clap.beRepaired(repair);
	return (0);
}
