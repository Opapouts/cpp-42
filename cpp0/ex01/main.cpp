/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 19:54:12 by opapouts          #+#    #+#             */
/*   Updated: 2026/04/18 19:54:12 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

int	main(void) {
	PhoneBook	myPhoneBook;
	std::string	cmd;

	while (1) {
		std::cout << "Please enter one of the following commands (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, cmd);
		myPhoneBook.eofHandling();
		while (cmd.compare("ADD") && cmd.compare("SEARCH") && cmd.compare("EXIT")) {
			std::cout << "Command ignored. Enter a valid command: ";
			std::getline(std::cin, cmd);
			myPhoneBook.eofHandling();
		}
		if (!cmd.compare("EXIT"))
			return (0);
		else if (!cmd.compare("ADD"))
			myPhoneBook.addContact();
		else if (!cmd.compare("SEARCH"))
			myPhoneBook.searchContact();
		}
	return (0);
}
