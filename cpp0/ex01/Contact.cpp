/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 19:53:45 by opapouts          #+#    #+#             */
/*   Updated: 2026/04/18 19:55:07 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

//Constructor & Destructor
Contact::Contact(void) {
	return ;
}
Contact::~Contact(void) {
	return ;
}

//Setters
void	Contact::setFirstName(std::string firstName) {
	this->_firstName = firstName;
}
void	Contact::setLastName(std::string lastName) {
	this->_lastName = lastName;
}
void	Contact::setNickname(std::string nickName) {
	this->_nickname = nickName;
}
void	Contact::setNumber(std::string number) {
	this->_number = number;
}
void	Contact::setSecret(std::string secret) {
	this->_secret = secret;
}

//Getters
std::string	Contact::getFirstName(void) const {
	return (this->_firstName);
}
std::string	Contact::getLastName(void) const {
	return (this->_lastName);
}
std::string	Contact::getNickname(void) const {
	return (this->_nickname);
}
std::string	Contact::getNumber(void) const {
	return (this->_number);
}
std::string	Contact::getSecret(void) const {
	return (this->_secret);
}
