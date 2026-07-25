/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 01:51:40 by opapouts          #+#    #+#             */
/*   Updated: 2026/07/24 01:51:44 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"

//Orthodox Canonical Form
Serializer::Serializer(void) {
	return ;
}

Serializer::Serializer(const Serializer& other) {
	(void) other;
	return ;
}

Serializer& Serializer::operator = (const Serializer& other) {
	(void) other;
	return (*this);
}

Serializer::~Serializer(void) {
	return ;
}

//Serialize && Deserialize
uintptr_t Serializer::serialize(Data* ptr) {
	uintptr_t	code = reinterpret_cast<uintptr_t>(ptr);
	return (code);
}

Data*	Serializer::deserialize(uintptr_t raw) {
	Data	*ptr = reinterpret_cast<Data *>(raw);
	return (ptr);
}
