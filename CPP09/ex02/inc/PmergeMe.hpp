/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:14:14 by mrios-he          #+#    #+#             */
/*   Updated: 2025/01/14 14:21:15 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <vector>
# include <list>
# include <set>
# include <iostream>
# include <ctime>
# include <iomanip>
# include <cstdlib>
# include <algorithm>
# include <utility>
# include <climits>

class PmergeMe
{
	private:
		std::vector<int> vec;
		std::list<int> lst;
		void fordJohnsonVector(std::vector<int> &arr);
		void fordJohnsonList(std::list<int> &lst);

	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		bool processInput(int argc, char** argv);
		void sort();
		void displayBefore() const;
		void displayAfter() const;
};

#endif
