/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 21:27:07 by opapouts          #+#    #+#             */
/*   Updated: 2026/05/07 21:27:14 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP
# include <string>

class	ICharacter;

class	AMateria {

	public :
		AMateria(void);
		AMateria(std::string const& type);
		AMateria(const AMateria& other);
		virtual ~AMateria(void);
		AMateria& operator = (const AMateria& other);
		std::string const& getType(void) const;
		virtual AMateria* clone() const = 0;
		virtual	void use(ICharacter& target);
	protected :
		std::string _type;
};

#endif
