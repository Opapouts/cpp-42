/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 19:16:54 by opapouts          #+#    #+#             */
/*   Updated: 2026/07/18 19:16:55 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include "AForm.hpp"

class	Bureaucrat;

class	ShrubberyCreationForm : public AForm {
	
	public	:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm(void);
		ShrubberyCreationForm& operator = (const ShrubberyCreationForm& other);
		std::string const&	getTarget(void) const;
		void	executeAction(void) const;
	
	private	:
		std::string	_target;
		void	drawASCIITree(std::ofstream& file) const;
};

#endif
