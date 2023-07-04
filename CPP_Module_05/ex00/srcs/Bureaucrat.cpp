/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 19:01:32 by maparigi          #+#    #+#             */
/*   Updated: 2023/06/22 20:18:22 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat& Bureaucrat::operator=( const Bureaucrat &old ) {
	std::cout << "Bureaucrat Assignment operator called for Bureaucrat." << std::endl;
	if (this != &old) {
		_name = old.getName();
		_grade = old.getGrade();
	}
	return *this;
}

Bureaucrat::Bureaucrat() : _name("Bureaucrat"), _grade(150) {
	std::cout << "Bureaucrat Default Constructor called" << std::endl;
}

Bureaucrat::Bureaucrat( std::string name, int grade ) : _name(name), _grade(grade) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	std::cout << "Bureaucrat Constructor called for " << _name << '.' << std::endl;
}

Bureaucrat::Bureaucrat( const Bureaucrat &old ) {
	std::cout << "Bureaucrat Copy Constructor called." << std::endl;
	(*this) = old;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat Default Destructor called for " << _name << '.' << std::endl;
}

Bureaucrat::GradeTooHighException::GradeTooHighException() {
	std::cout << "GradeToohigh exception thrown." << std::endl;
}

Bureaucrat::GradeTooLowException::GradeTooLowException() {
	std::cout << "GradeToolow exception thrown." << std::endl;
}
