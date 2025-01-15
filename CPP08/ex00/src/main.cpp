/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 16:16:44 by mrios-he          #+#    #+#             */
/*   Updated: 2025/01/03 11:51:29 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
	try
	{
		std::vector<int> vec;
		vec.push_back(1);
		vec.push_back(2);
		vec.push_back(3);
		vec.push_back(4);
		vec.push_back(5);
		std::vector<int>::iterator vec_result = easyfind(vec, 3);
		std::cout << "Found value in vector at position: " 
				  << std::distance(vec.begin(), vec_result) << std::endl;

		std::list<int> lst;
		lst.push_back(10);
		lst.push_back(20);
		lst.push_back(30);
		lst.push_back(40);
		lst.push_back(50);
		std::list<int>::iterator lst_result = easyfind(lst, 30);
		std::cout << "Found value in list at position: " 
				  << std::distance(lst.begin(), lst_result) << std::endl;

		std::deque<int> deq;
		deq.push_back(100);
		deq.push_back(200);
		deq.push_back(300);
		deq.push_back(400);
		deq.push_back(500);
		std::deque<int>::iterator deq_result = easyfind(deq, 300);
		std::cout << "Found value in deque at position: " 
				  << std::distance(deq.begin(), deq_result) << std::endl;

		std::vector<int> vec2;
		vec2.push_back(1);
		vec2.push_back(2);
		vec2.push_back(3);
		vec2.push_back(4);
		vec2.push_back(5);
		easyfind(vec2, 10);
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	return (0);
}

