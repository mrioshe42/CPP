/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 16:17:50 by mrios-he          #+#    #+#             */
/*   Updated: 2025/01/03 11:51:19 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

void testBasicSpan()
{
	std::cout << "\n1. Testing Basic Span:" << std::endl;
	try
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Basic Span Exception: " << e.what() << std::endl;
	}
}

void testBigSpan()
{
	std::cout << "\n2. Testing Big Span (10000 numbers):" << std::endl;
	try
	{
		Span bigSpan(10000);
		std::vector<int> numbers;
		srand(time(NULL));
		for (int i = 0; i < 10000; ++i)
			numbers.push_back(rand());
		bigSpan.addNumbers(numbers.begin(), numbers.end());
		
		std::cout << "Shortest span: " << bigSpan.shortestSpan() << std::endl;
		std::cout << "Longest span: " << bigSpan.longestSpan() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Big Span Exception: " << e.what() << std::endl;
	}
}

void testFullSpan()
{
	std::cout << "\n3. Testing Full Span Exception:" << std::endl;
	try
	{
		Span smallSpan(1);
		smallSpan.addNumber(5);
		std::cout << "Added first number successfully" << std::endl;
		smallSpan.addNumber(10);
		std::cout << "This line shouldn't be printed" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Full Span Exception: " << e.what() << std::endl;
	}
}

void testExtremeCases()
{
	std::cout << "\n4. Testing Extreme Values:" << std::endl;
	try
	{
		Span sp(5);
		sp.addNumber(INT_MIN);
		sp.addNumber(INT_MAX);
		sp.addNumber(0);
		std::cout << "Added INT_MIN, INT_MAX and 0" << std::endl;
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Extreme Values Exception: " << e.what() << std::endl;
	}
}

void testEmptySpan()
{
	std::cout << "\n5. Testing Empty Span:" << std::endl;
	try
	{
		Span empty(5);
		std::cout << "Trying to get spans from empty Span:" << std::endl;
		empty.shortestSpan();
	}
	catch (const std::exception& e)
	{
		std::cout << "Empty Span Exception: " << e.what() << std::endl;
	}
}

void testDifferentContainers()
{
	std::cout << "\n6. Testing Different Containers:" << std::endl;
	
	try
	{
		std::list<int> lst;
		lst.push_back(1);
		lst.push_back(2);
		lst.push_back(3);
		
		Span sp1(5);
		sp1.addNumbers(lst.begin(), lst.end());
		std::cout << "List test - Shortest span: " << sp1.shortestSpan() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "List Test Exception: " << e.what() << std::endl;
	}

	try
	{
		std::deque<int> deq;
		deq.push_back(10);
		deq.push_back(20);
		deq.push_back(30);
		
		Span sp2(5);
		sp2.addNumbers(deq.begin(), deq.end());
		std::cout << "Deque test - Longest span: " << sp2.longestSpan() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Deque Test Exception: " << e.what() << std::endl;
	}
}

int main()
{
	testBasicSpan();
	testBigSpan();
	testFullSpan();
	testExtremeCases();
	testEmptySpan();
	testDifferentContainers();
	return (0);
}
