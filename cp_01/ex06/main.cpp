/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:21:50 by theo              #+#    #+#             */
/*   Updated: 2023/04/10 16:03:55 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int parse_level(std::string level)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
			return i;
	}
	return (-1);
}

void harl_filter(int level, Harl &harl)
{
	switch(level)
	{
		case 0:
			harl.complain("DEBUG");
			__attribute__ ((fallthrough));
		case 1:
			harl.complain("INFO");
			__attribute__ ((fallthrough));
		case 2:
			harl.complain("WARNING");
			__attribute__ ((fallthrough));
		case 3:
			harl.complain("ERROR");
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
	
}

int	main(int argc, char **argv)
{
	Harl harl;

	if (argc != 2)
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	else
		harl_filter(parse_level(argv[1]), harl);
	return (0);
}