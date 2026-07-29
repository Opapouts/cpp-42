/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 04:08:55 by opapouts          #+#    #+#             */
/*   Updated: 2026/07/26 04:08:56 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <string>
#include <iostream>
#include <cstdlib>

//This is the weird main.cpp given in the subject
#define MAX_VAL 750
int	bad_main(void) {
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++) {
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
        Array<int> tmp = numbers;
        Array<int> test(tmp);

	for (int i = 0; i < MAX_VAL; i++) {
		if (mirror[i] != numbers[i]) {
			std::cerr << "didn't save the same value!!" << std::endl;
			return (1);
		}
	}
	try {
		numbers[-2] = 0;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	try {
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	for (int i = 0; i < MAX_VAL; i++) {
		numbers[i] = rand();
	}
	delete [] mirror;
	return (0);
}

//This is my clean main function
int	main(int ac, char **av) {
	(void) av;
	if (ac != 1)
		return (bad_main());
	Array<int>	a(3);
	Array<std::string>	b(3);
	Array<std::string>	b_copy;

	a[0] = 3;
	a[1] = 42;
	a[2] = 0;
	Array<int>	a_copy(a);

	b[0] = "2030";
	b[1] = "sera notre";
	b[2] = "annee";
	b_copy = b;

	std::cout << "Int array-> ";
	a.printArray();
	unsigned int size = a.size();
	std::cout << "Size: " << size << std::endl;

	std::cout << std::endl;
	std::cout << "Array instantiated by copy operator-> ";
	a_copy.printArray();
	size = a_copy.size();
	std::cout << "Size: " << size << std::endl;

	std::cout << std::endl;
	std::cout << "std::string array-> ";
	b.printArray();
	size = b.size();
	std::cout << "Size: " << size << std::endl;

	std::cout << std::endl;
	std::cout << "Array instantiated by = operator-> ";
	b_copy.printArray();
	size = b_copy.size();
	std::cout << "Size: " << size << std::endl;
	std::cout << std::endl;

	try {
		a[7] = 8;
		std::cout << "This shouldn't be printed" << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
