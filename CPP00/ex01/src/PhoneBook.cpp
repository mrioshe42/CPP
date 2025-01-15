/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:57:51 by mrios-he          #+#    #+#             */
/*   Updated: 2024/11/19 15:10:48 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : index(0), nbr_contacts(0)
{}

PhoneBook::~PhoneBook()
{}

int	PhoneBook::get_phone() const
{
	return (nbr_contacts);
}

int	PhoneBook::add_contact(Contact contact)
{
	if (index + 1 > 8)
		index = 0;
	if (contact.add_new(&contacts[index]))
		return (1);
	index++;
	if (nbr_contacts < 8)
		nbr_contacts++;
	return (0);
}

void PhoneBook::display_contact(int i) const
{
	contacts[i].print_contact();
}

static void print_header()
{
    std::cout << std::setfill(' ');
    std::cout << SEPARATOR;
    std::cout << std::setw(COLUMN_WIDTH) << "Index" << SEPARATOR;
    std::cout << std::setw(COLUMN_WIDTH) << "First name" << SEPARATOR;
    std::cout << std::setw(COLUMN_WIDTH) << "Last name" << SEPARATOR;
    std::cout << std::setw(COLUMN_WIDTH - 1) << "Nickname" << SEPARATOR;
    std::cout << std::endl;
}

static void print_separator_line()
{
    std::cout << std::string(COLUMN_WIDTH * 4 + 4, '#') << std::endl;
}

int PhoneBook::display_list(int nbr) const
{
    if (nbr == 0)
    {
        std::cout << std::right << "Phone book is empty" << std::endl;
        return (1);
    }
    print_separator_line();
    print_header();
    print_separator_line();
    for (int i = 0; i < nbr; i++)
        contacts[i].list_contact(i);
    print_separator_line();
    return (0);
}
