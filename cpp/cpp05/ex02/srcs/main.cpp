/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:37:48 by pdubois           #+#    #+#             */
/*   Updated: 2022/11/26 17:11:12 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{
	Bureaucrat	A("Karen", 150);
	Bureaucrat	B("Paul", 1);
	AForm*	F = new ShrubberyCreationForm("garden");

	try
	{
		Bureaucrat	C("Fraud", 0);
	}
	catch (Bureaucrat::GradeTooHighException& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		A.decrGrade();
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	// B.incrGrade(); //Crash the program because exception not catched
	A.signForm(*F);
	B.signForm(*F);
	B.signForm(*F);
	A.executeForm(*F);
	B.executeForm(*F);
	delete F;
	F = new RobotomyRequestForm("Dr.Gero");
	B.executeForm(*F);
	delete F;
	F = new PresidentialPardonForm("Marvin");
	B.executeForm(*F);
	delete F;
	return (0);
}