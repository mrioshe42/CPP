#include "iter.hpp"

template<typename T>
void print(T const & x)
{
	std::cout << x << std::endl;
}

int main(void)
{
	int intArray[] = {1, 2, 3, 4, 5};
	size_t intLength = 5;
	std::cout << "Testing with integers:" << std::endl;
	iter(intArray, intLength, print<int>);

	std::string strArray[] = {"Hello", "World", "!"};
	size_t strLength = 3;
	std::cout << "\nTesting with strings:" << std::endl;
	iter(strArray, strLength, print<std::string>);

	char charArray[] = {'a', 'b', 'c', 'd'};
	size_t charLength = 4;
	std::cout << "\nTesting with characters:" << std::endl;
	iter(charArray, charLength, print<char>);

	double doubleArray[] = {1.1, 2.2, 3.3, 4.4};
	size_t doubleLength = 4;
	std::cout << "\nTesting with doubles:" << std::endl;
	iter(doubleArray, doubleLength, print<double>);

	int emptyArr[] = {};
	std::cout << "\nTesting empty array:" << std::endl;
	iter(emptyArr, 0, print<int>);

	std::cout << "\nTesting with NULL array:" << std::endl;
	int* nullArr = NULL;
	iter(nullArr, 0, print<int>);

	return 0;
}