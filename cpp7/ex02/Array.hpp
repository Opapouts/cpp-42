/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 02:37:19 by opapouts          #+#    #+#             */
/*   Updated: 2026/07/26 02:37:20 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <exception>

template <typename T>
class Array {

	public	:
		Array(void);
		Array(unsigned int n);
		Array(const Array& other);
		~Array(void);
		Array& operator = (const Array& other);
		T& operator [] (unsigned int index);
		const T& operator [] (unsigned int index) const;
		unsigned int	size(void) const;
		class	IndexOutOfBounds : public std::exception {
			virtual const char *what(void) const throw () {
				return ("Index out of Bounds");
			}
		};
		void	printArray(void) const;

	private	:
		T 		*_array;
		unsigned int	_size;
};

#include "Array.tpp"

#endif
