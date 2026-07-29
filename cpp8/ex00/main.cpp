/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 03:50:38 by opapouts          #+#    #+#             */
/*   Updated: 2026/07/28 03:50:39 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <deque>
#include <list>

void	setVector(std::vector<int>& vector) {
	vector.push_back(42);
	vector.push_back(-13);
	vector.push_back(1);
}

void	setDeque(std::deque<int>& deque) {
	deque.push_back(5);
	deque.push_back(-10);
	deque.push_back(41);
}

void	setList(std::list<int>& list) {
	list.push_back(13);
	list.push_back(9);
	list.push_back(2002);
}

int	main(void) {
	std::vector<int>	vector;
	std::deque<int>	deque;
	std::list<int>	list;

	setVector(vector);
	setDeque(deque);
	setList(list);

	std::cout << "Vector container: ";
	::printContainer(vector);

	std::cout << "Deque container: ";
	::printContainer(deque);

	std::cout << "List container: ";
	::printContainer(list);

	std::cout << std::endl;
	std::cout << *(::easyfind(vector, 42)) << std::endl;
	std::cout << *(::easyfind(deque, -10)) << std::endl;
	std::cout << *(::easyfind(list, 2002)) << std::endl;
	//std::cout << *(::easyfind(list, 15)) << std::endl; Undefined behavior 
	return (0);
}
