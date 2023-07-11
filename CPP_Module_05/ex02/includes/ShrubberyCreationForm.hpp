/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:10:20 by maparigi          #+#    #+#             */
/*   Updated: 2023/07/11 17:27:23 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Form.hpp"

class ShrubberyCreationForm : public Form {
	private:
		const std::string	_target;
		
		ShrubberyCreationForm();
	public:
		ShrubberyCreationForm( std::string target );
		ShrubberyCreationForm( const ShrubberyCreationForm &old );
		~ShrubberyCreationForm();

		ShrubberyCreationForm	&operator=( const ShrubberyCreationForm &old );

		void		execute( Bureaucrat const & executor ) const;
};