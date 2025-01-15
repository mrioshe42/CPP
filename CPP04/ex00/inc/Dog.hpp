/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:03:39 by mrios-he          #+#    #+#             */
/*   Updated: 2024/11/26 14:27:08 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
#include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog()
		{
			type = "Dog";
			std::cout << "Dog constructor called" << std::endl;
		}
		~Dog()
		{
			std::cout << "Dog destructor called" << std::endl;
		}
		void makeSound() const
		{
			std::cout << "Woof! 🐶" << std::endl;
		}
};

#endif