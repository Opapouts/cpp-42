/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 17:42:54 by opapouts          #+#    #+#             */
/*   Updated: 2026/08/05 17:42:55 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cstdlib>
#include <climits>
#include <iostream>
#include <sys/time.h>

/***********************************************************
*              Orthodox Canonical Form                     *
***********************************************************/
PmergeMe::PmergeMe(void) {
	return ;
}

PmergeMe::PmergeMe(const PmergeMe& other) : _valuesVe(other._valuesVe), _valuesDe(other._valuesDe) {
	return ;
}

PmergeMe::~PmergeMe(void) {
	return ;
}

PmergeMe& PmergeMe::operator = (const PmergeMe& other) {
	if (this != &other) {
		_valuesVe = other._valuesVe;
		_valuesDe = other._valuesDe;
	}
	return (*this);
}

/***********************************************************
*                    Exception Class                       *
***********************************************************/
const char* PmergeMe::ErrorException::what(void) const throw() {
	return ("Wrong input, try again");
}

/***********************************************************
*                         Parsing                          *
***********************************************************/

//Vector
void	PmergeMe::parseInputVe(const std::string& input) {
	int		start = 0;
	bool		inNumber = false;
	std::string	str;
	double		value = 0;

	for (unsigned int i = 0; i < input.length(); ++i) {
		if (!isdigit(input[i]) && input[i] != ' ' && input[i] != '+')
			throw ErrorException();
		if (!inNumber && (isdigit(input[i]) || input[i] == '+')) {
			inNumber = true;
			start = i;
		}
		else if (inNumber && input[i] == ' ' ) {
			if (input[i] == ' ')
				str = input.substr(start, i - start);
			if (!isValidToken(str))
				throw (ErrorException());
			value = std::strtod(str.c_str(), NULL);
			if (!value || value > INT_MAX || isDuplicateVe(static_cast<int>(value)))
				throw ErrorException();
			addElem(value, &inNumber, VECTOR);
		}
	}
	if (inNumber) {
		str = input.substr(start);
		if (!isValidToken(str))
			throw ErrorException();
		value = std::strtod(str.c_str(), NULL);
		if (!value || value > INT_MAX || isDuplicateVe(static_cast<int>(value)))
			throw ErrorException();
		addElem(value, &inNumber, VECTOR);
	}
}

bool	PmergeMe::isDuplicateVe(int value) const {
	for (unsigned int i = 0; i < _valuesVe.size(); ++i) {
		if (value == _valuesVe[i])
			return (true);
	}
	return (false);
}

//Double-Ended Queue
void	PmergeMe::parseInputDe(const std::string& input) {
	int		start = 0;
	bool		inNumber = false;
	std::string	str;
	double		value = 0;

	for (unsigned int i = 0; i < input.length(); ++i) {
		if (!isdigit(input[i]) && input[i] != ' ' && input[i] != '+')
			throw ErrorException();
		if (!inNumber && (isdigit(input[i]) || input[i] == '+')) {
			inNumber = true;
			start = i;
		}
		else if (inNumber && input[i] == ' ' ) {
			if (input[i] == ' ')
				str = input.substr(start, i - start);
			if (!isValidToken(str))
				throw (ErrorException());
			value = std::strtod(str.c_str(), NULL);
			if (!value || value > INT_MAX || isDuplicateDe(static_cast<int>(value)))
				throw ErrorException();
			addElem(value, &inNumber, DEQUE);
		}
	}
	if (inNumber) {
		str = input.substr(start);
		if (!isValidToken(str))
			throw ErrorException();
		value = std::strtod(str.c_str(), NULL);
		if (!value || value > INT_MAX || isDuplicateDe(static_cast<int>(value)))
			throw ErrorException();
		addElem(value, &inNumber, DEQUE);
	}
}

bool	PmergeMe::isDuplicateDe(int value) const {
	for (unsigned int i = 0; i < _valuesDe.size(); ++i) {
		if (value == _valuesDe[i])
			return (true);
	}
	return (false);
}

/***********************************************************
*                    General Functions                     *
***********************************************************/
//The actual formula
//Jn = (2^n - (-1)^n) / 3
//3, 5, 11, 21, 43, 85..
unsigned int PmergeMe::jacobsRange(unsigned int jNumber) const {
	if (!jNumber)
		return (0);
	if (jNumber == 1)
		return (1);
	return (jacobsRange(jNumber - 1) + 2 * jacobsRange(jNumber - 2));
}

bool	PmergeMe::isValidToken(const std::string& s) const {
	unsigned int i = 0;
	if (s[i] == '+')
		++i;
	if (i == s.length())
		return (false);
	for (; i < s.length(); ++i) {
		if (!isdigit(s[i]))
			return (false);
	}
	return (true);
}

