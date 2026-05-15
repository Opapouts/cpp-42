/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 20:56:45 by opapouts          #+#    #+#             */
/*   Updated: 2026/05/07 20:56:48 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"
#include <iostream>

//Constructors && Destructor
Cat::Cat(void) : Animal() {
	_brain = new Brain();
	std::cout << "Default cat created" << std::endl;
	return ;
}
Cat::Cat(std::string type) : Animal(type) {
	_brain = new Brain();
	std::cout << "Typed cat created" << std::endl;
	return ;
}
Cat::Cat(const Cat& other) : Animal(other) {
	_brain = new Brain(*other._brain);
	std::cout << "Copy cat created" << std::endl;
	return ;
}
Cat::~Cat(void) {
	delete _brain;
	std::cout << "Cat destroyed" << std::endl;
	return ;
}

//Operator overload
Cat&	Cat::operator = (const Cat& other) {
	if (this == &other)
		return (*this);
	if (_brain)
		*_brain = *other._brain;
	else
		_brain = new Brain(*other._brain);
	_type = other._type;
	return (*this);
}

//Member functions
void	Cat::makeSound(void) const {
	std::cout << "Miaou miaou" << std::endl;
}
void	Cat::setIdeas(std::string idea) {
	for (int i = 0; i < 100; i++)
		_brain->setIdeas(idea);
}
void	Cat::printIdea(int index) const {
	_brain->getIdeas(index);
}
