/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 19:37:42 by maparigi          #+#    #+#             */
/*   Updated: 2023/07/20 15:25:00 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class ScalarConverter {
	private:
		ScalarConverter() = delete;
		ScalarConverter( const ScalarConverter &old ) = delete;
		~ScalarConverter() = delete;

		ScalarConverter	&	operator=( const ScalarConverter &old ) = delete;
	public:
		static int	resType();
};