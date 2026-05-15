/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 19:51:38 by opapouts          #+#    #+#             */
/*   Updated: 2026/05/07 19:51:41 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"
#include <iostream>

//Constructors && Destructor
Dog::Dog(void) : Animal() {
	_brain = new Brain();
	std::cout << "Default dog created" << std::endl;
	return ;
}
Dog::Dog(std::string type) : Animal(type) {
	_brain = new Brain();
	std::cout << "Typed dog created" << std::endl;
	return ;
}
Dog::Dog(const Dog& other) : Animal(other) {
	_brain = new Brain(*other._brain);
	std::cout << "Copy dog created" << std::endl;
	return ;
}
Dog::~Dog(void) {
	delete _brain;
	std::cout << "Dog destroyed" << std::endl;
	return ;
}

//Operator overload
Dog&	Dog::operator = (const Dog& other) {
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
void	Dog::makeSound(void) const {
	std::cout << "Wooof wooof" << std::endl;
}
void	Dog::setIdeas(std::string idea) {
	for (int i = 0; i < 100; i++)
		_brain->setIdeas(idea);
}
void	Dog::printIdea(int index) const {
	_brain->getIdeas(index);
}
