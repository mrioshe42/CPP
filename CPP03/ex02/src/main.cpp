/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 12:33:44 by mrios-he          #+#    #+#             */
/*   Updated: 2024/11/25 15:56:11 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <cstdlib>

int main(int argc, char **argv)
{
    unsigned int damage = 25;
    unsigned int repair = 15;
    
    if (argc == 3)
    {
        if (atoi(argv[1]) >= 0)
            damage = atoi(argv[1]);
        if (atoi(argv[2]) >= 0)
            repair = atoi(argv[2]);
    }

    ClapTrap clap("CT-1");
    clap.attack("Enemy");
    clap.takeDamage(damage);
    clap.beRepaired(repair);

    ScavTrap scav("ST-1");
    scav.attack("Enemy");
    scav.takeDamage(damage);
    scav.beRepaired(repair);
    scav.guardGate();

    FragTrap frag("FT-1");
    frag.attack("Enemy");
    frag.takeDamage(damage);
    frag.beRepaired(repair);
    frag.highFivesGuys();

    return (0);
}
