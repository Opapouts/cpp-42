/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 16:07:35 by opapouts          #+#    #+#             */
/*   Updated: 2026/08/04 16:07:35 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP
#include <stack>
#include <list>
#include <string>

typedef	enum	s_oper {
	ADD,
	SUB,
	MULTI,
	DIV
}	oper;

class	RPN {

	public	:
		//Orthodox Canonical Form
		RPN(void);
		RPN(const RPN& other);
		~RPN(void);
		RPN& operator = (const RPN& other);

		//Member Functions
		void	readInput(const std::string& input);

		//Exception Classes
		class	ErrorException : public std::exception {
			public	:
				virtual const char *what(void) const throw();
		};
		class	OverflowException : public std::exception {
			public	:
				virtual const char *what(void) const throw();
		};

	private	:
		bool	isOperator(char c) const;
		void	checkOverflow(double a, double b, oper op_code) const;
		void	doOperation(void);
		std::stack<double, std::list<double> >	_stack;
		char				_operator;
};

#endif
