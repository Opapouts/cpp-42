/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 02:26:23 by opapouts          #+#    #+#             */
/*   Updated: 2026/05/11 02:26:26 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
# include "AMateria.hpp"
# include "IMateriaSource.hpp"

class	MateriaSource	: public IMateriaSource {

	public :
		MateriaSource(void);
		MateriaSource(const MateriaSource& other);
		virtual ~MateriaSource(void);
		MateriaSource& operator = (const MateriaSource& other);
		virtual void learnMateria(AMateria* m);
		virtual AMateria* createMateria(std::string const& type);
	private :
		AMateria*	_template[4];
};

#endif
