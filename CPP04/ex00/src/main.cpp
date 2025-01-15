/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:54:38 by mrios-he          #+#    #+#             */
/*   Updated: 2024/11/26 14:45:46 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
		
	std::cout << "j's type: " << j->getType() << std::endl;
	std::cout << "i's type: " << i->getType() << std::endl;
	std::cout << "meta's type: " << meta->getType() << std::endl;

	std::cout << "j (Dog) makes sound: ";
	j->makeSound();
	std::cout << "i (Cat) makes sound: ";
	i->makeSound();
	std::cout << "meta (Animal) makes sound: ";
	meta->makeSound();

	delete j;
	delete i;
	delete meta;

	const WrongAnimal* wrong_meta = new WrongAnimal();
	const WrongAnimal* wrong_cat = new WrongCat();

	std::cout << "wrong_cat's type: " << wrong_cat->getType() << std::endl;
	std::cout << "wrong_meta's type: " << wrong_meta->getType() << std::endl;

	std::cout << "wrong_cat makes sound: ";
	wrong_cat->makeSound();
	std::cout << "wrong_meta makes sound: ";
	wrong_meta->makeSound();
	
	WrongCat direct_wrong_cat;
	std::cout << "direct_wrong_cat makes sound: ";
	direct_wrong_cat.makeSound();
		
	delete wrong_meta;
	delete wrong_cat;
	return 0;
}
