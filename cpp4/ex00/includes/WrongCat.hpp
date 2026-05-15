/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 18:04:23 by opapouts          #+#    #+#             */
/*   Updated: 2026/05/06 18:04:23 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP
# include "WrongAnimal.hpp"
#include <string>

class	WrongCat : public WrongAnimal {

	public :
		WrongCat(void);
		WrongCat(std::string type);
		WrongCat(const WrongCat& other);
		~WrongCat(void);
		WrongCat&	operator = (const WrongCat& other);
		void	makeSound(void) const;
};

#endif
