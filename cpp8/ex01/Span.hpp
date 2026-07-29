/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 04:39:42 by opapouts          #+#    #+#             */
/*   Updated: 2026/07/28 04:39:42 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP
#include <vector>
#include <iterator>

class	Span {

	public	:
		Span(void);
		Span(unsigned int n);
		Span(const Span& other);
		~Span();
		Span& operator = (const Span& other);
		void	addNumber(int number);
		int	shortestSpan(void) const;
		int	longestSpan(void) const;
		void	printContainer(void) const;
		template <typename T>
		void	addRange(T first, T last) {
			if (_numbers.size() + std::distance(first, last) > _maxSize)
				throw	AddRangeException();
			_numbers.insert(_numbers.end(), first, last);
		}
		class	VectorIsFullException : public std::exception {
			public	:
				virtual const char *what(void) const throw();
		};
		class	VectorIsEmptyException : public std::exception {
			public	:
				virtual const char *what(void) const throw();
		};
		class	AddRangeException : public std::exception {
			public	:
				virtual const char *what(void) const throw();
		};

	private	:
		unsigned int			_maxSize;
		std::vector<int>		_numbers;

};

#endif
