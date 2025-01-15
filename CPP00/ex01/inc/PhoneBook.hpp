/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:55:53 by mrios-he          #+#    #+#             */
/*   Updated: 2024/11/19 14:56:22 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"

#define MAX_CONTACTS 8
#define COLUMN_WIDTH 10
#define SEPARATOR "#"

class PhoneBook
{
	private:

	int		index;
	int		nbr_contacts;
	Contact	contacts[MAX_CONTACTS];

	public:

	PhoneBook();
	~PhoneBook();
	int		add_contact(Contact contact);
	int		display_list(int nbr_contact) const;
	void	display_contact(int index) const;
	int		get_phone() const;
};

#endif