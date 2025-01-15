/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:13:51 by mrios-he          #+#    #+#             */
/*   Updated: 2025/01/14 15:53:30 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::~PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	*this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		vec = other.vec;
		lst = other.lst;
	}
	return (*this);
}

void PmergeMe::fordJohnsonVector(std::vector<int> &arr)
{
	int		straggler;
	int		first;
	int		second;
	bool	hasStraggler;

	if (arr.size() <= 1)
		return ;
	std::vector<std::pair<int, int> > pairs;
	hasStraggler = (arr.size() % 2 == 1);
	straggler = hasStraggler ? arr.back() : 0;

	std::vector<int>::iterator it = arr.begin();
	while (std::distance(it, arr.end()) >= 2)
	{
		first = *it++;
		second = *it++;
		pairs.push_back(std::make_pair(std::max(first, second), std::min(first, second)));
	}
	std::sort(pairs.begin(), pairs.end());
	arr.clear();
	std::vector<int> smaller;
	for (size_t i = 0; i < pairs.size(); ++i)
	{
		arr.push_back(pairs[i].first);
		smaller.push_back(pairs[i].second);
	}
	for (size_t i = 0; i < smaller.size(); ++i)
	{
		std::vector<int>::iterator it = std::lower_bound(arr.begin(), arr.end(), smaller[i]);
		arr.insert(it, smaller[i]);
	}
	if (hasStraggler)
	{
		std::vector<int>::iterator it = std::lower_bound(arr.begin(), arr.end(), straggler);
		arr.insert(it, straggler);
	}
}

void PmergeMe::fordJohnsonList(std::list<int> &lst)
{
	bool	hasStraggler;
	int		straggler;
	int		first;
	int		second;

	if (lst.size() <= 1)
		return ;
	std::list<std::pair<int, int> > pairs;
	hasStraggler = (lst.size() % 2 == 1);
	straggler = hasStraggler ? lst.back() : 0;

	std::list<int>::iterator it = lst.begin();
	while (std::distance(it, lst.end()) >= 2)
	{
		first = *it++;
		second = *it++;
		pairs.push_back(std::make_pair(std::max(first, second), std::min(first, second)));
	}
	pairs.sort();
	lst.clear();
	std::list<int> smaller;
	for (std::list<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
	{
		lst.push_back(it->first);
		smaller.push_back(it->second);
	}
	for (std::list<int>::iterator small_it = smaller.begin(); small_it != smaller.end(); ++small_it)
	{
		std::list<int>::iterator insert_pos = lst.begin();
		while (insert_pos != lst.end() && *insert_pos < *small_it)
		{
			++insert_pos;
		}
		lst.insert(insert_pos, *small_it);
	}
	if (hasStraggler)
	{
		std::list<int>::iterator insert_pos = lst.begin();
		while (insert_pos != lst.end() && *insert_pos < straggler)
		{
			++insert_pos;
		}
		lst.insert(insert_pos, straggler);
	}
}

bool PmergeMe::processInput(int argc, char** argv)
{
	char*	endPtr;
	long	num;

	if (argc < 2)
		return (false);    
	for (int i = 1; i < argc; ++i)
	{
		num = std::strtol(argv[i], &endPtr, 10);
		if (*endPtr != '\0' || num <= 0 || num > INT_MAX)
			return (false);
		for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
		{
			if (*it == static_cast<int>(num))
				return (false);
		}
		vec.push_back(static_cast<int>(num));
		lst.push_back(static_cast<int>(num));
	}
	return (true);
}

void PmergeMe::sort()
{
	clock_t total_time_vec = 0;
	clock_t total_time_lst = 0;

	clock_t start_vec = clock();
	fordJohnsonVector(vec);
	clock_t end_vec = clock();
	total_time_vec = (end_vec - start_vec);
	
	clock_t start_lst = clock();
	fordJohnsonList(lst);
	clock_t end_lst = clock();
	total_time_lst = (end_lst - start_lst);
	
	displayAfter();
	double time_vec = static_cast<double>(total_time_vec) / CLOCKS_PER_SEC * 1000000;
	double time_lst = static_cast<double>(total_time_lst) / CLOCKS_PER_SEC * 1000000;
	
	std::cout << "Time to process a range of " << vec.size() 
			  << " elements with std::vector : " << std::fixed 
			  << std::setprecision(5) << time_vec << " us" << std::endl;
	
	std::cout << "Time to process a range of " << lst.size() 
			  << " elements with std::list : " << std::fixed 
			  << std::setprecision(5) << time_lst << " us" << std::endl;
}

void PmergeMe::displayBefore() const
{
	std::cout << "Before: ";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << vec[i] << " ";
	std::cout << std::endl;
}

void PmergeMe::displayAfter() const
{
	std::cout << "After: ";
	for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}
