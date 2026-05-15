/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 18:40:33 by opapouts          #+#    #+#             */
/*   Updated: 2026/05/03 18:40:34 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include "ClapTrap.hpp"

class	FragTrap : public ClapTrap{

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
