/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 19:52:11 by opapouts          #+#    #+#             */
/*   Updated: 2026/05/07 19:52:19 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include <iostream>

int	main(void) {
	std::cout << "<-----Generic test----->" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;
	delete i;
	std::cout << std::endl;
	std::cout << "<-----Complex test----->" << std::endl;
	const Animal	*animals[3];
	animals[0] = new	Dog();
	animals[1] = new Cat();
	animals[2] = new	Dog();
	std::cout << std::endl;
	for (int i = 0; i < 3; i++) {
		std::cout << "Animal number " << i << " sound->>" << std::endl;
		animals[i]->makeSound();
		std::cout << std::endl;
	}
	for (int j = 0; j < 3; j++)
		delete animals[j];
	std::cout << std::endl;
	std::cout << "<-----Deep Copy test----->" << std::endl;
	Cat	*original = new Cat();
	original->makeSound();
	original->setIdeas("Leave me alone");
	original->printIdea(1);
	Cat	*copy = new Cat(*original);
	delete original;
	copy->makeSound();
	copy->printIdea(1);
	delete copy;
	return (0);
}
