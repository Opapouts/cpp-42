/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 01:33:52 by opapouts          #+#    #+#             */
/*   Updated: 2026/07/28 01:34:30 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <algorithm>
#include <iostream>

template <typename T>
typename T::iterator	easyfind(T& container, int value) {
	return (std::find(container.begin(), container.end(), value));
}

template <typename T>
void	printContainer(T& container) {
	typename T::iterator	it = container.begin();
	while (it != container.end()) {
		if (it != container.begin())
			std::cout << " ";
		std::cout << *it;
		++it;
	}
	std::cout << std::endl;
}
#endif
