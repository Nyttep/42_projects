/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 08:00:48 by pdubois           #+#    #+#             */
/*   Updated: 2023/07/25 08:00:48 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int argc, char** argv)
{
	RPN	calculator;
	if (argc != 2)
	{
		std::cerr << "Error: program should be executed like this: ./RPN <RPN expression>";
		return (1);
	}
	int		result = 0;
	std::string	expression = argv[1];
	if (calculator.calculate(expression, result) == 1)
		return (1);
	std::cout << result << std::endl;
	return (0);
}