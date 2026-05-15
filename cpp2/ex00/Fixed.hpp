/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 17:30:28 by opapouts          #+#    #+#             */
/*   Updated: 2026/04/27 17:30:50 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class	Fixed {

	public :
		Fixed(void);
		Fixed(const Fixed& other);
		~Fixed(void);
		Fixed& operator = (const Fixed& other);
		int	getRawBits(void) const;
		void	setRawBits(int const raw);
	private :
		int	_value;
		static const int _bits = 8;
};

#endif
