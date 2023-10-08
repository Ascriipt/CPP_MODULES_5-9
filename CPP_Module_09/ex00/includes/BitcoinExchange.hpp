/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uniix <uniix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:04:38 by uniix             #+#    #+#             */
/*   Updated: 2023/10/09 00:31:33 by uniix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <map>
#include <cmath>
#include <string>
#include <limits>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

class BitcoinExchange {
	private:
		std::multimap<std::string, std::string> _data;
		std::multimap<std::string, std::string > _input;

		BitcoinExchange();
		BitcoinExchange( const BitcoinExchange & old );
		BitcoinExchange & operator=( const BitcoinExchange & old );

		bool	isValidNumber( float n );
		bool	isValidDateFormat( const std::string & date );


		void	Init();
		void	matchData( const std::multimap<std::string, std::string>::iterator & Iter );
		void	checkFormat( const std::multimap<std::string, std::string>::iterator & one );
		void	matchOneData( const std::multimap<std::string, std::string>::iterator & one );

	public:
		BitcoinExchange( std::string input );
		~BitcoinExchange();

		class BadFormat : std::exception {
			public:
				virtual const char* what() const throw() {
					return	("Format Error\n");
				};
		};
		void	printData();
};

// grave c'est exactement mon wallet en plus

// putain batard tu fais le cpp 09, si t'etais en vrai chad tu ferais ft_containers (have fun askip le 09 est un peu chiant mais ca va)

// jsuis un maxi chad je l'ai deja fait avec mes doigts dans le cul en fete 