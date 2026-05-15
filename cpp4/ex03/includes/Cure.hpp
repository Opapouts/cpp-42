/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 21:27:22 by opapouts          #+#    #+#             */
/*   Updated: 2026/05/07 21:27:23 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP
# include "AMateria.hpp"
#include "../includes/ICharacter.hpp"

class	Cure : public AMateria {

	public :
		Cure(void);
		Cure(const Cure& other);
		virtual ~Cure(void);
		Cure& operator = (const Cure& other);
		virtual AMateria *clone(void) const;
		virtual void	use(ICharacter& target);
};

#endif
