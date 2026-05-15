/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 17:41:13 by opapouts          #+#    #+#             */
/*   Updated: 2026/04/22 17:41:15 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP
# include "Weapon.hpp"
# include <string>

class	HumanB	{

	public :
		HumanB(std::string name);
		~HumanB(void);
		void	setWeapon(Weapon& weapon);
		void	attack(void);
	private :
		std::string	_name;
		Weapon*	_weapon;
};

#endif


