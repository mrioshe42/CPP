/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:20:22 by mrios-he          #+#    #+#             */
/*   Updated: 2024/11/26 16:46:05 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain created!" << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = "Empty thought";
}

Brain::Brain(const Brain& other)
{
	std::cout << "Brain copied." << std::endl;
	*this = other;
}

Brain::~Brain()
{
	std::cout << "Brain destroyed." << std::endl;
}

Brain& Brain::operator=(const Brain& other)
{
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			ideas[i] = other.ideas[i];
	}
	return (*this);
}

const std::string& Brain::getIdea(int index) const
{
	static const std::string invalid = "Invalid index";
	if (index >= 0 && index < 100)
		return (ideas[index]);
	return (invalid);
}

void Brain::setIdea(int index, const std::string& idea)
{
	if (index >= 0 && index < 100)
		ideas[index] = idea;
}