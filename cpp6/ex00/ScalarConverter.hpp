/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 19:50:54 by opapouts          #+#    #+#             */
/*   Updated: 2026/07/20 19:51:00 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#include <string>

enum	e_type {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	INVALID
};

class	ScalarConverter {

	public	:
		static void	convert(const std::string& literal);

	private	:
		//Orthodox Canonical Form
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter& other);
		~ScalarConverter(void);
		ScalarConverter& operator = (const ScalarConverter& other);

		//Identifying Type && Helper Functions
		static e_type		identifyType(const std::string& literal);
		static bool		isChar(const std::string& literal);
		static bool		isPseudo(const std::string& literal);
		static bool		isInt(const std::string& literal, double value);
		static bool	isLastCharF(char *endptr);
		static bool	hasDecimalPoint(const std::string& literal);
		static bool	isPseudoFloat(const std::string& literal);

		//Convertions
		static void	charToAll(const std::string& literal);
		static void	intToAll(const std::string& literal);
		static void	floatToAll(const std::string& literal);
		static void	doubleToAll(const std::string& literal);
		static void	invalidCase(void);

		//Printing
		static void	printAllTypes(char c, int i, float f, double d);
		static void	printChar(char c, double d);
		static void	printInt(int i, double d);
		static void	printFloatandDouble(float f, double d);

};

#endif
