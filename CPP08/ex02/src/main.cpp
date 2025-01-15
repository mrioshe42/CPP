/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 16:20:05 by mrios-he          #+#    #+#             */
/*   Updated: 2025/01/03 11:51:09 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template<typename T>
void printStack(const std::string& name, T& container)
{
	std::cout << "Printing " << name << ":" << std::endl;
	typename T::iterator it = container.begin();
	typename T::iterator ite = container.end();
	
	while (it != ite)
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
}

void testSubjectExample()
{
	std::cout << "\n1. Testing Subject Example:" << std::endl;
	
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	
	std::cout << "Top: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "Size after pop: " << mstack.size() << std::endl;
	
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	
	printStack("mstack", mstack);
	
	std::stack<int> s(mstack);
	std::cout << "Converted to regular stack, top: " << s.top() << std::endl;
}

void testWithDifferentTypes()
{
	std::cout << "\n2. Testing Different Types:" << std::endl;
	
	MutantStack<std::string> strStack;
	strStack.push("Hello");
	strStack.push("World");
	strStack.push("!");

	printStack("string stack", strStack);

	MutantStack<double> dblStack;
	dblStack.push(3.14);
	dblStack.push(2.718);
	dblStack.push(1.414);

	printStack("double stack", dblStack);
}

void testIterators()
{
	std::cout << "\n3. Testing Iterator Operations:" << std::endl;

	MutantStack<int> mstack;
	for (int i = 1; i <= 5; ++i)
		mstack.push(i);

	std::cout << "Forward iteration: ";
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "Reverse iteration: ";
	for (MutantStack<int>::reverse_iterator it = mstack.rbegin(); it != mstack.rend(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	const MutantStack<int> const_mstack(mstack);
	std::cout << "Const iteration: ";
	for (MutantStack<int>::const_iterator it = const_mstack.begin(); it != const_mstack.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void compareWithList()
{
	std::cout << "\n4. Comparing with std::list:" << std::endl;
	
	MutantStack<int> mstack;
	std::list<int> lst;

	for (int i = 1; i <= 5; ++i)
	{
		mstack.push(i);
		lst.push_back(i);
	}

	printStack("mstack", mstack);

	std::cout << "List: ";
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

int main()
{
	testSubjectExample();
	testWithDifferentTypes();
	testIterators();
	compareWithList();
	return (0);
}
