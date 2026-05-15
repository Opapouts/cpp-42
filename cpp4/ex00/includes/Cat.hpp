/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 17:22:11 by opapouts          #+#    #+#             */
/*   Updated: 2026/05/06 17:22:12 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"
#include <string>

class	Cat : public Animal {

	public :
		Cat(void);
		Cat(std::string type);
		Cat(const Cat& other);
		~Cat(void);
		Cat&	operator = (const Cat& other);
		void	makeSound(void) const;
};

#endif
