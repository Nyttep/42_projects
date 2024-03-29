/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:30:25 by pdubois           #+#    #+#             */
/*   Updated: 2022/10/31 16:12:14 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class	Fixed
{
	private:
		int	_value;
		static const int	_binary_point;
	public:
		Fixed(void);
		Fixed(const Fixed& to_copy);
		~Fixed(void);
		int	getRawBits(void) const;
		void	setRawBits(int const raw);
		Fixed&	operator=(const Fixed& to_copy);
};

#endif