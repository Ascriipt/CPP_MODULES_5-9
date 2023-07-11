/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:14:29 by maparigi          #+#    #+#             */
/*   Updated: 2023/07/11 17:31:49 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	ShrubberyCreationForm s("Shrubbery");
	RobotomyRequestForm r("Robotomy");
	PresidentialPardonForm p("Presidential");
	Bureaucrat b("bureaucrat", 50);

	try
	{
		b.executeForm(s);
		b.executeForm(r);
		b.executeForm(p);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "---------------------" << std::endl;
		try
	{
		s.beSigned(b);
		r.beSigned(b);
		p.beSigned(b);
		b.executeForm(s);
		b.executeForm(r);
		b.executeForm(p);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "---------------------" << std::endl;
		try
	{
		s.beSigned(b);
		std::cout << "+++++++++++" << std::endl;
		b.executeForm(s);
		b.executeForm(r);
		b.executeForm(p);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}