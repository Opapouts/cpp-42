/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 17:22:00 by opapouts          #+#    #+#             */
/*   Updated: 2026/05/06 17:22:02 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"
#include <string>

class	Dog : public Animal {

	public :
		Dog(void);
		Dog(std::string type);
		Dog(const Dog& other);
		~Dog(void);
		Dog&	operator = (const Dog& other);
		void	makeSound(void) const;
};

#endif
