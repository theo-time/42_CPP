/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 13:43:51 by theo              #+#    #+#             */
/*   Updated: 2023/04/10 14:21:04 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    _name = name;
    std::cout << "👶 " << _name << " the zombie is born !" << std::endl << std::endl;
}

Zombie::Zombie(void)
{
	this->_name = "(no name)";
    std::cout << "👶 " << _name << " the zombie is born !" << std::endl << std::endl;
}

Zombie::~Zombie(void)
{
    std::cout <<  "💀 " << _name << " the zombie has been obliterated..." << std::endl << std::endl;
}

void	Zombie::announce(void)
{
    std::cout << RED << _name << DEFAULT << ": BraiiiiiiinnnzzzZ..." << std::endl << std::endl;
}

void	Zombie::setName(std::string name)
{
	this->_name = name;
}