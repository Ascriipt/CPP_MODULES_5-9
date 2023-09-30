/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uniix <uniix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 19:28:14 by uniix             #+#    #+#             */
/*   Updated: 2023/09/27 19:49:09 by uniix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>

int main( void )
{
	std::vector<int> test;
	test.push_back(0);
	test.push_back(2);
	test.push_back(1);
	test.push_back(4);
	test.push_back(2147483647);


	try
	{
		(void)easyfind(test, 21);
	}
	catch (const std::exception& e)
	{
		std::cout << "number not found" << std::endl;
	}
	std::cout << *easyfind(test, 4) << std::endl << *easyfind(test, 2) << std::endl;
	std::cout << *easyfind(test, 1) << std::endl << *easyfind(test, 2147483647) << std::endl;

	std::vector<float>	test2;
	try
	{
		std::cout << *easyfind(test2, 6) << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "empty vector" << std::endl;
	}
}