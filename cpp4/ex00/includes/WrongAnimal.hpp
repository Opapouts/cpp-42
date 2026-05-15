/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 18:04:07 by opapouts          #+#    #+#             */
/*   Updated: 2026/05/06 18:04:11 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
#include <string>

class	WrongAnimal {
	public :
		WrongAnimal(void);
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal& other);
		virtual ~WrongAnimal(void);
		WrongAnimal&	operator = (const WrongAnimal& other);
		void	makeSound(void) const;
		std::string	getType(void) const;
	protected :
		std::string	_type;
};

#endif
