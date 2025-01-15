/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:15:53 by mrios-he          #+#    #+#             */
/*   Updated: 2024/11/27 17:06:03 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

void testBasicFunctionality()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
}

void testInventoryLimits()
{
	Character* hero = new Character("Hero");	
	for (int i = 0; i < 6; i++)
	{
		AMateria* mat = (i % 2 == 0) ? static_cast<AMateria*>(new Ice()) 
									: static_cast<AMateria*>(new Cure());
		std::cout << "Equipping materia " << i + 1 << std::endl;
		hero->equip(mat);
		if (i >= 4)
			delete mat;
	}
	ICharacter* target = new Character("Target");
	for (int i = 0; i < 4; i++)
		hero->use(i, *target);
	delete target;
	delete hero;
}

void testDeepCopy()
{
	std::cout << "\n=== Testing Deep Copy ===" << std::endl;
	Character* original = new Character("Original");
	original->equip(new Ice());
	original->equip(new Cure());
	Character* copy = new Character(*original);
	ICharacter* target = new Character("Target");

	std::cout << "Original using materias:" << std::endl;
	original->use(0, *target);
	original->use(1, *target);
	std::cout << "Copy using materias:" << std::endl;
	copy->use(0, *target);
	copy->use(1, *target);
	delete target;
	delete copy;
	delete original;
}

void testMateriaSource()
{
	IMateriaSource* src = new MateriaSource();
	for (int i = 0; i < 4; i++)
	{
		AMateria* mat = (i % 2 == 0) ? static_cast<AMateria*>(new Ice()) 
									: static_cast<AMateria*>(new Cure());
		src->learnMateria(mat);
	}
	AMateria* tmp1 = src->createMateria("ice");
	AMateria* tmp2 = src->createMateria("cure");
	AMateria* tmp3 = src->createMateria("unknown");
	if (tmp1)
	{
		std::cout << "Successfully created Ice materia" << std::endl;
		delete tmp1;
	}
	if (tmp2)
	{
		std::cout << "Successfully created Cure materia" << std::endl;
		delete tmp2;
	}
	if (!tmp3)
		std::cout << "Failed to create unknown materia (as expected)" << std::endl;
	delete src;
}

void testUnequip()
{
	Character* hero = new Character("Hero");
	AMateria* ice = new Ice();
	AMateria* cure = new Cure();
	hero->equip(ice);
	hero->equip(cure);
	ICharacter* target = new Character("Target");
	std::cout << "Before unequip:" << std::endl;
	hero->use(0, *target);
	hero->use(1, *target);
	AMateria* unequipped = ice;
	hero->unequip(0);
	std::cout << "\nAfter unequip:" << std::endl;
	hero->use(0, *target);
	hero->use(1, *target);
	delete unequipped;
	delete target;
	delete hero;
}

int main()
{
	testBasicFunctionality();
	testInventoryLimits();
	testMateriaSource();
	testUnequip();
	testDeepCopy();
	return 0;
}