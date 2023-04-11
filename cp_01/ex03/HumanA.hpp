/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:31:19 by theo              #+#    #+#             */
/*   Updated: 2023/04/10 14:34:46 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A
# define HUMAN_A

#include "Weapon.hpp"

class	HumanA
{
	private:
		std::string	_name;
		Weapon		&_weapon;
	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA(void);
		void	attack(void);
		void	setWeapon(Weapon weapon);
};

#endif