/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:22:12 by theo              #+#    #+#             */
/*   Updated: 2023/04/10 14:24:36 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string	string;
	std::string	*stringPTR;

	string = "HI THIS IS BRAIN";
	stringPTR = &string;
	std::string	&stringREF = string;
	std::cout << "string addr: " << &string << std::endl;
	std::cout << "pointer addr: " << stringPTR << std::endl;
	std::cout << "ref addr: " << &stringREF << std::endl;
	std::cout << "pointer string: " << *stringPTR << std::endl;
	std::cout << "reference string: " << stringREF << std::endl;
}