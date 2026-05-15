/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 02:27:20 by opapouts          #+#    #+#             */
/*   Updated: 2026/05/11 02:27:24 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MateriaSource.hpp"
#include <iostream>

//Constructors && Destructor
MateriaSource::MateriaSource(void) {
	for (int i = 0; i < 4; i++)
		_template[i] = NULL;
	return ;
}
MateriaSource::MateriaSource(const MateriaSource& other) {
	for (int i = 0; i < 4; i++) {
		if (other._template[i])
			_template[i] = other._template[i]->clone();
		else
			_template[i] = NULL;
	}
	return ;
}
MateriaSource::~MateriaSource(void) {
	for (int i = 0; i < 4; i++) {
		if (_template[i])
			delete _template[i];
	}
	return ;
}

//Operator Overload
MateriaSource&	MateriaSource::operator = (const MateriaSource& other) {
	if (this == &other)
		return (*this);
	for (int i = 0; i < 4; i++) {
		if (_template[i])
			delete _template[i];
	}
	for (int i = 0; i < 4; i++) {
		if (other._template[i])
			_template[i] = other._template[i]->clone();
		else
			_template[i] = NULL;
	}
	return (*this);
}

//Function Members
void	MateriaSource::learnMateria(AMateria* m) {
	for (int i = 0; i < 4; i++) {
		if (!_template[i]) {
			_template[i] = m;
			return ;
		}
	}
	return (delete m);
}
AMateria*	MateriaSource::createMateria(std::string const& type) {
	for (int i = 0; i < 4; i++) {
		if (_template[i] && _template[i]->getType() == type)
			return _template[i]->clone();
	}
	return (NULL);
}
