/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:55:18 by mrios-he          #+#    #+#             */
/*   Updated: 2024/11/26 17:14:01 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Abstract Animal")
{
	std::cout << "Animal constructor: A theoretical being forms..." << std::endl;
}

Animal::Animal(const Animal& other) : type(other.type)
{
	std::cout << "Animal copy constructor: Abstractly duplicating..." << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal destructor: Abstractly fading away..." << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
	if (this != &other)
		type = other.type;
	return (*this);
}

std::string Animal::getType() const
{
	return (type);
}