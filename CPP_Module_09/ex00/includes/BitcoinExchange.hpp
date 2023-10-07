/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uniix <uniix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:04:38 by uniix             #+#    #+#             */
/*   Updated: 2023/10/07 18:40:01 by uniix            ###   ########.fr       */
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
		std::map<std::string, std::string > _input;

		BitcoinExchange();
		BitcoinExchange( const BitcoinExchange & old );
		BitcoinExchange & operator=( const BitcoinExchange & old );
	public:
		BitcoinExchange( std::string input );
		~BitcoinExchange();

		class BadFormat : std::exception {
			public:
				virtual const char* what() const throw() {
					return	("Format Error\n");
				};
		};
		void	Init();
		void	printData();
		void	matchData( std::string );
};

// grave c'est exactement mon wallet en plus

// putain batard tu fais le cpp 09, si t'etais en vrai chad tu ferais ft_containers (have fun askip le 09 est un peu chiant mais ca va)