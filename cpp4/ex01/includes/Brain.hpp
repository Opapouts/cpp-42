/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 19:53:09 by opapouts          #+#    #+#             */
/*   Updated: 2026/05/07 19:53:11 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <string>

class	Brain {

	public :
		Brain(void);
		Brain(const Brain& other);
		~Brain(void);
		Brain& operator = (const Brain& other);
		void	setIdeas(std::string idea);
		void	getIdeas(int index) const;
	private :
		std::string	_ideas[100];
};

#endif
