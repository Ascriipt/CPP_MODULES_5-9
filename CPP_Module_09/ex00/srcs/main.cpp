/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uniix <uniix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 19:28:14 by uniix             #+#    #+#             */
/*   Updated: 2023/10/09 00:17:09 by uniix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main( int ac, char **av ) {
	if ( ac != 2 ) {
		std::cout << "Error : couldn't open file" << std::endl;
		return	1;
	}
	BitcoinExchange a(av[1]);
	// a.printData();
}