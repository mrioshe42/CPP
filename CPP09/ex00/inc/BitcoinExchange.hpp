/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:11:41 by mrios-he          #+#    #+#             */
/*   Updated: 2025/01/09 16:40:40 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# include <map>
# include <string>
# include <fstream>
# include <iostream>
# include <cstdlib>
# include <sstream>

class BitcoinExchange
{
	private:
		bool isValidDate(const std::string& date) const;
		bool isValidValue(const float value) const;
		void loadDatabase(const std::string& filename);
		float stringToFloat(const std::string& str) const;
		std::string findDate(const std::string& date) const;
		std::map<std::string, float> database;

	public:
		BitcoinExchange();
		BitcoinExchange(const std::string& databaseFile);
		BitcoinExchange(const BitcoinExchange& other);
		~BitcoinExchange();
		BitcoinExchange& operator=(const BitcoinExchange& other);
		void processInfile(const std::string& inputFile);
};

#endif
