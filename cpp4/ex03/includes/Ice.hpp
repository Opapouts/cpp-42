/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 21:27:25 by opapouts          #+#    #+#             */
/*   Updated: 2026/05/07 21:27:28 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP
# include "AMateria.hpp"
#include "../includes/ICharacter.hpp"

class	Ice : public AMateria {

	public :
		Ice(void);
		Ice(const Ice& other);
		virtual ~Ice(void);
		Ice& operator = (const Ice& other);
		virtual AMateria* clone(void) const;
		virtual void	use(ICharacter& target);
};

#endif
