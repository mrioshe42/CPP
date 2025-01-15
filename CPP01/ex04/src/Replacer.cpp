/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:19:05 by mrios-he          #+#    #+#             */
/*   Updated: 2024/11/20 18:19:06 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"

Replacer::Replacer(const std::string& filename, const std::string& s1, const std::string& s2)
	: filename(filename), s1(s1), s2(s2)
{
}

bool Replacer::validateInputs(void) const
{
	if (this->filename.empty())
	{
		std::cerr << "Error: Empty filename" << std::endl;
		return (false);
	}
	if (this->s1.empty())
	{
		std::cerr << "Error: Empty search string" << std::endl;
		return (false);
	}
	return (true);
}

std::string Replacer::processLine(const std::string& line) const
{
	std::string result;
	size_t start = 0;
	size_t pos;

	while ((pos = line.find(this->s1, start)) != std::string::npos)
	{
		result += line.substr(start, pos - start);
		result += this->s2;
		start = pos + this->s1.length();
	}
	result += line.substr(start);
	return (result);
}

bool Replacer::replace(void) const
{
	if (!validateInputs())
		return (false);
	std::ifstream inFile(this->filename.c_str());
	if (!inFile.is_open())
	{
		std::cerr << "Error: Could not open input file: " << this->filename << std::endl;
		return (false);
	}
	std::string outFilename = this->filename + ".replace";
	std::ofstream outFile(outFilename.c_str());
	if (!outFile.is_open())
	{
		std::cerr << "Error: Could not create output file: " << outFilename << std::endl;
		inFile.close();
		return (false);
	}
	std::string line;
	while (std::getline(inFile, line))
	{
		outFile << processLine(line);
		if (!inFile.eof())
			outFile << std::endl;
	}
	inFile.close();
	outFile.close();
	return (true);
}