void	PmergeMe::addElem(double value, bool *inNumber, int op_code) {
	if (op_code == VECTOR) {
		int	elem = static_cast<int>(value);
		_valuesVe.push_back(elem);
		*inNumber = false;
	}
	else if (op_code == DEQUE) {
		int	elem = static_cast<int>(value);
		_valuesDe.push_back(elem);
		*inNumber = false;
	}
}

/***********************************************************
*                         Vector                           *
***********************************************************/
indexVe PmergeMe::mergeInsertAlgo(indexVe& seq) const {
	unsigned int size = seq.size();
	if (size < 2)//Return condition
		return (seq);
	indexVe	winners(size / 2);
	indexVe	loserOf(_valuesVe.size());
	for (unsigned int i = 0; i < size - 1 ; i += 2) {
		if (_valuesVe[seq[i]] > _valuesVe[seq[i + 1]]) {
			winners[i / 2] = seq[i];
			loserOf[seq[i]] = seq[i + 1];
		}
		else
		{
			winners[i / 2] = seq[i + 1];
			loserOf[seq[i + 1]] = seq[i];
		}
	}

	indexVe sortedWinners;
	sortedWinners = mergeInsertAlgo(winners);//Recursion
	//Creating the main and pend chains
	containers chains = initMainandPend(sortedWinners, loserOf);
	jacobsthalNumber(chains);
	if (seq.size() % 2 != 0)
		binaryInsert(chains.mainChain, seq.back(), chains.mainChain.size());
	return (chains.mainChain);
}

containers	PmergeMe::initMainandPend(indexVe& sortedWinners, indexVe& loserOf) const {
	indexVe		mainChain(sortedWinners.size() + 1);
	indexVe		pendChain(sortedWinners.size() - 1);

	mainChain[0] = loserOf[sortedWinners[0]];
	for (unsigned int i = 0; i < sortedWinners.size(); ++i) {
		mainChain[i + 1] = sortedWinners[i];
		if (i < sortedWinners.size() - 1)
			pendChain[i] = loserOf[sortedWinners[i + 1]];
	}

	containers	chains;
	chains.mainChain = mainChain;
	chains.pendChain = pendChain;
	return (chains);
}

unsigned int	PmergeMe::binaryInsert(indexVe& chain, unsigned int valueIdx, const unsigned int upperBound) const {
	unsigned int low = 0;
	unsigned int high = upperBound;
	int value = _valuesVe[valueIdx];

	while (low < high) {
		unsigned int mid = low + (high - low) / 2;
		if (value < _valuesVe[chain[mid]])
			high = mid;
		else
			low = mid + 1;
	}
	chain.insert(chain.begin() + low, valueIdx);
	return (low);
}

//We start with Jacobsthal number 3(3, 2), then 5(5, 4), then 11(11, 10...6)
void PmergeMe::jacobsthalNumber(containers& chains) const {
	if (chains.pendChain.empty())
		return ;
	unsigned int totalPairs = chains.pendChain.size() + 1;
	indexVe pos(totalPairs + 1);
	for (unsigned int k = 1; k <= totalPairs; ++k)
		pos[k] = k;

	unsigned int	lastJacob = 1;
	unsigned int	jIndex = 3;
	while (lastJacob < totalPairs) {
		unsigned int jNumber = jacobsRange(jIndex);
		unsigned int start;
		if (jNumber < totalPairs)
			start = jNumber;
		else
			start = totalPairs;
		for (unsigned int k = start; k > lastJacob; --k) {
			unsigned int upperBound = pos[k];
			unsigned int insertIndex = binaryInsert(chains.mainChain, chains.pendChain[k - 2], upperBound);
			for (unsigned int i = 1; i <= totalPairs; ++i) {
				if (pos[i] >= insertIndex)
					pos[i]++;
			}
		}
	lastJacob = jNumber;
	jIndex++;
	}
}

/***********************************************************
*                 Double-Ended Queue                       *
***********************************************************/
indexDe	PmergeMe::mergeInsertAlgo(indexDe& serie) const {
	unsigned int size = serie.size();
	if (size < 2)//Return condition
		return (serie);
	indexDe winners(size / 2);
	indexDe loserOf(_valuesDe.size());
	for (unsigned int i = 0; i < size - 1 ; i += 2) {
		if (_valuesDe[serie[i]] > _valuesDe[serie[i + 1]]) {
			winners[i / 2] = serie[i];
			loserOf[serie[i]] = serie[i + 1];
		}
		else
		{
			winners[i / 2] = serie[i + 1];
			loserOf[serie[i + 1]] = serie[i];
		}
	}

	indexDe	sortedWinners;
	sortedWinners = mergeInsertAlgo(winners);//Recursion
	//Creating the main and pend chains
	boxes	chains = initMainandPend(sortedWinners, loserOf);
	jacobsthalNumber(chains);
	if (serie.size() % 2 != 0)
		binaryInsert(chains.mainChain, serie.back(), chains.mainChain.size());
	return (chains.mainChain);
}

