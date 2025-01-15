/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 13:46:43 by mrios-he          #+#    #+#             */
/*   Updated: 2024/11/25 15:23:32 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "FragTrap " << name << " has been assembled!" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << "FragTrap " << name << " has been cloned!" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << name << " is shutting down...!" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	if (this != &other)
		ClapTrap::operator=(other);
	std::cout << "FragTrap " << name << " settings have been copied!" << std::endl;
	return (*this);
}

void FragTrap::attack(const std::string& target)
{
	if (energyPoints == 0)
	{
		std::cout << "FragTrap " << name << " is out of energy to attack!" << std::endl;
		return ;
	}
	if (hitPoints == 0)
	{
		std::cout << "FragTrap " << name << " is too damaged to attack!" << std::endl;
		return ;
	}
	energyPoints--;
	std::cout << "FragTrap " << name << " unleashes a powerful attack on " << target 
			  << ", dealing " << attackDamage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << name << " enthusiastically requests high fives from everyone! ✋" << std::endl;
}