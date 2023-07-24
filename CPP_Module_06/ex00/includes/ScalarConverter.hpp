/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 19:37:42 by maparigi          #+#    #+#             */
/*   Updated: 2023/07/24 18:22:08 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <string>
# include <cerrno>
# include <cstdlib>
# include <sstream>
# include <iostream>

class ScalarConverter {
	private:
		ScalarConverter();
		ScalarConverter( const ScalarConverter &old );
		~ScalarConverter();

		ScalarConverter	&	operator=( const ScalarConverter &old );
	public:
		static void	resType( const std::string &input );
};