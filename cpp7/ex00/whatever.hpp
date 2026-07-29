/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 23:19:13 by opapouts          #+#    #+#             */
/*   Updated: 2026/07/25 23:19:16 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void	swap(T &a, T &b) {
	T tmp = a;
	a = b;
	b = tmp;
	return ;
}

template <typename T>
T	min(const T &a, const T &b) {
	return ((a < b) ? a : b);
}

template <typename T>
T	max(const T &a, const T &b) {
	return ((a > b) ? a : b);
}
#endif
