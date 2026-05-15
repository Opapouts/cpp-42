/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 17:40:52 by opapouts          #+#    #+#             */
/*   Updated: 2026/04/22 17:41:05 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP
# include "Weapon.hpp"
# include <string>

class	HumanA	{

	public :
		HumanA(std::string name, Weapon& weapon);
		~HumanA(void);
		void	attack(void);
	private :
		Weapon&	_weapon;
		std::string	_name;
};

#endif

