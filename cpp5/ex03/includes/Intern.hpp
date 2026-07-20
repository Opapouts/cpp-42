/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 19:17:51 by opapouts          #+#    #+#             */
/*   Updated: 2026/07/18 19:17:53 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP
#include <string>

class	AForm;

class	Intern {

	public	:
		Intern(void);
		Intern(const Intern& other);
		~Intern(void);
		Intern& operator = (const Intern& other);
		AForm*	makeForm(const std::string& name, const std::string& target);
	private	:
		AForm*	makeShrubbery(const std::string& target) const;
		AForm*	makeRobotomy(const std::string& target) const;
		AForm*	makePresidential(const std::string& target) const;

};
#endif
