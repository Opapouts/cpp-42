/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 02:26:13 by opapouts          #+#    #+#             */
/*   Updated: 2026/05/11 02:26:16 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP
# include "AMateria.hpp"

class	IMateriaSource {

	public :
		virtual ~IMateriaSource(void) {};
		virtual void learnMateria(AMateria* other) = 0;
		virtual AMateria* createMateria(std::string const& type) = 0;
};

#endif
