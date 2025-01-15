/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:09:49 by mrios-he          #+#    #+#             */
/*   Updated: 2024/11/26 11:22:04 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_CAT_HPP
# define WRONG_CAT_HPP
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat()
		{
			type = "Wrong Cat";
			std::cout << "WrongCat constructor called" << std::endl;
		}
		~WrongCat()
		{
			std::cout << "WrongCat destructor called" << std::endl;
		}
		void makeSound() const
		{
			std::cout << "Wrong Meow! 🐅" << std::endl;
		}
};

#endif