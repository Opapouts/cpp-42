/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 19:54:07 by opapouts          #+#    #+#             */
/*   Updated: 2026/04/18 19:54:08 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"
class	PhoneBook {

public:
	PhoneBook(void);
	~PhoneBook(void);
	void	eofHandling(void) const;
	void	addContact(void);
	void	searchContact(void) const;

private:
	Contact	_contacts[8];
	int	_totalContacts;
	int	_oldestContact;
	std::string	_getInput(std::string prompt) const;
	std::string	_getNumber(std::string prompt) const;
	void	_displayOverview(int i) const;
	void	_showContacts(void) const;
	int	_verifyIndex(void) const;
};
#endif
