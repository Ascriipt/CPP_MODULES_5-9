/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 17:16:20 by maparigi          #+#    #+#             */
/*   Updated: 2023/07/11 17:34:43 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "Bureaucrat.hpp"
# include <fstream>

class Bureaucrat;
class Form {
	private:
		std::string const	_Name;
		const int			_signReq;
		const int			_execReq; 
		bool				_isSigned;
	public:
		Form();
		Form( std::string Name, int signReq, int execReq, bool isSigned );
		Form( const Form &old );
		virtual	~Form();

		class notSignedException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class alreadySignedException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		virtual void		execute( const Bureaucrat & executor ) const = 0;

		std::string const	getName() const;
		bool				getStatus() const;
		int					getSignReq() const;
		int					getExecReq() const;

		void	beSigned( const Bureaucrat &signatory );
		
		void	setStatus( bool status );
};

std::ostream&	operator<<( std::ostream& o, const Form& curr );