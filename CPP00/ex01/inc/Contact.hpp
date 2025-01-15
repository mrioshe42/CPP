/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:59:02 by mrios-he          #+#    #+#             */
/*   Updated: 2024/11/19 13:44:38 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <csignal>
#include <cstdlib>
#include <iomanip>
#include <cctype>

class Contact
{
	public:

	Contact();
	~Contact();
	int		add_new(Contact *contact);
	void	print_contact() const;
	void	list_contact(int i) const;

	private:

	std::string name;
	std::string surname;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;
};

#endif