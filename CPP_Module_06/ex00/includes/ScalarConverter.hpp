/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 19:37:42 by maparigi          #+#    #+#             */
/*   Updated: 2023/07/24 18:42:53 by emaugale         ###   ########.fr       */
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
		int _classInt;
		char _classChar;
		float _classFloat;
		double _classDouble;

		ScalarConverter();
		ScalarConverter( const ScalarConverter &old );
		~ScalarConverter();

		ScalarConverter	&	operator=( const ScalarConverter &old );
	public:
		static void	converter( const std::string &input );
		static void convertFromInt( int x );
		static void convertFromChar( char c );
		static void convertFromFloat( float f );
		static void convertFromDouble( double d );
};