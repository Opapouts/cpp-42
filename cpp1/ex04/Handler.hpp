/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Handler.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 20:48:12 by opapouts          #+#    #+#             */
/*   Updated: 2026/04/22 20:48:13 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLER_HPP
# define HANDLER_HPP
#include <string>
#include <fstream>

class	Handler	{

	public :
		Handler(std::string filename, std::string s1, std::string s2);
		~Handler(void);
		void	replaceFile(void);

	private :
		bool	checkConditions(void);
		std::string _filename;
		std::string	_s1;
		std::string	_s2;
		std::ifstream	_inFile;
		std::ofstream	_outFile;
};

#endif
