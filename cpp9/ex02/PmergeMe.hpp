/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 17:42:47 by opapouts          #+#    #+#             */
/*   Updated: 2026/08/05 17:42:47 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <vector>
#include <string>
#include <deque>

enum	stl_type {
	VECTOR,
	DEQUE
};

//Typedefing the containers to save space
typedef std::vector<unsigned int> indexVe;
typedef std::deque<unsigned int> indexDe;

//Structs that will store the main and pend chains
typedef struct	s_containers {
	indexVe	mainChain;
	indexVe	pendChain;
}		containers;

typedef struct	s_boxes {
	indexDe	mainChain;
	indexDe	pendChain;
}		boxes;


class	PmergeMe {

	public	:
		//Orthodox Canonical Form
		PmergeMe(void);
		PmergeMe(const PmergeMe& other);
		~PmergeMe(void);
		PmergeMe& operator = (const PmergeMe& other);

		//Exception Class
		class	ErrorException : public std::exception {
			public	:
				virtual const char *what(void) const throw();
		};

		//Complete Program
		void		run(const std::string& input);

	private	:
		//Containers
		std::vector<int>	_valuesVe;
		std::deque<int>		_valuesDe;

		//Parsing Functions
		void		parseInputVe(const std::string& input);
		bool		isDuplicateVe(int value) const;
		void		parseInputDe(const std::string& input);
		bool		isDuplicateDe(int value) const;

		//General Functions
		unsigned int	jacobsRange(unsigned int jNumber) const;
		bool		isValidToken(const std::string& s) const;
		void		addElem(double value, bool *inNumber, int op_code);

		//Vector Functions
		indexVe		mergeInsertAlgo(indexVe& seq) const;
		containers 	initMainandPend(indexVe& sortedWinners, indexVe& loserOf) const;
		void 		jacobsthalNumber(containers& chains) const;
		unsigned int	binaryInsert(indexVe& chain, unsigned int valueIdx, unsigned int upperBound) const;

		//Double-Ended Queue Functions
		indexDe		mergeInsertAlgo(indexDe& serie) const;
		boxes		initMainandPend(indexDe& sortedWinners, indexDe& loserOf) const;
		void 		jacobsthalNumber(boxes& chains) const;
		unsigned int	binaryInsert(indexDe& chain, unsigned int valueIdx, unsigned int upperBound) const;

		//Output Functions
		void		printContainer(indexVe& sequence) const;
		void		printContainer(indexDe& serie) const;
		double		getTimeUs(void) const;
};

#endif
