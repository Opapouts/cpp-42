/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 02:47:23 by opapouts          #+#    #+#             */
/*   Updated: 2026/07/26 02:47:24 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
#define ARRAY_TPP
#include "Array.hpp"
#include <iostream>

//Constructors && Destructor
template <typename T>
Array<T>::Array(void) : _array(NULL), _size(0) {
	return ;
}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n) {
	return ;
}

template <typename T>
Array<T>::Array(const Array& other) : _array(new T[other._size]), _size(other._size) {
	for (unsigned int i = 0; i < _size; i++)
		_array[i] = other._array[i];
	return ;
}

template <typename T>
Array<T>::~Array(void) {
	delete[] _array;
}

//Operator Overloads
template <typename T>
Array<T>& Array<T>::operator = (const Array& other) {
	if (this == &other)
		return (*this);
	delete[] _array;
	_array = new T[other._size];
	_size = other._size;
	for (unsigned int i = 0; i < _size; i++)
		_array[i] = other._array[i];
	return (*this);
}

template <typename T>
T& Array<T>::operator [] (unsigned int index) {
	if (index >= _size)
		throw IndexOutOfBounds();
	return (_array[index]);
}

template <typename T>
const T& Array<T>::operator [] (unsigned int index) const {
	if (index >= _size)
		throw IndexOutOfBounds();
	return (_array[index]);
}

//Member Function
template <typename T>
unsigned int	Array<T>::size(void) const {
	return (_size);
}

template <typename T>
void	Array<T>::printArray(void) const {
	for (unsigned int i = 0; i < _size; i++) {
		if (i)
			std::cout << " ";
		std::cout << _array[i];
	}
	std::cout << std::endl;
}

#endif