boxes	PmergeMe::initMainandPend(indexDe& sortedWinners, indexDe& loserOf) const {

	indexDe		mainChain(sortedWinners.size() + 1);
	indexDe		pendChain(sortedWinners.size() - 1);

	mainChain[0] = loserOf[sortedWinners[0]];
	for (unsigned int i = 0; i < sortedWinners.size(); ++i) {
		mainChain[i + 1] = sortedWinners[i];
		if (i < sortedWinners.size() - 1)
			pendChain[i] = loserOf[sortedWinners[i + 1]];
	}

	boxes	chains;
	chains.mainChain = mainChain;
	chains.pendChain = pendChain;
	return (chains);
}

unsigned int	PmergeMe::binaryInsert(indexDe& chain, unsigned int valueIdx, unsigned int upperBound) const {
	unsigned int low = 0;
	unsigned int high = upperBound;
	int value = _valuesDe[valueIdx];

	while (low < high) {
		unsigned int mid = low + (high - low) / 2;
		if (value < _valuesDe[chain[mid]])
			high = mid;
		else
			low = mid + 1;
	}
	chain.insert(chain.begin() + low, valueIdx);
	return (low);
}

void PmergeMe::jacobsthalNumber(boxes& chains) const {
	if (chains.pendChain.empty())
		return ;
	unsigned int totalPairs = chains.pendChain.size() + 1;
	indexDe pos(totalPairs + 1);
	for (unsigned int k = 1; k <= totalPairs; ++k)
		pos[k] = k;

	unsigned int	lastJacob = 1;
	unsigned int	jIndex = 3;

	while (lastJacob < totalPairs) {
		unsigned int jNumber = jacobsRange(jIndex);
		unsigned int start;
		if (jNumber < totalPairs)
			start = jNumber;
		else
			start = totalPairs;
		for (unsigned int k = start; k > lastJacob; --k) {
			unsigned int upperBound = pos[k];
			unsigned int insertIndex = binaryInsert(chains.mainChain, chains.pendChain[k - 2], upperBound);
			for (unsigned int i = 1; i <= totalPairs; ++i) {
				if (pos[i] >= insertIndex)
					pos[i]++;
			}
		}
	lastJacob = jNumber;
	jIndex++;
	}
}

/***********************************************************
*                       Outputting                         *
***********************************************************/
void	PmergeMe::printContainer(indexVe& sequence) const {
							   
	unsigned int size = sequence.size();
	bool		verbose = true;

	if (size > 10) {
		size = 5;
		verbose = false;
	}
	for (unsigned int i = 0; i < size; ++i) {
		if (i)
			std::cout << " ";
		std::cout << _valuesVe[sequence[i]];
	}
	if (!verbose)
		std::cout << " [...]";
}

void	PmergeMe::printContainer(indexDe& serie) const {

	unsigned int size = serie.size();
	bool		verbose = true;

	if (size > 10) {
		size = 5;
		verbose = false;
	}

	for (unsigned int i = 0; i < size; ++i) {
		if (i)
			std::cout << " ";
		std::cout << _valuesDe[serie[i]];
	}
	if (!verbose)
		std::cout << " [...]";
}

double	PmergeMe::getTimeUs(void) const {
	struct	timeval	tv;
	double	result;

	gettimeofday(&tv, NULL);
	result = static_cast<double>(tv.tv_sec) * 1000000.0 + static_cast<double>(tv.tv_usec);
	return (result);
}

/***********************************************************
*                    Complete Program                      *
***********************************************************/
void	PmergeMe::run(const std::string& input) {
	parseInputVe(input);
	parseInputDe(input);

	indexVe seqVe(_valuesVe.size());
	for (unsigned int i = 0; i < _valuesVe.size(); ++i)
		seqVe[i] = i;

	std::cout << "Before:   ";
	printContainer(seqVe);
	std::cout << std::endl;

	double	startVe = getTimeUs();
	indexVe resultVe = mergeInsertAlgo(seqVe);
	double	endVe = getTimeUs();

	std::cout << "After:   ";
	printContainer(resultVe);
	std::cout << std::endl;

	indexDe serieDe(_valuesDe.size());
	for (unsigned int i = 0; i < _valuesDe.size(); ++ i)
		serieDe[i] = i;

	std::cout << "Before:   ";
	printContainer(serieDe);
	std::cout << std::endl;


	double	startDe = getTimeUs();
	indexDe	resultDe = mergeInsertAlgo(serieDe);
	double	endDe = getTimeUs();

	std::cout << "After:   ";
	printContainer(resultDe);
	std::cout << std::endl;

	std::cout << "Time to process a range of " << _valuesVe.size()
		<< " elements with std::vector : " << (endVe - startVe)
		<< " us" << std::endl;
	std::cout << "Time to process a range of " << _valuesDe.size()
		<< " elements with std::deque : " << (endDe - startDe)
		<< " us" << std::endl;
}
