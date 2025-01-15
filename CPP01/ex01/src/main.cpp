/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:18:01 by mrios-he          #+#    #+#             */
/*   Updated: 2024/11/20 18:18:03 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(int argc, char *argv[]) 
{
    int	N = 5;

    if (argc > 1)
    {
        N = std::atoi(argv[1]);
        if (N <= 0)
        {
            std::cout << "Error: Number of zombies must be positive" << std::endl;
            return (1);
        }
    }
    std::cout << "Creating a horde of " << N << " zombies..." << std::endl;
    Zombie* horde = zombieHorde(N, "Horde_Zombie");
    if (horde == NULL)
    {
        std::cout << "Failed to create zombie horde!" << std::endl;
        return (1);
    }
    for (int i = 0; i < N; i++)
    {
        std::cout << "Zombie " << i + 1 << ": ";
        horde[i].announce();
    }
    delete[] horde;
    return (0);
}
