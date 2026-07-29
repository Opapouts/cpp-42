/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 00:19:46 by opapouts          #+#    #+#             */
/*   Updated: 2026/07/26 00:19:54 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define	ITER_HPP
#include <iostream>

template <typename T, typename F>
void	iter(T *array, unsigned int length, F f) {
	for (unsigned int i = 0; i < length; i++) {
		f(array[i]);
	}
}
template <typename T>
void	printArray(T *a, unsigned int length) {
	for (unsigned int i = 0; i < length; i++) {
		if (i)
			std::cout << " ";
		std::cout << a[i];
	}
	std::cout << std::endl;
}
#endif
