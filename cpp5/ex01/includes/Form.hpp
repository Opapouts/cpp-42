/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 19:00:53 by opapouts          #+#    #+#             */
/*   Updated: 2026/07/12 19:00:56 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP
#include <string>

class	Bureaucrat;

class	Form {

	public	:
		Form(void);
		Form(std::string name);
		Form(std::string name, int signGrade, int executeGrade);
		Form(const Form& other);
		~Form(void);
		Form& operator = (const Form& other);
		std::string const& getName(void) const;
		bool	getIsSigned(void) const;
		int	getSignGrade(void) const;
		int	getExecuteGrade(void) const;
		void	beSigned(const Bureaucrat& bureaucrat);
		class	GradeTooHighException : public std::exception {
			public	:
				virtual const char *what(void) const throw();
		};
		class	GradeTooLowException : public std::exception {
			public	:
				virtual const char *what(void) const throw();
		};
	
	private	:
		const	std::string	_name;
		bool			_isSigned;
		const	int		_signGrade;
		const	int		_executeGrade;

};

std::ostream&	operator << (std::ostream& stream, const Form& other);

#endif
