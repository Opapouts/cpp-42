/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 19:54:03 by opapouts          #+#    #+#             */
/*   Updated: 2026/04/20 19:55:25 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <cctype>
#include <iomanip>
#include <cstdlib>

//Constructor && Destructor
PhoneBook::PhoneBook(void) {
	this->_totalContacts = 0;
	this->_oldestContact = 0;
	return ;
}
PhoneBook::~PhoneBook(void) {
	return ;
}

//Member functions
void	PhoneBook::eofHandling(void) const {
	if (std::cin.eof()) {
		std::cout << "\nEOF detected. Exiting the program.\n";
		std::exit(0);
	}
}

std::string	PhoneBook::_getInput(std::string prompt) const {
	std::string	input;
	std::cout << prompt;
	std::getline(std::cin, input);
	this->eofHandling();
	while (input.empty()) {
		std::cout << "Field cannot be empty. ";
		std::cout << prompt;
		std::getline(std::cin, input);
		this->eofHandling();
	}
	return (input);
}

std::string PhoneBook::_getNumber(std::string prompt) const {
	bool		valid;
	std::string	number;

	valid = false;
	while (!valid) {
		std::cout << prompt;
		std::getline(std::cin, number);
		this->eofHandling();
		if (number.empty()) {
			std::cout << "Field cannot be empty. ";
			continue ;
		}
		valid = true;
		for (size_t i = 0; i < number.length(); i++) {
			if (!std::isdigit(number[i])) {
				std::cout << "Phone number must contain only digits\n";
				valid = false;
				break ;
			}
		}
	}
	return (number);
}

void	PhoneBook::addContact(void) {

	std::cout << "In order to create a new contact, fill out these fields\n";
	Contact& currContact = this->_contacts[this->_oldestContact];
	currContact.setFirstName(this->_getInput("Enter First Name: "));
	currContact.setLastName(this->_getInput("Enter Last Name: "));
	currContact.setNickname(this->_getInput("Enter Nickname: "));
	currContact.setNumber(this->_getNumber("Enter Number: "));
	currContact.setSecret(this->_getInput("Enter Darkest Secret: "));
	std::cout << "Contact successfully created\n";
	this->_oldestContact = (this->_oldestContact + 1) % 8;
	if (this->_totalContacts < 8)
		this->_totalContacts++;
}

void	PhoneBook::_displayOverview(int i) const {
	size_t	length;

	length = this->_contacts[i].getFirstName().length();
	if (length < 10)
		std::cout << std::setw(10) << this->_contacts[i].getFirstName();
	else
		std::cout << this->_contacts[i].getFirstName().substr(0, 9) << ".";
	length = this->_contacts[i].getLastName().length();
	std::cout << "|";
	if (length < 10)
		std::cout << std::setw(10) << this->_contacts[i].getLastName();
	else
		std::cout << this->_contacts[i].getLastName().substr(0, 9) << ".";
	length = this->_contacts[i].getNickname().length();
	std::cout << "|";
	if (length < 10)
		std::cout << std::setw(10) << this->_contacts[i].getNickname();
	else
		std::cout << this->_contacts[i].getNickname().substr(0, 9) << ".";
}

void	PhoneBook::_showContacts(void) const{
	int	i;

	i = 0;
	while (i < this->_totalContacts) {
		std::cout << std::setw(10) << i << "|";
		PhoneBook::_displayOverview(i++);
		std::cout << std::endl;
	}
}

int	PhoneBook::_verifyIndex(void) const {
	std::string	index;
	int		result;

	while (1) {
		std::cout << "Enter the index of the contact you want to see: ";
		std::getline(std::cin, index);
		this->eofHandling();
		if (index.length() == 1 && std::isdigit(index[0])) {
			result = index[0] - '0';
			if (result >= this->_totalContacts) {
				std::cout << "Please choose an index from 0 until ";
				std::cout << this->_totalContacts - 1 << ".\n";
				continue ;
			}
			else
				return (result);
		}
		else
			std::cout << "Invalid index. Please try a single digit input.\n";
	}
	return (0);
}

void	PhoneBook::searchContact(void) const {
	int	index;

	if (this->_totalContacts == 0) {
		std::cout << "The PhoneBooks is empty, please add a contact first\n";
		return ;
	}
	this->_showContacts();
	index = this->_verifyIndex();
	std::cout << this->_contacts[index].getFirstName() << std::endl;
	std::cout << this->_contacts[index].getLastName() << std::endl;
	std::cout << this->_contacts[index].getNickname() << std::endl;
	std::cout << this->_contacts[index].getNumber() << std::endl;
	std::cout << this->_contacts[index].getSecret() << std::endl;
}
