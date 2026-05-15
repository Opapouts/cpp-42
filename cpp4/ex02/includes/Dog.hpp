/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 20:57:50 by opapouts          #+#    #+#             */
/*   Updated: 2026/05/07 20:57:51 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"
# include "Brain.hpp"
#include <string>

class	Dog : public Animal {

	public :
		Dog(void);
		Dog(std::string type);
		Dog(const Dog& other);
		~Dog(void);
		Dog&	operator = (const Dog& other);
		void	makeSound(void) const;
		void	setIdeas(std::string idea);
		void	printIdea(int index) const;
	private :
		Brain	*_brain;
};

#endif
