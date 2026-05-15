/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 21:49:43 by opapouts          #+#    #+#             */
/*   Updated: 2026/04/21 21:49:45 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class Zombie {

	public:
		Zombie(void);
		void	setName(std::string name);
		void	announce(void) const;
		~Zombie(void);
	private:
		std::string _name;
};

Zombie*	zombieHorde(int N, std::string name);
