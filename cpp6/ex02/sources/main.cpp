/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 05:34:56 by opapouts          #+#    #+#             */
/*   Updated: 2026/07/24 05:34:57 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <exception>

Base*	generate(void) {
	int	random = std::rand() % 3;

	if (!random)
		return (new A);
	else if (random == 1)
		return (new B);
	else
		return (new C);
}

void	identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void	identify(Base& p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return ;
	}
	catch (const std::exception&) {}

	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return ;
	}
	catch (const std::exception&) {}

	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return ;
	}
	catch (const std::exception&) {}
}

int	main(void) {
	std::srand(std::time(NULL));

	Base* test1 = generate();
	Base* test2 = generate();
	Base* test3 = generate();

	std::cout << "====Pointer identification====" << std::endl;
	identify(test1);
	identify(test2);
	identify(test3);

	std::cout << std::endl;
	std::cout << "====Reference identification====" << std::endl;
	identify(*test1);
	identify(*test2);
	identify(*test3);

	delete test1;
	delete test2;
	delete test3;

	return (0);
}
