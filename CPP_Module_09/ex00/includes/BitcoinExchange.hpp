/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:12:58 by maparigi          #+#    #+#             */
/*   Updated: 2023/10/14 23:39:41 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <map>
#include <string>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

#define SEPARATORS			"|"
#define DB_SEPARATORS		","

#define NC		"\033[0m"
#define RED		"\033[0;31m"
#define GREEN	"\033[0;32m"
#define PURPLE	"\033[0;35m"

#define NEGATIVE_ERR_M			"not a positive number."
#define TOO_LARGE_ERR_M			"too large a number."
#define BAD_INPUT_ERR_M			"bad input => "
#define	INVALID_DB_ERR_M		"invalid database"
#define WRONG_DATE_ERR_M		"no data for this date."
#define INVALID_DATE_ERR_M		"bad date format => "
#define COULD_NOT_OPEN_ERR_M	"could not open file."
#define INV_ARG_NUMBER_ERR_M	"invalid number of arguments."

#ifndef PRINT_DEBUG
# define PRINT_DEBUG false
#endif

class BitcoinExchange {

	private:
		const char						*_fileName;
		std::ifstream					_file;
		std::ifstream					_database;
		std::map<std::string, float>	_dataMap;

		void initDataBase();
		void fillDatabase();
		void execute( std::ifstream &file );
		void initFile( const char *fileName );
		void fillDate( const std::string line );
		void exchange( const std::string line ) const;
		void checkDateFormat( const std::string & date ) const;
		void checkValueRequirements( const float value ) const;

		std::string findClosestDate(const std::map<std::string, float>& myMap, const std::string& input) const;

		BitcoinExchange();
		BitcoinExchange( const BitcoinExchange &bigcoinExchange );
		BitcoinExchange &operator=( const BitcoinExchange &bigcoinExchange );

	public:
		BitcoinExchange( const int ac, const char *fileName );
		~BitcoinExchange();

		void displayConversion();
		class InvalidArgumentNumber: public std::exception {
			public:
				const char *what() const throw() {
					return	INV_ARG_NUMBER_ERR_M;
				};
		};
		class InvalidFile: public std::exception {
			public:
				const char *what() const throw() {
					return	COULD_NOT_OPEN_ERR_M;
				};
		};
		class NegativeValue: public std::exception {
			public:
				const char *what() const throw() {
					return	NEGATIVE_ERR_M;
				};
		};
		class TooLargeValue: public std::exception {
			public:
				const char *what() const throw() {
					return	TOO_LARGE_ERR_M;
				};
		};
		class TooEarlyDate: public std::exception {
			public:
				const char *what() const throw() {
					return	WRONG_DATE_ERR_M;
				};
		};
		class BadInput: public std::exception {
			private:
				std::string _errorMessage;
			public:
				BadInput( const std::string &message );
				const char *what() const throw();
				~BadInput() throw();
		};
		class InvalidDateFormat: public std::exception {
			private:
				std::string _errorMessage;
			public:
				InvalidDateFormat( const std::string &message );
				const char *what() const throw();
				~InvalidDateFormat() throw();
		};
};