/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:56:59 by maparigi          #+#    #+#             */
/*   Updated: 2023/07/11 16:55:25 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Form.hpp"

class RobotomyRequestForm : public Form {
	private:
		const std::string	_target;

		RobotomyRequestForm();
	public:
		RobotomyRequestForm( std::string target );
		RobotomyRequestForm( const RobotomyRequestForm &old );
		~RobotomyRequestForm();
		
		RobotomyRequestForm&	operator=( const RobotomyRequestForm &old );

		void	execute( Bureaucrat const & executor ) const;
};