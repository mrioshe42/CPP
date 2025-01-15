/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:18:57 by mrios-he          #+#    #+#             */
/*   Updated: 2024/11/20 18:18:58 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACER_HPP
# define REPLACER_HPP
# include <string>
# include <fstream>
# include <iostream>

class Replacer
{
	private:
		std::string     filename;
		std::string     s1;
		std::string     s2;
		
		bool            validateInputs(void) const;
		std::string     processLine(const std::string& line) const;

	public:
		Replacer(const std::string& filename, const std::string& s1, const std::string& s2);
		bool            replace(void) const;
};

#endif