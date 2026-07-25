/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 19:51:03 by opapouts          #+#    #+#             */
/*   Updated: 2026/07/20 19:51:04 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cctype>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <climits>
#include <iostream>

//Orthodox Canonical Form
ScalarConverter::ScalarConverter(void) {
	return ;
}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
	(void) other;
	return ;
}

ScalarConverter::~ScalarConverter(void) {
	return ;
}

ScalarConverter& ScalarConverter::operator = (const ScalarConverter& other) {
	(void) other;
	return (*this);
}

//Identifying Type of literal
bool	ScalarConverter::isChar(const std::string& literal) {
	return (literal.length() == 1 && !isdigit(literal[0]));
}

bool	ScalarConverter::isPseudo(const std::string& literal) {
	return (literal == "nan" || literal == "nanf" ||
		literal == "+inf" || literal == "-inf" ||
		literal == "+inff" || literal == "-inff");
}

bool	ScalarConverter::isInt(const std::string& literal, double value) {
	if (value >= INT_MIN && value <= INT_MAX && literal.find('.') == std::string::npos)
		return (true);
	return (false);
}

e_type	ScalarConverter::identifyType(const std::string& literal) {
	if (isChar(literal))
		return (CHAR);
	if (isPseudo(literal)) {
		if (isPseudoFloat(literal))
			return (FLOAT);
		return (DOUBLE);
	}
	char	*endptr = NULL;
	double value = std::strtod(literal.c_str(), &endptr);
	if (endptr == literal.c_str())
		return (INVALID);
	if (!*endptr) {
		if (isInt(literal, value))
			return (INT);
		return (DOUBLE);
	}
	if (isLastCharF(endptr) && hasDecimalPoint(literal))
		return (FLOAT);
	return (INVALID);
}

//Helper Functions
bool	ScalarConverter::isLastCharF(char *endptr) {
	if ((*endptr == 'f' || *endptr == 'F') && !*(endptr + 1))
		return (true);
	return (false);
}

bool	ScalarConverter::hasDecimalPoint(const std::string& literal) {
	if (literal.find('.') != std::string::npos)
		return (true);
	return (false);
}

bool	ScalarConverter::isPseudoFloat(const std::string& literal) {
	if (literal.find("inff") != std::string::npos || literal == "nanf")
		return (true);
	return (false);
}

//Convertions
void	ScalarConverter::convert(const std::string& literal) {
	e_type	type = identifyType(literal);

	if (type == CHAR)
		return (charToAll(literal));
	else if (type == INT)
		return (intToAll(literal));
	else if (type == FLOAT)
		return (floatToAll(literal));
	else if (type == DOUBLE)
		return (doubleToAll(literal));
	else if (type == INVALID)
		return (invalidCase());
}

void	ScalarConverter::charToAll(const std::string& literal) {
	char	c = literal[0];
	int 	i = static_cast<int>(c);
	float	f = static_cast<float>(c);
	double	d = static_cast<double>(c);
	printAllTypes(c, i, f, d);
}

void	ScalarConverter::intToAll(const std::string& literal) {
	long	l = std::strtol(literal.c_str(), NULL, 10);
	int	i = static_cast<int>(l);
	char	c = static_cast<char>(i);
	float	f = static_cast<float>(i);
	double	d = static_cast<double>(i);
	printAllTypes(c, i, f, d);
}

void	ScalarConverter::floatToAll(const std::string& literal) {
	float	f = static_cast<float>(std::strtod(literal.c_str(), NULL));
	char	c = static_cast<char>(f);
	int	i = static_cast<int>(f);
	double	d = static_cast<double>(f);
	printAllTypes(c, i, f, d);
}

void	ScalarConverter::doubleToAll(const std::string& literal) {
	double	d = std::strtod(literal.c_str(), NULL);
	char	c = static_cast<char>(d);
	int	i = static_cast<int>(d);
	float	f = static_cast<float>(d);
	printAllTypes(c, i, f, d);
}

void	ScalarConverter::invalidCase(void) {
	std::cout << "The input was invalid, try again with a valid input" << std::endl;
}

//Printing
void	ScalarConverter::printAllTypes(char c, int i, float f, double d) {
	printChar(c, d);
	printInt(i, d);
	printFloatandDouble(f, d);
}

void	ScalarConverter::printChar(char c, double d) {
	std::cout << "char: ";
	if (std::isnan(d) || std::isinf(d) || d < 0 || d > 127)
		std::cout << "impossible\n";
	else if (!std::isprint(c))
		std::cout << "Non displayable\n";
	else
		std::cout << "'" << c << "'" << "\n";
}

void	ScalarConverter::printInt(int i, double d) {
	std::cout << "int: ";
	if (std::isnan(d) || std::isinf(d) || d > INT_MAX || d < INT_MIN)
		std::cout << "impossible\n";
	else
		std::cout << i << "\n";
}

void	ScalarConverter::printFloatandDouble(float f, double d) {
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << f << "f\n";
	std::cout << "double: " << d << "\n";
}


