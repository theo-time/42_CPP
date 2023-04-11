/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:13:42 by theo              #+#    #+#             */
/*   Updated: 2023/04/10 15:38:31 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>

#ifndef HARL
# define HARL

# define BOLD "\033[1m" //[1m"Contact List\033[0m"
# define DEFAULT "\001\033[0;39m\002"

class	Harl
{
	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
	public:
		Harl(void);
		~Harl(void);
		void	complain(std::string level);
};

#endif