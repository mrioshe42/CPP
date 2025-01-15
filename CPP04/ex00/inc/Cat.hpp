/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:06:34 by mrios-he          #+#    #+#             */
/*   Updated: 2024/11/26 14:27:17 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
#include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat()
		{
			type = "Cat";
			std::cout << "Cat constructor called" << std::endl;
		}
		~Cat()
		{
			std::cout << "Cat destructor called" << std::endl;
		}
		void makeSound() const
		{
			std::cout << "Meow! 🐱" << std::endl;
		}
};

#endif