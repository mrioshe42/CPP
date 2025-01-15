/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:18:47 by mrios-he          #+#    #+#             */
/*   Updated: 2024/11/20 18:18:48 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string const &type) : type(type)
{
}

const std::string& Weapon::getType(void) const
{
	return this->type;
}

void Weapon::setType(std::string const &type)
{
	this->type = type;
}
