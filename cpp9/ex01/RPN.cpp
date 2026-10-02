/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 16:07:29 by opapouts          #+#    #+#             */
/*   Updated: 2026/08/04 16:07:31 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>
#include <climits>

//Orthodox Canonical Form
RPN::RPN(void) {
	return ;
}

RPN::RPN(const RPN& other) : _stack(other._stack) {
	return ;
}

RPN::~RPN(void) {
	return ;
}

RPN&	RPN::operator = (const RPN& other) {
	if (this != &other)
		_stack = other._stack;
	return (*this);
}

//Member Functions
void	RPN::readInput(const std::string& input) {
	bool	acceptDigit = true;
	for (unsigned int i = 0; i < input.length(); i++) {
		if (input[i] == ' ')
			acceptDigit = true;
		else if (isdigit(input[i]) && acceptDigit) {
			_stack.push(input[i] - '0');
			acceptDigit = false;
		}
		else if (isOperator(input[i]) && _stack.size() > 1) {
			_operator = input[i];
			doOperation();
			acceptDigit = true;
		}
		else
			throw	ErrorException();
	}
	if (_stack.size() != 1)
		throw ErrorException();
	std::cout << _stack.top() << std::endl;
}

bool	RPN::isOperator(char c) const {
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return (true);
	return (false);
}

void	RPN::checkOverflow(double a, double b, oper op_code) const {
	double result;

	if (op_code == ADD) {
		result = b + a;
		if (result > INT_MAX || result < INT_MIN)
			throw OverflowException();
	}
	else if (op_code == SUB) {
		result = b - a;
		if (result > INT_MAX || result < INT_MIN)
			throw OverflowException();
	}
	else if (op_code == MULTI) {
		result = b * a;
		if (result > INT_MAX || result < INT_MIN)
			throw OverflowException();
	}
	else if (op_code == DIV) {
		result = b / a;
		if (result > INT_MAX || result < INT_MIN)
			throw OverflowException();
	}
}

void	RPN::doOperation(void) {
	double	a = _stack.top();
	_stack.pop();
	double	b = _stack.top();
	_stack.pop();

	if (_operator == '+') {
		checkOverflow(a, b, ADD);
		_stack.push(b + a);
	}
	else if (_operator == '-') {
		checkOverflow(a, b, SUB);
		_stack.push(b - a);
	}
	else if (_operator == '*') {
		checkOverflow(a, b, MULTI);
		_stack.push(b * a);
	}
	else if (_operator == '/') {
		if (a == 0)
			throw ErrorException();
		checkOverflow(a, b, DIV);
		_stack.push(b/a);
	}
}

//Exception Classes
const char* RPN::ErrorException::what(void) const throw () {
	return ("Error");
}

const char* RPN::OverflowException::what(void) const throw () {
	return ("Overflow error");
}
