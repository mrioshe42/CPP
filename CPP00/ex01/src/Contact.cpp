/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:59:50 by mrios-he          #+#    #+#             */
/*   Updated: 2024/11/19 15:09:22 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{}

Contact::~Contact()
{}

void Contact::print_contact() const
{
    std::cout << "*******************************************" << std::endl;
    std::cout << "First name: " << name << std::endl;
    std::cout << "Last name: " << surname << std::endl;
    std::cout << "Nick name: " << nickname << std::endl;
    std::cout << "Phone number: " << phone_number << std::endl;
    std::cout << "Darkest secret: " << darkest_secret << std::endl;
    std::cout << "*******************************************" << std::endl;
}

static bool isOnlyLetters(const std::string &str)
{
    std::string::const_iterator it;
    for (it = str.begin(); it != str.end(); ++it)
    {
        if (!std::isalpha(*it) && !std::isspace(*it))
            return (false);
    }
    return (true);
}

static bool isOnlyNumbers(const std::string &str)
{
    std::string::const_iterator it;
    for (it = str.begin(); it != str.end(); ++it)
    {
        if (!std::isdigit(*it))
            return (false);
    }
    return (true);
}

static std::string getInput(const std::string &prompt, bool (*validator)(const std::string &) = NULL)
{
    std::string input;
    bool valid = false;

    while (!valid)
    {
        std::cout << prompt;
        if (!std::getline(std::cin, input))
            return "";
        if (input.empty())
        {
            std::cout << "Error: Field cannot be empty. Please try again." << std::endl;
            continue ;
        }
        if (validator && !validator(input))
        {
            if (validator == isOnlyLetters)
                std::cout << "Error: Only letters and spaces are allowed. Please try again." << std::endl;
            else if (validator == isOnlyNumbers)
                std::cout << "Error: Only numbers are allowed. Please try again." << std::endl;
            continue ;
        }
        valid = true;
    }
    return (input);
}

int Contact::add_new(Contact *contact)
{
    std::string input;

    input = getInput("Enter First Name : ", isOnlyLetters);
    if (input.empty())
        return (1);
    contact->name = input;
    input = getInput("Enter Last Name : ", isOnlyLetters);
    if (input.empty())
        return (1);
    contact->surname = input;
    input = getInput("Enter Nickname : ");
    if (input.empty())
        return (1);
    contact->nickname = input;
    input = getInput("Enter Phone Number : ", isOnlyNumbers);
    if (input.empty())
        return (1);
    contact->phone_number = input;
    input = getInput("Enter Darkest Secret : ");
    if (input.empty())
        return (1);
    contact->darkest_secret = input;
    return (0);
}

void Contact::list_contact(int i) const
{
    std::cout << std::right << std::setw(10) << (i + 1) << "|";
    if (name.size() > 10)
        std::cout << std::right << std::setw(9) << name.substr(0, 9) << "." << "|";
    else
        std::cout << std::right << std::setw(10) << name << "|";
    if (surname.size() > 10)
        std::cout << std::right << std::setw(9) << surname.substr(0, 9) << "." << "|";
    else
        std::cout << std::right << std::setw(10) << surname << "|";
    if (nickname.size() > 10)
        std::cout << std::right << std::setw(9) << nickname.substr(0, 9) << "." << "#" << std::endl;
    else
        std::cout << std::right << std::setw(10) << nickname << "#" << std::endl;
}
