/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 17:41:48 by opapouts          #+#    #+#             */
/*   Updated: 2026/04/22 17:41:49 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void) {
	std::string	str;
	std::string	*stringPTR;



	str = "HI THIS IS BRAIN";
	stringPTR = &str;
	std::string& stringREF = str;
	std::cout << "------Memory addresses-----" << std::endl;
	std::cout << "The memory address of the string variable: " << &str << std::endl;
	std::cout << "The memory address held by the stringPTR: " << stringPTR << std::endl;
	std::cout << "The memory address held by the stringREF: " << &stringREF << std::endl;
	std::cout << "------Values-----" << std::endl;
	std::cout << "The value of the string variable: " << str << std::endl;
	std::cout << "The value pointed to by stringPTR: " << *stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF: " << stringREF << std::endl;
	return (0);
}

