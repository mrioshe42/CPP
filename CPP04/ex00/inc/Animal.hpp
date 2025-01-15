/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:02:06 by mrios-he          #+#    #+#             */
/*   Updated: 2024/11/26 13:32:02 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <string>
# include <iostream>

class Animal
{
	protected:
		std::string type;
	public:
		Animal()
		{
			type = "Generic Animal";
			std::cout << "Animal constructor called" << std::endl;
		}
		virtual ~Animal()
		{
			std::cout << "Animal destructor called" << std::endl;
		}
		virtual void makeSound() const
		{
			std::cout << "* silence *" << std::endl;
		}
		std::string getType() const
		{
			return (type);
		}
};

#endif