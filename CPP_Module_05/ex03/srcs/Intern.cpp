/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 15:28:43 by maparigi          #+#    #+#             */
/*   Updated: 2023/07/14 16:46:56 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern( const Intern &old ) {
	*this = old;
}

Intern	&Intern::operator=( const Intern &old ) {
	(void)old;
	return	*this;
}

Intern::~Intern() {}

static Form	*makePresi( std::string target ) {
	return	new PresidentialPardonForm( target );
}

static Form	*makeShrub( std::string target ) {
	return	new ShrubberyCreationForm( target );
}

static Form		*makeRobot( std::string target ) {
	return	new RobotomyRequestForm( target );
}

Form	*Intern::makeForm( std::string fname, std::string target ) {
	std::string	formNames[] = {"RobotomyRequestForm", "PresidentialPardonForm", "ShrubberyCreationForm"};
	Form		*(*formFunc[])(const std::string target) = {&makeRobot, &makePresi, &makeShrub};

	for (int i = 0; i < 3; i++) {
		if (fname == formNames[i]) {
			std::cout << "\033[36mIntern creates " << fname << "\033[0m" << std::endl;
			return	formFunc[i](target);
		}
	}

	std::cout << "\033[36mIntern was unable to create " << fname << "\033[0m" << std::endl;
	return NULL;
}