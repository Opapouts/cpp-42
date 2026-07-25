/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 01:51:32 by opapouts          #+#    #+#             */
/*   Updated: 2026/07/24 01:51:38 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"
#include <iostream>

int	main(void) {
	Data	data1 = {3, "John"};
	uintptr_t	raw1;
	Data	data2 = {42, "Olise"};
	uintptr_t	raw2;
	Data	data3 = {-35, "Trump"};
	uintptr_t	raw3;

	std::cout << "====Initial addresses of structures====" << std::endl;
	std::cout << "Address: " << &data1 << std::endl;
	std::cout << "Address: " << &data2 << std::endl;
	std::cout << "Address: " << &data3 << std::endl;
	std::cout << std::endl;

	raw1 = Serializer::serialize(&data1);
	raw2 = Serializer::serialize(&data2);
	raw3 = Serializer::serialize(&data3);

	Data	*ptr1 = Serializer::deserialize(raw1);
	Data	*ptr2 = Serializer::deserialize(raw2);
	Data	*ptr3 = Serializer::deserialize(raw3);

	std::cout << "====Addresses of structures after serialization and deserialization====" << std::endl;
	std::cout << "Address: " << ptr1 << std::endl;
	std::cout << "Address: " << ptr2 << std::endl;
	std::cout << "Address: " << ptr3 << std::endl;
	std::cout << std::endl;

	std::cout << "====Here are the values of the structures after the operations====" << std::endl;
	std::cout << "Name: " << ptr1->name << std::endl << "Number: " << ptr1->number << std::endl;
	std::cout << std::endl;
	std::cout << "Name: " << ptr2->name << std::endl << "Number: " << ptr2->number << std::endl;
	std::cout << std::endl;
	std::cout << "Name: " << ptr3->name << std::endl << "Number: " << ptr3->number << std::endl;
	return (0);
}

