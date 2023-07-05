/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:14:29 by maparigi          #+#    #+#             */
/*   Updated: 2023/07/05 13:28:40 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main( void ) {
	Bureaucrat	bu("Bureaucrat", 1);
	Bureaucrat	bu2("Bureaucrat2", 150);
	Bureaucrat	bu3("Bureaucrat3", 151);
	Bureaucrat	bu4("Bureaucrat4", 22);
	
	try {
		bu.incrementGrade();
	}catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		bu2.decrementGrade();
	}catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		bu4.decrementGrade();
	}catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}