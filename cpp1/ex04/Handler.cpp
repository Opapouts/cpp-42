/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Handler.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 20:48:08 by opapouts          #+#    #+#             */
/*   Updated: 2026/04/22 20:48:13 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Handler.hpp"
#include <fstream>
#include <string>
#include <iostream>

//Constructor && Destructor
Handler::Handler(std::string filename, std::string s1, std::string s2) : _filename(filename), _s1(s1), _s2(s2) {
	std::cout << "Constructor of Handler class called" << std::endl;
}

Handler::~Handler(void) {
	this->_inFile.close();
	this->_outFile.close();
	std::cout << "Destructor of Handler class called" << std::endl;
}

//Member functions
bool	Handler::checkConditions(void) {
	if (this->_s1.empty()) {
		std::cout << "Wrong input, can't accept empty string as s1" << std::endl;
		return (false);
	}
	this->_inFile.open(_filename.c_str());
	if (!_inFile.is_open()) {
		std::cout << "Failed to open infile" << std::endl;
		return (false);
	}
	std::string	_replacement;
	_replacement = this->_filename + ".replace";
	this->_outFile.open(_replacement.c_str());
	if (!_outFile.is_open()) {
		std::cout << "Failed to open outfile" << std::endl;
		return (false);
	}
	return (true);
}

void	Handler::replaceFile(void) {
	if (!checkConditions())
		return ;
	std::string	currentLine;
	size_t		occurence;
	size_t		index;

	while (std::getline(this->_inFile, currentLine)) {
		index = 0;
		while (1) {
			occurence = currentLine.find(this->_s1, index);
			if (occurence == std::string::npos) {
				this->_outFile << currentLine << std::endl;
				break ;
			}
			currentLine.erase(occurence, this->_s1.length());
			currentLine.insert(occurence, this->_s2);
			index = occurence + this->_s2.length();
		}
	}
}
