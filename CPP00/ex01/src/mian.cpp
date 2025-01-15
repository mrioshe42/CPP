/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mian.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:24:57 by mrios-he          #+#    #+#             */
/*   Updated: 2024/11/19 14:37:30 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

static void displayMenu()
{
    std::cout << std::endl;
    std::cout << "Choose a command:" << std::endl;
    std::cout << "ADD\t: Add a new contact" << std::endl;
    std::cout << "SEARCH\t: Search for a contact" << std::endl;
    std::cout << "EXIT\t: Exit the program" << std::endl;
    std::cout << "> ";
}

static bool handleSearch(PhoneBook &book)
{
    std::string input;
    int         index;

    if (book.display_list(book.get_phone()))
        return true;
    std::cout << "Enter index to display (1-" << book.get_phone() << "): ";
    if (!std::getline(std::cin, input))
        return false;
    index = std::atoi(input.c_str()) - 1;
    if (index >= 0 && index < book.get_phone())
        book.display_contact(index);
    else
        std::cout << "Invalid index!" << std::endl;
    return true;
}

static bool handleAdd(PhoneBook &book)
{
    Contact newContact;
    
    if (book.add_contact(newContact))
        return false;
    return true;
}

int main(void)
{
    PhoneBook    book;
    std::string  input;
    bool         running;

    running = true;
    std::cout << "Welcome to PhoneBook!" << std::endl;
    while (running)
    {
        displayMenu();
        if (!std::getline(std::cin, input))
            break ;
        if (input == "EXIT")
            running = false;
        else if (input == "ADD")
        {
            if (!handleAdd(book))
                break ;
        }
        else if (input == "SEARCH")
        {
            if (!handleSearch(book))
                break ;
        }
    }
    std::cout << "\nGoodbye!" << std::endl;
    return 0;
}
