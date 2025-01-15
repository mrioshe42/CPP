/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:08:01 by mrios-he          #+#    #+#             */
/*   Updated: 2024/11/26 11:24:28 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP
# include <string>
# include <iostream>

class WrongAnimal
{
	protected:
		std::string type;
	public:
		WrongAnimal()
		{
			type = "Wrong Animal";
			std::cout << "WrongAnimal constructor called" << std::endl;
		}
		~WrongAnimal()
		{
			std::cout << "WrongAnimal destructor called" << std::endl;
		}
		void makeSound() const
		{
			std::cout << "* wrong sound 🌀*" << std::endl;
		}
		std::string getType() const
		{
			return (type);
		}
};

#endif