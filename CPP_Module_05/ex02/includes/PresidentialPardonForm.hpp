/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:19:26 by maparigi          #+#    #+#             */
/*   Updated: 2023/07/11 16:33:31 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Form.hpp"

class PresidentialPardonForm : public Form {
	private:
		const std::string	_target;

		PresidentialPardonForm();
	public:
		PresidentialPardonForm( std::string target );
		PresidentialPardonForm( const PresidentialPardonForm &old );
		~PresidentialPardonForm();
		
		PresidentialPardonForm&	operator=( const PresidentialPardonForm &old );

		void	execute( const Bureaucrat & executor ) const;
};