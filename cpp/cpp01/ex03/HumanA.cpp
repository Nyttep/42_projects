/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:59:47 by pdubois           #+#    #+#             */
/*   Updated: 2022/10/24 18:55:10 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string myName, Weapon newWeapon) : myWeapon(newWeapon), name(myName)
{
	std::cout << "construct A " << myWeapon.getType() << std::endl;
}

HumanA::~HumanA(void)
{
}

void	HumanA::attack(void)
{
	std::cout << this->name << " attacks with their " << this->myWeapon.getType() << std::endl;
}
