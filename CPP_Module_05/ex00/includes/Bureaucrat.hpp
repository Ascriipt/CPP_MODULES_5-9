/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:58:42 by maparigi          #+#    #+#             */
/*   Updated: 2023/06/22 20:14:38 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat
{
public:

	Bureaucrat();
	Bureaucrat( std::string type, int grade );
	Bureaucrat( const Bureaucrat &old );
	~Bureaucrat();

	Bureaucrat&	operator=( const Bureaucrat &old );
private:

	std::string const	_name;
	int					_grade;

};

#endif