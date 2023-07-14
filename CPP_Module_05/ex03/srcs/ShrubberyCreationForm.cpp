/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:18:24 by maparigi          #+#    #+#             */
/*   Updated: 2023/07/11 16:56:27 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) : Form("ShrubberyCreationForm", 145, 137, 0), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm &old ) : Form(old), _target(old._target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=( const ShrubberyCreationForm &old ) {
    (void)old;
    return	*this;
}

void	ShrubberyCreationForm::execute( Bureaucrat const & executor ) const {
    if ( getStatus() == 0 )
		throw	notSignedException();
    if ( executor.getGrade() > getExecReq() )
		throw	GradeTooLowException();
    std::string		fname = _target + "_shrubbery";
    std::ofstream	Shrubfile( fname.c_str() );
    if (Shrubfile.is_open()) {
		Shrubfile << "                      ___" << std::endl;
		Shrubfile << "                _,-'\"\"   \"\"\"\"`--." << std::endl;
		Shrubfile << "             ,-'          __,,-- \\" << std::endl;
		Shrubfile << "           ,\'    __,--\"\"\"\"dF      )" << std::endl;
		Shrubfile << "          /   .-\"Hb_,--\"\"dF      /" << std::endl;
		Shrubfile << "        ,\'       _Hb ___dF\"-._,-'" << std::endl;
		Shrubfile << "      ,'      _,-\"\"\"\"   \"\"--..__" << std::endl;
		Shrubfile << "     (     ,-'                  `." << std::endl;
		Shrubfile << "      `._,'     _   _             ;" << std::endl;
		Shrubfile << "       ,'     ,' `-'Hb-.___..._,-'" << std::endl;
		Shrubfile << "       \\    ,'\"Hb.-\'HH`-.dHF\"" << std::endl;
		Shrubfile << "        `--\'   \"Hb  HH  dF\"" << std::endl;
		Shrubfile << "                \"Hb HH dF" << std::endl;
		Shrubfile << "                 \"HbHHdF" << std::endl;
		Shrubfile << "                  |HHHF" << std::endl;
		Shrubfile << "                  |HHH|" << std::endl;
		Shrubfile << "                  |HHH|" << std::endl;
		Shrubfile << "                  |HHH|" << std::endl;
		Shrubfile << "                  |HHH|" << std::endl;
		Shrubfile << "                  dHHHb" << std::endl;
		Shrubfile << "                .dFd|bHb.               o" << std::endl;
		Shrubfile << "      o       .dHFdH|HbTHb.          o /" << std::endl;
		Shrubfile << "\\  Y  |  \\__,dHHFdHH|HHhoHHb.         Y" << std::endl;
		Shrubfile << "##########################################" << std::endl;
		Shrubfile << "                      ___" << std::endl;
		Shrubfile << "                _,-'\"\"   \"\"\"\"`--." << std::endl;
		Shrubfile << "             ,-'          __,,-- \\" << std::endl;
		Shrubfile << "           ,\'    __,--\"\"\"\"dF      )" << std::endl;
		Shrubfile << "          /   .-\"Hb_,--\"\"dF      /" << std::endl;
		Shrubfile << "        ,\'       _Hb ___dF\"-._,-'" << std::endl;
		Shrubfile << "      ,'      _,-\"\"\"\"   \"\"--..__" << std::endl;
		Shrubfile << "     (     ,-'                  `." << std::endl;
		Shrubfile << "      `._,'     _   _             ;" << std::endl;
		Shrubfile << "       ,'     ,' `-'Hb-.___..._,-'" << std::endl;
		Shrubfile << "       \\    ,'\"Hb.-\'HH`-.dHF\"" << std::endl;
		Shrubfile << "        `--\'   \"Hb  HH  dF\"" << std::endl;
		Shrubfile << "                \"Hb HH dF" << std::endl;
		Shrubfile << "                 \"HbHHdF" << std::endl;
		Shrubfile << "                  |HHHF" << std::endl;
		Shrubfile << "                  |HHH|" << std::endl;
		Shrubfile << "                  |HHH|" << std::endl;
		Shrubfile << "                  |HHH|" << std::endl;
		Shrubfile << "                  |HHH|" << std::endl;
		Shrubfile << "                  dHHHb" << std::endl;
		Shrubfile << "                .dFd|bHb.               o" << std::endl;
		Shrubfile << "      o       .dHFdH|HbTHb.          o /" << std::endl;
		Shrubfile << "\\  Y  |  \\__,dHHFdHH|HHhoHHb.         Y" << std::endl;
		Shrubfile << "##########################################" << std::endl;
		Shrubfile.close();
    }
}
