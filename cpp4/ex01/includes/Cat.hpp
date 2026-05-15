/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 19:53:15 by opapouts          #+#    #+#             */
/*   Updated: 2026/05/07 19:53:19 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"
#include "../includes/Brain.hpp"
#include <string>

class	Cat : public Animal {

	public :
		Cat(void);
		Cat(std::string type);
		Cat(const Cat& other);
		~Cat(void);
		Cat&	operator = (const Cat& other);
		void	makeSound(void) const;
		void	setIdeas(std::string idea);
		void	printIdea(int index) const;
	private :
		Brain	*_brain;
};

#endif
