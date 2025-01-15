/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:11:23 by mrios-he          #+#    #+#             */
/*   Updated: 2025/01/09 16:40:33 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	loadDatabase("data.csv");
}

BitcoinExchange::BitcoinExchange(const std::string& databaseFile)
{
	loadDatabase(databaseFile);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	this->database = other.database;
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
		database = other.database;
	return (*this);
}

bool BitcoinExchange::isValidDate(const std::string& date) const
{
	int		year, month, day;
	char	delimiter;
	bool	isLeap;

	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return (false);
	for (size_t i = 0; i < date.length(); i++)
        if (i != 4 && i != 7 && !isdigit(date[i]))
            return (false);			
	std::istringstream iss(date);
	iss >> year >> delimiter >> month >> delimiter >> day;
	if (year < 2009 || year > 2022)
	{
		std::cerr << "[Date not present in the database] ";
		return (false);
	}
	if (month < 1 || month > 12 || day < 1 || day > 31)
		return (false);
	if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (day > 30)
			return (false);
	}
	else if (month == 2)
	{
		isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
		if (day > (isLeap ? 29 : 28)) 
			return (false);
	}
	return (true);
}

bool BitcoinExchange::isValidValue(const float value) const
{
	return (value >= 0 && value <= 1000);
}

float BitcoinExchange::stringToFloat(const std::string& str) const
{
	std::istringstream iss(str);
	float value;
	iss >> value;
	return (value);
}

std::string BitcoinExchange::findDate(const std::string& date) const
{
	std::map<std::string, float>::const_iterator it = database.lower_bound(date);
	if (it == database.begin())
		return (it->first);
	if (it == database.end() || it->first != date)
		--it;
	return (it->first);
}

void BitcoinExchange::loadDatabase(const std::string& filename)
{
	std::string	line;
	std::string	date;
	size_t		comma;
	float		value;

	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: could not open database file." << std::endl;
		return ;
	}
	std::getline(file, line);
	while (std::getline(file, line))
	{
		comma = line.find(',');
		if (comma != std::string::npos)
		{
			date = line.substr(0, comma);
			value = stringToFloat(line.substr(comma + 1));
			if (isValidDate(date))
				database[date] = value;
		}
	}
}

void BitcoinExchange::processInfile(const std::string& inputFile)
{
	std::string line;
	size_t separator;
	std::string date;
	float value;

	std::ifstream file(inputFile.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return ;
	}
	std::getline(file, line);
	while (std::getline(file, line))
	{
		separator = line.find(" | ");
		if (separator == std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue ;
		}
		date = line.substr(0, separator);
		if (!isValidDate(date))
		{
			std::cerr << "Error: bad input => " << date << std::endl;
			continue ;
		}
		std::string valueStr = line.substr(separator + 3);
		try
		{
			value = stringToFloat(valueStr);
		}
		catch (...)
		{
			std::cerr << "Error: invalid value." << std::endl;
			continue ;
		}
		if (value < 0)
		{
			std::cerr << "Error: not a positive number." << std::endl;
			continue ;
		}
		if (value > 1000)
		{
			std::cerr << "Error: too large a number." << std::endl;
			continue ;
		}
		std::string closestDate = findDate(date);	
		std::cout << date << " => " << value << " = " << value * database[closestDate] << std::endl;
	}
}
