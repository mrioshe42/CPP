/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 12:11:15 by mrios-he          #+#    #+#             */
/*   Updated: 2024/11/30 12:54:04 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data* original = new Data;
	original->number = 42;
	original->character = 'A';
	original->decimal = 3.14;

	uintptr_t serialized = Serializer::serialize(original);
	Data* deserialized = Serializer::deserialize(serialized);

	std::cout << "Original pointer: " << original << std::endl;
	std::cout << "Deserialized pointer: " << deserialized << std::endl;
	std::cout << "Pointers are " << (original == deserialized ? "equal!" : "different...") << std::endl;
	std::cout << "Number: " << deserialized->number << std::endl;
	std::cout << "Character: " << deserialized->character << std::endl;
	std::cout << "Decimal: " << deserialized->decimal << std::endl;

	delete original;
	return 0;
}