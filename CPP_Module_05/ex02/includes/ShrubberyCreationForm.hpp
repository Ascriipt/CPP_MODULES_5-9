/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:10:20 by maparigi          #+#    #+#             */
/*   Updated: 2023/07/10 19:47:27 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

		std::string	getTarget();

		void		execute( Bureaucrat const & executor );
};