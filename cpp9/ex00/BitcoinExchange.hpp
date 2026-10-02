/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 14:50:10 by opapouts          #+#    #+#             */
/*   Updated: 2026/08/01 14:50:10 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#define DATE_LENGTH 10
#include <map>
#include <string>

//Enumerations
enum	e_ret {
	TRUE,
	MIN,
	MAX,
	INPUT,
	DATE
};

typedef	enum	e_file {
	DATABASE,
	PARAMETER
}	f_type;

class	BitcoinExchange {

	public	:

		//Orthodox Canonical Form
		BitcoinExchange(void);
		BitcoinExchange(std::string filename);
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator = (const BitcoinExchange& other);
		~BitcoinExchange(void);

		//Map Look Up
		void	mapLookUp(void);

		//Exception Classes
		class	FileException : public std::exception{
			public	:
				virtual const char *what(void) const throw();
		};
		class	InputException : public std::exception{
			public	:
				virtual const char *what(void) const throw();
		};
		class	DatabaseException : public std::exception{
			public	:
				virtual const char *what(void) const throw();
		};
	private	:

		//Parsing
		void	fillOutMap(void);


		//Database Validation
		bool	validDB(std::ifstream& file);
		bool	validDBDate(const std::string& date) const;
		bool	isDuplicate(const std::string& date) const;
		bool	validDBRate(const std::string& rateStr) const;
		bool	dotCheck(const std::string& rateStr) const;
		bool	isOverflow(const std::string& rateStr) const;
		bool	firstLineValid(const std::string& line, f_type file) const;

		//Date Validation
		bool	validDate(const std::string& line);
		bool	areSeparatorsinPlace(const std::string& date) const ;
		bool	areDateDigits(const std::string& date) const;
		bool	validMonth(const double& month) const;
		bool	validDay(const std::string& date, const double& month) const;
		bool	calendar(int year, int month, int day) const;
		bool	leapYear(int year, int month, int day) const;

		//Value Validation Tools
		e_ret	validValue(const std::string& line);
		e_ret	isValueDigits(const std::string& value) const;
		e_ret	valueOutOfBounds(const std::string& value);

		//Printing
		void	printErrorMsg(const std::string& line, e_ret ret) const;
		void	printValidMsg(void) const;

		//Map container
		std::map<std::string, float>	_database;

		//Class Fields
		std::string	_filename;
		std::string	_bufferDate;
		float		_bufferValue;

};

#endif
