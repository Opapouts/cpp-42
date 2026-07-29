/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 10:41:49 by opapouts          #+#    #+#             */
/*   Updated: 2026/07/29 10:41:49 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include <stack>
#include <iostream>

template <typename T>
class	MutantStack : public std::stack<T> {

	public	:
		//Orthodox Canonical Form
		MutantStack(void) {
			return ;
		}
		MutantStack(const MutantStack<T>& other) : std::stack<T>(other) {
			return ;
		}
		~MutantStack(void) {
			return ;
		}
		MutantStack<T>& operator = (const MutantStack<T>& other) {
			std::stack<T>::operator = (other);
			return (*this);
		}

		//Iterators
		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin() { return (this->c.begin()); }
		iterator end() { return (this->c.end()); }

		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		const_iterator	begin() const { return (this->c.begin()); }
		const_iterator	end() const { return (this->c.end()); }
		void	printContainer(void) const {
			for (const_iterator it = this->c.begin(); it != this->c.end(); ++it) {
				if (it != this->c.begin())
					std::cout << " ";
				std::cout << *it;
			}
			std::cout << std::endl;
		}

};

#endif
