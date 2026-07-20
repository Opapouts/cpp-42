/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 19:27:09 by opapouts          #+#    #+#             */
/*   Updated: 2026/07/16 19:27:10 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include <fstream>

//Constructors && Destructor
ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("Default SCF", 145, 137), _target("Default SCF") {
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other.getName(), other.getSignGrade(), other.getExecuteGrade()), _target(other.getTarget()) {
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
	return ;
}

//Operator Overload
ShrubberyCreationForm& ShrubberyCreationForm::operator = (const ShrubberyCreationForm& other) {
	if (this == &other)
		return (*this);
	_target = other.getTarget();
	return (*this);
}

//Member Functions
std::string const& ShrubberyCreationForm::getTarget(void) const {
	return (_target);
}

void	ShrubberyCreationForm::executeAction(void) const {
	std::string	filename;
	filename = _target + "_shrubbery";

	std::ofstream	file(filename.c_str());
	if (file.is_open()) {
		drawASCIITree(file);
		file.close();
	}
}

void	ShrubberyCreationForm::drawASCIITree(std::ofstream& file) const {
	file << "       _-_" << std::endl;
	file << "    /~~   ~~\\" << std::endl;
	file << " /~~         ~~\\" << std::endl;
	file << "{               }" << std::endl;
	file << " \\  _-     -_  /" << std::endl;
	file << "   ~  \\\\ //  ~" << std::endl;
	file << "_- -   | | _- _" << std::endl;
	file << "  _ -  | |   -_" << std::endl;
	file << "      // \\\\" << std::endl;
}
