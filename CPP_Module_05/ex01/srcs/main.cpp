/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:14:29 by maparigi          #+#    #+#             */
/*   Updated: 2023/07/08 17:48:47 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

//int	main( void ) {
//	Bureaucrat	bu("Bureaucrat", 1);
//	Bureaucrat	bu2("Bureaucrat2", 150);
//	Bureaucrat	bu3("Bureaucrat3", 151);
//	Bureaucrat	*bu4 = new Bureaucrat("Bureaucrat4", 22);
	
//	try {
//		bu.incrementGrade();
//	}catch (std::exception &e) {
//		std::cout << e.what() << std::endl;
//	}
//	try {
//		bu2.decrementGrade();
//	}catch (std::exception &e) {
//		std::cout << e.what() << std::endl;
//	}
//	try {
//		std::cout << bu4;
//		bu4->decrementGrade();
//	}catch (std::exception &e) {
//		std::cout << e.what() << std::endl;
//	}
//	delete (bu4);
//}

int main(void)
{
	{
		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		Bureaucrat *a = new Bureaucrat();
		Form	*f = new Form();
		std::cout << std::endl;

		std::cout << "\033[34mTesting\033[0m" << std::endl;
		std::cout << *a;

		try // in my opinion would make more sense if the try-catch blocks would have been inside the class itself already
		{
		a->incrementGrade();
		}
		catch(Bureaucrat::GradeTooHighException &e) // the try-catch blocks inside the class are commented out but fully functional
		{
			std::cerr << "\033[33mIncrementing grade of " << a->getName() <<
			" failed: " << e.what() << "\033[0m" << std::endl;
		}

		std::cout << *a;

		try
		{
		a->decrementGrade();
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << "\033[33mDecrementing grade of " << a->getName() <<
			" failed: " << e.what() << "\033[0m" << std::endl;
		}

		std::cout << *a;

		try
		{
		a->decrementGrade();
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << "\033[33mDecrementing grade of " << a->getName() <<
			" failed: " << e.what() << "\033[0m" << std::endl;
		}

		std::cout << *a;
		std::cout << std::endl;

		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
		delete a;
		delete f;
		std::cout << std::endl;
	}
	std::cout << "-------------------------------------------------------" << std::endl;
	{
		std::cout << std::endl;
		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		Bureaucrat *a = new Bureaucrat(1);
		std::cout << std::endl;
		std::cout << "\033[34mTesting\033[0m" << std::endl;
		std::cout << *a;

		try
		{
		a->decrementGrade();
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << "\033[33mDecrementing grade of " << a->getName() <<
			" failed: " << e.what() << "\033[0m" << std::endl;
		}

		std::cout << *a;

		try
		{
		a->incrementGrade();
		}
		catch(Bureaucrat::GradeTooHighException &e)
		{
			std::cerr << "\033[33mIncrementing grade of " << a->getName() <<
			" failed: " << e.what() << "\033[0m" << std::endl;
		}

		std::cout << *a;

		try
		{
		a->incrementGrade();
		}
		catch(Bureaucrat::GradeTooHighException &e)
		{
			std::cerr << "\033[33mIncrementing grade of " << a->getName() <<
			" failed: " << e.what() << "\033[0m" << std::endl;
		}

		std::cout << *a;
		std::cout << std::endl;

		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
		delete a;
		std::cout << std::endl;
	}
	std::cout << "-------------------------------------------------------" << std::endl;
	{
		std::cout << std::endl;
		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		Bureaucrat *a = NULL;

		try
		{
			a = new Bureaucrat(0);
		}
		catch(Bureaucrat::GradeTooHighException &e)
		{
			std::cerr << "\033[33mConstructing default failed: " <<
			e.what() << "\033[0m" << std::endl;
		}

		if (a != NULL)
		{
			std::cout << std::endl;

			std::cout << "\033[34mDeconstructing b\033[0m" << std::endl;
			delete a;
		}

		std::cout << std::endl;
	}
	std::cout << "-------------------------------------------------------" << std::endl;
	{
		std::cout << std::endl;
		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		Bureaucrat *a = NULL;

		try
		{
			a = new Bureaucrat(160);
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << "\033[33mConstructing default failed: " <<
			e.what() << "\033[0m" << std::endl;
		}

		if (a != NULL)
		{
			std::cout << std::endl;
			std::cout << "\033[34mDeconstructing b\033[0m" << std::endl;
			delete a;
		}
		std::cout << std::endl;
	}
	std::cout << "-------------------------------------------------------" << std::endl;
	{
		std::cout << std::endl;
		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		Bureaucrat *a = new Bureaucrat("Peter", 120);
		std::cout << std::endl;

		std::cout << "\033[34mTesting a\033[0m" << std::endl;
		std::cout << *a;

		a->decrementGrade();

		std::cout << *a;
		std::cout << std::endl;

		std::cout << "\033[34mConstructing b\033[0m" << std::endl;
		Bureaucrat *b = new Bureaucrat(*a);
		std::cout << std::endl;

		std::cout << "\033[34mDeconstructing a\033[0m" << std::endl;
		delete a;
		std::cout << std::endl;

		std::cout << "\033[34mTesting b\033[0m" << std::endl;
		std::cout << *b;
		b->decrementGrade();
		std::cout << *b;
		std::cout << std::endl;

		std::cout << "\033[34mDeconstructing b\033[0m" << std::endl;
		delete b;

		std::cout << std::endl;
	}
}