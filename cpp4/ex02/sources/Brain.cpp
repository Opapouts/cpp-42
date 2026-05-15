/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 20:56:40 by opapouts          #+#    #+#             */
/*   Updated: 2026/05/07 20:56:41 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Brain.hpp"
#include <iostream>

//Constructors && Destructor
Brain::Brain(void) {
	std::cout << "A default brain spawned" << std::endl;
	return ;
}
Brain::Brain(const Brain& other) {
	for (int i = 0; i < 100; i++) 
		_ideas[i] = other._ideas[i];
	std::cout << "A copy brain spawned" << std::endl;
	return ;
}
Brain::~Brain(void) {
	std::cout << "Brain deleted" << std::endl;
	return ;
}

//Function Members
void	Brain::setIdeas(std::string idea) {
	for (int i = 0; i < 100; i++)
		_ideas[i] = idea;
}
void	Brain::getIdeas(int index) const {
	std::cout << _ideas[index] << std::endl;
}

//Operator overload
Brain&	Brain::operator = (const Brain& other) {
	if (this == &other) 
		return (*this);
	for (int i = 0; i < 100; i++)
		_ideas[i] = other._ideas[i];
	return (*this);
}
