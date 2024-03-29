/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:41:01 by pdubois           #+#    #+#             */
/*   Updated: 2022/11/22 17:55:51 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <stdexcept>
# include <iostream>

class	Bureaucrat
{
	private :
		const std::string	_name;
		int	_grade;
	public :
		Bureaucrat();
		Bureaucrat(const Bureaucrat& toCopy);
		Bureaucrat(const std::string newName, int newGrade);
		~Bureaucrat();
		Bureaucrat& operator=(const Bureaucrat& rhs);
		class	GradeTooHighException : public std::exception
		{
			public :
				virtual const char*	what() const throw();
		};
		class	GradeTooLowException : public std::exception
		{
			public :
				virtual const char*	what() const throw();
		};
		const std::string	getName() const;
		int	getGrade() const;
		void	setGrade(int newGrade);
		void	incrGrade();
		void	decrGrade();
		
};

std::ostream&	operator<<(std::ostream& o, const Bureaucrat& toDisplay);

#endif