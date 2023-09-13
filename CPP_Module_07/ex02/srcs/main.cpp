/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 21:39:07 by maparigi          #+#    #+#             */
/*   Updated: 2023/09/13 12:22:45 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

#include <string>
#include <iostream>

int	main(void)
{
	char *	a = new char();
	Array< int > numbers(12);
	Array< char > cahr(11);
	Array< std::string > strs;
	Array< int >	suce(numbers);
	std::cout << *a << std::endl;
	std::cout << cahr[5] << std::endl;
	std::cout << numbers[11] << std::endl;
	try {
		std::cout << numbers[12] << std::endl;
	} catch ( std::exception &e ) {
		std::cout << "Error : " << e.what() << std::endl;
	}
	delete a;
	return (0);
}