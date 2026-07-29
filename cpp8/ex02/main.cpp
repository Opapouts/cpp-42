/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 12:11:13 by opapouts          #+#    #+#             */
/*   Updated: 2026/07/28 12:11:15 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

int	given_main(void) {
	std::cout << "===== Given main ====" << std::endl;
	MutantStack<int>	mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	return (0);
}

int	list_main(void) {
	std::cout << "==== List main ====" << std::endl;
	std::list<int>	list;
	list.push_back(5);
	list.push_back(17);
	std::cout << list.back() << std::endl;
	list.pop_back();
	std::cout << list.size() << std::endl;
	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	list.push_back(0);
	std::list<int>::iterator it = list.begin();
	std::list<int>::iterator ite = list.end();
	++it;
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
	return (0);
}

int	my_main(void) {
	MutantStack<char>	mstack;
	std::cout << "==== My main ====" << std::endl;
	mstack.push('v');
	mstack.push('o');
	mstack.push('i');
	mstack.push('l');
	mstack.push('a');
	mstack.push('m');
	mstack.push('o');
	mstack.push('n');
	mstack.push('m');
	mstack.push('a');
	mstack.push('i');
	mstack.push('n');
	mstack.printContainer();
	return (0);
}

int	main(int ac, char **av) {
	(void) av;
	if (ac == 1)
		return (my_main());
	if (av[1][0] == '1')
		return (list_main());
	else
		return (given_main());
}
