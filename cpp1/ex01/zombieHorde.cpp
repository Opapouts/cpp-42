/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 21:49:49 by opapouts          #+#    #+#             */
/*   Updated: 2026/04/21 21:49:49 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <cstdlib>

Zombie*	zombieHorde(int N, std::string name) {
	Zombie* zHorde;

	if (N <= 0) {
		std::cout << "Wrong input, please use a positive number\n";
		exit(1);
	}
	zHorde = new Zombie[N];
	for (int i = 0; i < N; i++)
		zHorde[i].setName(name);
	return (zHorde);
}
