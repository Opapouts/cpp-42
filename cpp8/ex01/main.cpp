/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 04:39:57 by opapouts          #+#    #+#             */
/*   Updated: 2026/07/28 04:39:59 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <list>
#include <deque>
#include <iostream>

int	given_main(void) {
	std::cout << "Testing the given main" << std::endl;
	Span	sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return (0);
}

int	main(int ac, char **av) {
	(void) av;
	if (ac != 1)
		return (given_main());

	std::cout << "Testing the exceptions" << std::endl;
	Span	exc = Span(5);
	try {
		std::cout << exc.shortestSpan() << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "Now testing the addRange member function" << std::endl;
	std::list<int>	list;
	for (int i = 0; i < 10001; i++)
		list.push_back(i);
	Span	sp = Span(15000);
	sp.addRange(list.begin(), list.end());
	sp.printContainer();

	std::cout << std::endl;
	std::cout << "Testing the AddRangeException" << std::endl;
	std::deque<int>	deque;
	for (int i = 0; i < 2000; i++)
		deque.push_back(i);
	Span	fail = Span(1500);
	try {
		fail.addRange(deque.begin(), deque.end());
		fail.printContainer();
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
