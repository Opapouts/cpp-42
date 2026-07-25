/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 01:41:12 by opapouts          #+#    #+#             */
/*   Updated: 2026/07/24 01:41:14 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP
#include <stdint.h>
#include "Data.hpp"

class	Serializer {

	public	:
		static uintptr_t serialize(Data* ptr);
		static Data*	deserialize(uintptr_t raw);

	private	:
		Serializer(void);
		Serializer(const Serializer& other);
		Serializer& operator = (const Serializer& other);
		~Serializer(void);
};

#endif
