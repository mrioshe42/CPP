/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 14:09:47 by mrios-he          #+#    #+#             */
/*   Updated: 2024/11/25 15:15:55 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) :
	ClapTrap(name + "_clap_name"),
	ScavTrap(name),
	FragTrap(name),
	name(name)
{
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScavTrap::energyPoints;
	this->attackDamage = FragTrap::attackDamage;
	
	std::cout << "DiamondTrap " << this->name << " is constructed, combining the best of both worlds!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : 
	ClapTrap(other),
	ScavTrap(other),
	FragTrap(other),
	name(other.name)
{
	std::cout << "DiamondTrap " << this->name << " has been cloned!" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << this->name << " is being deconstructed!" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		name = other.name;
	}
	std::cout << "DiamondTrap " << this->name << " has been assigned!" << std::endl;
	return (*this);
}

void DiamondTrap::whoAmI()
{
	std::cout << "I am DiamondTrap " << name << ", also known as ClapTrap " 
			  << ClapTrap::name << "!" << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}
