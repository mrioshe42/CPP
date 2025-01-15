/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 12:33:44 by mrios-he          #+#    #+#             */
/*   Updated: 2024/11/23 14:42:20 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

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
    DiamondTrap diamond("DT");
    diamond.attack("Enemy");
    diamond.takeDamage(damage);
    diamond.beRepaired(repair);
    diamond.guardGate();
    diamond.highFivesGuys();
    diamond.whoAmI();
    return (0);
}
