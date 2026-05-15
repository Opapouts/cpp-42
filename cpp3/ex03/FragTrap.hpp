/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 19:58:24 by opapouts          #+#    #+#             */
/*   Updated: 2026/05/03 19:58:27 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include "ClapTrap.hpp"

class	FragTrap : virtual public ClapTrap{

	public :
		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(const FragTrap& other);
		~FragTrap(void);
		FragTrap& operator = (const FragTrap& other);
		void	attack(const std::string& target);
		void	highFivesGuys(void);
};

#endif
