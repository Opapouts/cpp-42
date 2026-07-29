/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 04:39:51 by opapouts          #+#    #+#             */
/*   Updated: 2026/07/28 04:39:53 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <algorithm>

//Constructors && Destructor
Span::Span(void) : _maxSize(5) {
	return ;
}

Span::Span(unsigned int n) : _maxSize(n) {
	return ;
}

Span::Span(const Span& other) : _maxSize(other._maxSize) {
	_numbers = other._numbers;
	return ;
}

Span::~Span(void) {
	return ;
}

//Operator Overload
Span&	Span::operator = (const Span& other) {
	if (this == &other)
		return (*this);
	_maxSize = other._maxSize;
	_numbers = other._numbers;
	return (*this);
}

//Member Functions
void	Span::addNumber(int number) {
	if (_numbers.size() == _maxSize)
		throw	VectorIsFullException();
	_numbers.push_back(number);
}

int	Span::shortestSpan(void) const {
	if (!_numbers.size() || _numbers.size() == 1)
		throw	VectorIsEmptyException();
	std::vector<int>	sorted(_numbers);
	std::sort(sorted.begin(), sorted.end());
	int	span = sorted[1] - sorted[0];
	for (unsigned int i = 1; i < sorted.size() - 1; i++) {
		if (sorted[i + 1] - sorted[i] < span)
			span = sorted[i + 1] - sorted[i];
	}
	return (span);
}

int	Span::longestSpan(void) const {
	if (!_numbers.size() || _numbers.size() == 1)
		throw	VectorIsEmptyException();
	std::vector<int>	sorted(_numbers);
	std::sort(sorted.begin(), sorted.end());
	return (*(sorted.end() - 1) - *sorted.begin());
}

void	Span::printContainer(void) const {
	for (unsigned int i = 0; i < _numbers.size(); i++) {
		if (i)
			std::cout << " ";
		std::cout << _numbers[i];
	}
	std::cout << std::endl;
}

//Exception Classes
const char *Span::VectorIsFullException::what(void) const throw () {
	return ("The vector is full");
}

const char *Span::VectorIsEmptyException::what(void) const throw () {
	return ("The vector is empty");
}

const char *Span::AddRangeException::what(void) const throw () {
	return ("Range is too big to be added");
}
