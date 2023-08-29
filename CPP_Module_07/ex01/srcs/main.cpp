/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 21:39:07 by maparigi          #+#    #+#             */
/*   Updated: 2023/07/26 21:40:59 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "Iter.hpp"

int	main(void)
{
	int			arrayInt[5] = {0, 1, 2, 3, 4};
	std::string	arrayStr[5] = {"niq", "euhhhh", "mouk", "sashimi", "greGori"};
	const char	*arrayStrC[5] = {"ab", "ac", "ad", "ae", "af"};
	char		arrayChar[5] = {'r', 'e', 't', 's', 'u'};

	Iter(arrayInt, 5, printValue);
	std::cout << std::endl;
	Iter(arrayInt, 2, printValue);
	std::cout << std::endl;

	Iter(arrayStr, 5, printValue);
	std::cout << std::endl;

	Iter(arrayStrC, 5, printValue);
	std::cout << std::endl;

	Iter(arrayChar, 5, printValue);
	std::cout << std::endl;

	return (0);
}