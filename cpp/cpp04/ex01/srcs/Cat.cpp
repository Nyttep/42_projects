/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:14:42 by pdubois           #+#    #+#             */
/*   Updated: 2022/11/30 15:44:30 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"

// --------------- Constructors & Destructors --------------
Cat::Cat()
{
	std::cout << "Cat default constructor called" << std::endl;
	setType("Cat");
	_myBrain = new Brain();
}

Cat::Cat(const Cat& to_copy) : Animal()
{
	std::cout << "Cat copy constructor called" << std::endl;
	setType(to_copy.getType());
	_myBrain = new Brain;
	*_myBrain = *(to_copy.getBrain());
}

Cat::~Cat()
{
	std::cout << "Cat default destructor called" << std::endl;
	delete _myBrain;
}

// -------------- Operators overload --------------------
Cat&	Cat::operator=(const Cat& to_copy)
{
	this->_type = to_copy.getType();
	*(this->_myBrain) = *(to_copy.getBrain());
	return (*this);
}

//-------------- Setters & Getters --------------------
Brain*	Cat::getBrain() const
{
	return (_myBrain);
}

void	Cat::setBrain(Brain* newBrain)
{
	delete _myBrain;
	_myBrain = newBrain;
}

// ------------- Other Functions ----------------------
void	Cat::makeSound() const
{
	std::cout << "Meeeeoooowwww" << std::endl;
}