/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 00:19:57 by opapouts          #+#    #+#             */
/*   Updated: 2026/07/26 00:19:58 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void	increment(int& a) {
	a++;
}

void	capitalize(char& a) {
	a = std::toupper(a);
}

void	strCapitalize(std::string& str) {
	int	i = 0;
	
	while (str[i]) {
		str[i] = std::toupper(str[i]);
		i++;
	}
}

void	printConst(const char& a) {
	std::cout << a << std::endl;
}

int	main(void) {
	int		intArray[5] = {0, 42, 1, -13, 32};
	char		charArray[4] = {'a', 'e', 'k', 'o'};
	std::string	strArray[3] = {"Bonjour", "Mbappe", "Dictateur"};

	std::cout << "Array avant: ";
	::printArray(intArray, 5);
	::iter(intArray, 5, increment);
	std::cout << "Array apres: ";
	::printArray(intArray, 5);
	
	std::cout << std::endl;
	std::cout << "Array avant: ";
	::printArray(charArray, 4);
	::iter(charArray, 4, capitalize);
	std::cout << "Array apres: ";
	::printArray(charArray, 4);

	std::cout << std::endl;
	std::cout << "Array avant: ";
	::printArray(strArray, 3);
	::iter(strArray, 3, strCapitalize);
	std::cout << "Array apres: ";
	::printArray(strArray, 3);

	std::cout << std::endl;
	std::cout << "Const references accepted as well" << std::endl;
	::iter(charArray, 4, printConst);

	return (0);
}
