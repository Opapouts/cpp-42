/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 19:16:06 by opapouts          #+#    #+#             */
/*   Updated: 2026/07/18 19:16:13 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP
#include <string>

class	Bureaucrat;

class	AForm {

	public	:
		AForm(void);
		AForm(std::string name);
		AForm(std::string name, int signGrade, int executeGrade);
		AForm(const AForm& other);
		virtual	~AForm(void);
		AForm& operator = (const AForm& other);
		std::string const& getName(void) const;
		bool	getIsSigned(void) const;
		int	getSignGrade(void) const;
		int	getExecuteGrade(void) const;
		void	beSigned(const Bureaucrat& bureaucrat);
		virtual void	execute(Bureaucrat const& executor) const;
		class	GradeTooHighException : public std::exception {
			public	:
				virtual const char *what(void) const throw();
		};
		class	GradeTooLowException : public std::exception {
			public	:
				virtual const char *what(void) const throw();
		};
		class	ExecutionException : public std::exception {
			public	:
				virtual const char *what(void) const throw();
		};
		class	FormNotSignedException : public std::exception {
			public	:
				virtual const char *what(void) const throw();
		};
	
	protected :
		virtual void	executeAction(void) const = 0;
	private	:
		const	std::string	_name;
		bool			_isSigned;
		const	int		_signGrade;
		const	int		_executeGrade;

};

std::ostream&	operator << (std::ostream& stream, const AForm& other);

#endif
