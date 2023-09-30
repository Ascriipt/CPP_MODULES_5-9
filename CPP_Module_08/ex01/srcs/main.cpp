/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uniix <uniix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 19:28:14 by uniix             #+#    #+#             */
/*   Updated: 2023/09/30 22:28:32 by uniix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"
#include <iostream>
#include <vector>

int main( void ) {
	span a(12);

	a.addNumber(6);
	a.addNumber(3);
	a.addNumber(17);
	a.addNumber(9);
	a.addNumber(11);

	std::cout << a.shortestSpan() << std::endl;
	std::cout << a.longestSpan() << std::endl;

	return (0);
}