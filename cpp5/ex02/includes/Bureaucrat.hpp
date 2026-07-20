/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 18:39:35 by opapouts          #+#    #+#             */
/*   Updated: 2026/07/16 18:39:35 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <string>
#include <exception>

class	AForm;

class	Bureaucrat {

	public	:
		Bureaucrat(void);
		Bureaucrat(std::string name);
		Bureaucrat(int grade);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& other);
		~Bureaucrat(void);
		Bureaucrat& operator = (const Bureaucrat& other);
		std::string const& getName(void) const;
		int	getGrade(void) const;
		void	increaseGrade(void);
		void	decreaseGrade(void);
		void	signForm(AForm& form);
		void	executeForm(AForm const& form) const;
		class	GradeTooHighException : public std::exception {
			public	:
				virtual const char *what(void) const throw();
		};
		class	GradeTooLowException : public std::exception{
			public	:
				virtual const char *what(void) const throw();
		};

	private :
		const std::string	_name;
		int		_grade; //150 the lowest, 1 the highest
};

std::ostream&	operator << (std::ostream& stream, const Bureaucrat& other);
#endif
