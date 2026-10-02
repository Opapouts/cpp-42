/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 14:50:22 by opapouts          #+#    #+#             */
/*   Updated: 2026/08/01 14:50:23 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <exception>
#include <string>
#include <cstdlib>
#include <climits>

//Constructors and Destructors
BitcoinExchange::BitcoinExchange(void) : _filename("inputs/eval.txt") {
	fillOutMap();
	return ;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _database(other._database) {
	return ;
}

BitcoinExchange::BitcoinExchange(std::string filename) : _filename(filename) {
	fillOutMap();
	return ;
}

BitcoinExchange::~BitcoinExchange(void) {
	return ;
}

//Operator Overload
BitcoinExchange& BitcoinExchange::operator = (const BitcoinExchange& other) {
	if (this != &other)
		_database = other._database;
	return (*this);
}

//Parsing
void	BitcoinExchange::fillOutMap(void) {
	//Checking the database
	std::ifstream	file("data.csv");
	if (!file.is_open())
		throw DatabaseException();
	std::string	line;
	getline(file, line);
	if (!firstLineValid(line, DATABASE) || !validDB(file))
		throw DatabaseException();
}

//Database Validation
bool	BitcoinExchange::validDB(std::ifstream& file) {
	std::string	line;
	std::size_t	pos;
	std::string	date;
	std::string	rateStr;
	float		rate;

	while (getline(file, line)) {
		pos = line.find(',');
		if (pos != DATE_LENGTH)
			return (false);
		date = line.substr(0, pos);
		if (!validDBDate(date) || isDuplicate(date))
			return (false);
		rateStr = line.substr(pos + 1);
		if (!validDBRate(rateStr))
			return (false);
		rate = static_cast<float>(std::strtod(rateStr.c_str(), NULL));
		_database[date] = rate;
	}
	if (_database.empty())
		return (false);
	return (true);
}

bool	BitcoinExchange::validDBDate(const std::string& date) const {
	if (!areSeparatorsinPlace(date) || !areDateDigits(date))
		return (false);

	std::string	month;
	month = date.substr(5, 2);
	double	month_value = std::strtod(month.c_str(), NULL);

	if (!validMonth(month_value) || !validDay(date, month_value))
		return (false);
	return (true);
}

bool	BitcoinExchange::isDuplicate(const std::string& date) const {
	if (_database.find(date) != _database.end())
		return (true);
	return (false);
}

bool	BitcoinExchange::validDBRate(const std::string& rateStr) const {
	if (rateStr.find_first_not_of("0123456789.") != std::string::npos)
		return (false);
	if (rateStr.empty() || !dotCheck(rateStr))
		return (false);
	if (isOverflow(rateStr))
		return (false);
	return (true);
}

bool	BitcoinExchange::dotCheck(const std::string& rateStr) const {
	int	counter = 0;
	int	i = 0;

	while (rateStr[i]) {
		if (rateStr[i] == '.') {
			if (!i)
				return (false);
			counter++;
		}
		i++;
	}
	if (rateStr[i - 1] == '.')
		return (false);
	if (counter > 1 || (counter == 1 && i == 1))
		return (false);
	return (true);
}

bool	BitcoinExchange::isOverflow(const std::string& rateStr) const {
	errno = 0;
	char	*endptr = NULL;
	double	value;

	value = std::strtod(rateStr.c_str(), &endptr);
	if (errno == ERANGE)
		return (true);
	if (value > INT_MAX || value < INT_MIN)
		return (true);
	return (false);
}

bool	BitcoinExchange::firstLineValid(const std::string& line, f_type file) const {
	if (file == DATABASE) {
		std::string tmp = line;
		if (!tmp.empty() && tmp[tmp.length() - 1] == '\r')
			tmp.erase(tmp.length() - 1);
		if (tmp != "date,exchange_rate")
			return (false);
	}
	else if (file == PARAMETER) {
		std::string tmp;
		for (unsigned int i = 0; i < line.length(); ++i) {
			if (line[i] != ' ' && line[i] != '\t' && line[i] != '\r')
				tmp += line[i];
		}
		if (tmp != "date|value")
			return (false);
	}
	return (true);
}

//Date Validation
bool	BitcoinExchange::validDate(const std::string& line) {
	std::size_t	pos;
	std::string	date;

	pos = line.find('|');
	if (pos == std::string::npos || pos < DATE_LENGTH)
		return (false);
	date = line.substr(0, DATE_LENGTH);
	if (line.substr(10, pos - DATE_LENGTH).find_first_not_of(' ') != std::string::npos)
		return (false);
	if (!areSeparatorsinPlace(date) || !areDateDigits(date))
		return (false);

	std::string	month;
	month = date.substr(5, 2);
	double	month_value = std::strtod(month.c_str(), NULL);

	if (!validMonth(month_value) || !validDay(date, month_value))
		return (false);
	_bufferDate = date;
	return (true);
}

bool	BitcoinExchange::areSeparatorsinPlace(const std::string& date) const {
	if (date[4] != '-' || date[7] != '-')
		return (false);
	return (true);
}

bool	BitcoinExchange::areDateDigits(const std::string& date) const {
	for (unsigned int i = 0; i < date.length(); i++) {
		if (i == 4 || i == 7)
			continue ;
		if (!isdigit(date[i]))
			return (false);
	}
	return (true);
}

bool	BitcoinExchange::validMonth(const double& month) const {

	if (month < 1 || month > 12)
		return (false);
	return (true);
}

bool	BitcoinExchange::validDay(const std::string& date, const double& month) const {
	std::string	day;
	double		value;
	std::string	year;
	double		year_value;

	day = date.substr(8, 2);
	value = std::strtod(day.c_str(), NULL);
	if (value < 1 || value > 31)
		return (false);
	year = date.substr(0, 4);
	year_value = std::strtod(year.c_str(), NULL);
	if (!year_value)
		return (false);
	if (!calendar(static_cast<int>(year_value), static_cast<int>(month), static_cast<int>(value)))
		return (false);
	return (true);
}

bool	BitcoinExchange::calendar(int year, int month, int day) const {
	if (day == 31 && (month == 4 || month == 6 || month == 9 || month == 11))
		return (false);
	if (!leapYear(year, month, day))
		return (false);
	return (true);
}

bool	BitcoinExchange::leapYear(int year, int month, int day) const {
	bool	isLeapYear = false;

	if (year % 4 == 0)
		isLeapYear = true;
	if (year % 100 == 0)
		isLeapYear = false;
	if (year % 400 == 0)
		isLeapYear = true;
	if (month == 2) {
		if (day > 29)
			return (false);
		if (day == 29 && !isLeapYear)
			return (false);
	}
	return (true);
}

//Value Validation
e_ret	BitcoinExchange::validValue(const std::string& line) {
	std::size_t	pos;
	std::string	str;
	std::string	value;
	e_ret		ret;

	pos = line.find('|');
	str = line.substr(pos + 1);
	pos = str.find_first_not_of(' ');
	if (pos == std::string::npos)
		return (INPUT);
	value = str.substr(pos);
	ret = isValueDigits(value);
	if (ret)
		return (ret);
	return (valueOutOfBounds(value));
}

e_ret	BitcoinExchange::isValueDigits(const std::string& value) const {

	if (!value.length())
		return (INPUT);

	int	dots = 0;
	int	digits = 0;
	bool	hasMinus = false;

	if (value[0] == '-') {
		hasMinus = true;
		if (value.length() == 1)
			return (INPUT);
	}
	for (unsigned int i = (hasMinus ? 1 : 0); i < value.length(); i++) {
		if (value[i] == '.') {
			dots++;
			if (dots > 1)
				return (INPUT);
			continue;
		}
		if (isdigit(value[i])) {
			digits++;
			continue;
		}
		return (INPUT);
	}
	if (!digits)
		return (INPUT);
	if (value[0] == '-')
		return (MIN);
	return (TRUE);
}

e_ret	BitcoinExchange::valueOutOfBounds(const std::string& value) {
	double	number;

	if (isOverflow(value))
		return (MAX);
	number = std::strtod(value.c_str(), NULL);
	if (number <= 0)
		return (MIN);
	if (number >= 1000)
		return (MAX);
	_bufferValue = static_cast<float>(number);
	return (TRUE);
}

void	BitcoinExchange::printErrorMsg(const std::string& line, e_ret ret) const {
	std::cout << "Error: ";
	if (ret == INPUT)
		std::cerr << "bad input => " << line << std::endl;
	else if (ret == MIN)
		std::cerr << "not a positive number." << std::endl;
	else if  (ret == MAX)
		std::cerr << "too large a number." << std::endl;
	else if (ret == DATE)
		std::cerr << "date is too early." << std::endl;
}

void	BitcoinExchange::printValidMsg(void) const {
	std::cout << _bufferDate << " => " << _bufferValue << " = ";

	std::map<std::string, float>::const_iterator it = _database.lower_bound(_bufferDate);
	if (it != _database.end() && it->first == _bufferDate) {
		std::cout << _bufferValue * it->second << std::endl;
		return;
	}
	if (it == _database.begin()) {
		std::string buffer = "buffer";
		printErrorMsg(buffer, DATE);
	}
	else {
		--it;
		std::cout << _bufferValue * it->second << std::endl;
	}
}

//Map Look Up
void	BitcoinExchange::mapLookUp(void) {
	std::ifstream file(_filename.c_str());
	if (!file.is_open())
		throw FileException();
	std::string	line;
	std::string	key;
	e_ret		ret;

	getline(file, line);
	if (!firstLineValid(line, PARAMETER))
		throw InputException();
	while (getline(file, line)) {
		if (!validDate(line)) {
			printErrorMsg(line, INPUT);
			continue ;
		}
		ret = validValue(line);
		if (ret) {
			printErrorMsg(line, ret);
			continue ;
		}
		try {
			printValidMsg();
		}
		catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
}

//Exception Classes
const char* BitcoinExchange::FileException::what(void) const throw () {
	return ("Error: could not open file.");
}

const char* BitcoinExchange::InputException::what(void) const throw () {
	return ("Content error.");
}

const char* BitcoinExchange::DatabaseException::what(void) const throw () {
	return ("Database error.");
}
