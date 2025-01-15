/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:17:14 by mrios-he          #+#    #+#             */
/*   Updated: 2024/11/20 18:17:15 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	std::cout << "Creating zombie on stack:" << std::endl;
	randomChump("Stack_Zombie");
	std::cout << "\nCreating zombie on heap:" << std::endl;
	Zombie* heapZombie = newZombie("Heap_Zombie");
	heapZombie->announce();
	delete heapZombie;
	return (0);
}
