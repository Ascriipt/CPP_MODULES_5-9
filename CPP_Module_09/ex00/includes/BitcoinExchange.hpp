/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uniix <uniix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:04:38 by uniix             #+#    #+#             */
/*   Updated: 2023/10/06 14:45:40 by uniix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <map>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

class BitcoinExchange {
	private:
		std::map<std::string, std::string> _data;

		BitcoinExchange( const BitcoinExchange &old );
		BitcoinExchange & operator=( const BitcoinExchange & old );
	public:
		BitcoinExchange();
		~BitcoinExchange();
		
		class BadFormat : std::exception {
			public:
				virtual const char* what() const throw() {
					return	("Format Error\n");
				};
		};
		void	printCSVStored();
};

// grave c'est exactement mon wallet en plus