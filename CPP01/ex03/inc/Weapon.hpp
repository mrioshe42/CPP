/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:18:33 by mrios-he          #+#    #+#             */
/*   Updated: 2024/11/20 18:18:34 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <string>
# include <string>
# include <iostream>

class Weapon
{
	private:
		std::string type;

	public:
		Weapon(std::string const &type);
		const std::string& getType(void) const;
		void setType(std::string const &type);
};

#endif