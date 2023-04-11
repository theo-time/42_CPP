/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 13:46:47 by theo              #+#    #+#             */
/*   Updated: 2023/04/10 14:20:13 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    std::cout << std::endl;
    
    Zombie *horde = zombieHorde(12, "Gertrude");

	for (int i = 0; i < 12; i++)
		horde[i].announce();
	delete [] horde;
}