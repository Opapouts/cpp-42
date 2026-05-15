/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 19:53:54 by opapouts          #+#    #+#             */
/*   Updated: 2026/04/18 19:55:07 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <string>

class	Contact {

public:
	Contact(void);
	~Contact(void);
	void	setFirstName(std::string firstName);
	void	setLastName(std::string lastName);
	void	setNickname(std::string nickname);
	void	setNumber(std::string number);
	void	setSecret(std::string secret);

	std::string	getFirstName(void) const;
	std::string	getLastName(void) const;
	std::string	getNickname(void) const;
	std::string	getNumber(void) const;
	std::string	getSecret(void) const;
private:
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickname;
	std::string	_number;
	std::string	_secret;
};

#endif
