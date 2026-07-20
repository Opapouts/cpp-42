/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 19:16:49 by opapouts          #+#    #+#             */
/*   Updated: 2026/07/18 19:16:51 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include "AForm.hpp"

class	Bureaucrat;

class	RobotomyRequestForm : public AForm {

	public	:
		RobotomyRequestForm(void);
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		~RobotomyRequestForm(void);
		RobotomyRequestForm& operator = (const RobotomyRequestForm& other);
		std::string const&	getTarget(void) const;
		void	executeAction(void) const;

	private	:
		std::string	_target;
		bool		robotomize(void) const;

};
#endif
