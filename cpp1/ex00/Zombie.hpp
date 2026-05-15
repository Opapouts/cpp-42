/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 18:27:56 by opapouts          #+#    #+#             */
/*   Updated: 2026/04/21 18:27:58 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <string>

class	Zombie {

	public:
		Zombie(std::string name);
		void	announce(void) const;
		~Zombie(void);
	private:
		std::string	_name;

};

	Zombie*	newZombie(std::string name);
	void	randomChump(std::string name);

#endif
