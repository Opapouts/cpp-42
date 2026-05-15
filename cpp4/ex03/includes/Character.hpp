/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 02:25:47 by opapouts          #+#    #+#             */
/*   Updated: 2026/05/11 02:25:55 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include "ICharacter.hpp"
# include "AMateria.hpp"

class	Character : public ICharacter {

	public :
		Character(void);
		Character(std::string name);
		Character(const Character& other);
		virtual ~Character(void);
		Character& operator = (const Character& other);
		std::string const& getName(void) const;
		void	equip(AMateria* m);
		void	unequip(int idx);
		void	use(int idx, ICharacter& target);

	private :
		AMateria*	_inventory[4];
		std::string	_name;

};
#endif
