/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 17:41:28 by opapouts          #+#    #+#             */
/*   Updated: 2026/04/22 17:41:30 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
#include <string>

class	Weapon	{

	public :
		Weapon(std::string type);
		~Weapon(void);
		const std::string&	getType(void) const;
		void	setType(std::string type);
	private :
		std::string	_type;
};

#endif

