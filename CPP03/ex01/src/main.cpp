/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 12:33:44 by mrios-he          #+#    #+#             */
/*   Updated: 2024/11/25 15:28:48 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(int argc, char **argv)
{
    unsigned int damage = 30;
    unsigned int repair = 20;
    
    if (argc == 3)
    {
        if (atoi(argv[1]) >= 0)
            damage = atoi(argv[1]);
        if (atoi(argv[2]) >= 0)
            repair = atoi(argv[2]);
    }
    ClapTrap clap("CT");
    clap.attack("Enemy");
    clap.takeDamage(damage);
    clap.beRepaired(repair);
    clap.attack("Enemy");

    ScavTrap scav("ST");
    scav.attack("Enemy");
    scav.takeDamage(damage);
    scav.beRepaired(repair);
    scav.guardGate();
    scav.attack("Enemy");
    return (0);
}
