/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:54:38 by mrios-he          #+#    #+#             */
/*   Updated: 2024/11/26 17:47:56 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

void testDeepCopy()
{
	std::cout << "\nCreating and clone:" << std::endl;
	Dog* original = new Dog();
	original->getBrain()->setIdea(0, "I love bones!");
	Dog* clone = new Dog(*original);
	std::cout << "Original dog's first idea: " << original->getBrain()->getIdea(0) << std::endl;
	std::cout << "Cloned dog's first idea: " << clone->getBrain()->getIdea(0) << std::endl;
	clone->getBrain()->setIdea(0, "I love different bones!");
	std::cout << "\nAfter modifying clone:" << std::endl;
	std::cout << "Original dog's first idea: " << original->getBrain()->getIdea(0) << std::endl;
	std::cout << "Cloned dog's first idea: " << clone->getBrain()->getIdea(0) << std::endl;
	delete original;
	delete clone;
}

int main()
{
	const int arraySize = 10;
	Animal* animals[arraySize];
	
	for (int i = 0; i < arraySize; i++)
	{
		if (i < arraySize / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	for (int i = 0; i < arraySize; i++)
	{
		std::cout << "Animal " << i << " (" << animals[i]->getType() << "): ";
		animals[i]->makeSound();
	}
	for (int i = 0; i < arraySize; i++)
		delete animals[i];
	testDeepCopy();
	return 0;
}
