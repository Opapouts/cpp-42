/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 20:57:36 by opapouts          #+#    #+#             */
/*   Updated: 2026/05/07 20:57:38 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
#include <string>

class	Animal {
	public :
		Animal(void);
		Animal(std::string type);
		Animal(const Animal& other);
		virtual ~Animal(void);
		Animal&	operator = (const Animal& other);
		virtual void	makeSound(void) const = 0;
		std::string	getType(void) const;
	protected :
		std::string	_type;
};

#endif
