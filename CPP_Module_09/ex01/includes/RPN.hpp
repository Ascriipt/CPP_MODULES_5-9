/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:50:21 by maparigi          #+#    #+#             */
/*   Updated: 2023/10/13 14:50:23 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>
#include <string>
#include <cstdlib>
#include <climits>
#include <sstream>
#include <iostream>

#define OVERFLOW_ERR_M				"int overflow"
#define MISSING_ARG_ERR_M			"missing argument"
#define TOO_MANY_ARG_ERR_M			"too many arguments"
#define	EMPTY_STRING_ERR_M			"the provided string is empty."
#define UNEXPECTED_TOK_ERR_M		"unexpected token"
#define DIVISION_BY_ZERO_ERR_M		"division by zero"
#define TOO_MANY_OPERANDS_ERR_M		"too many operands"
#define INSUFFICIENT_OPERANDS_ERR_M	"insufficient operands"

#define NC		"\033[0m"
#define RED		"\033[0;31m"
#define GREEN	"\033[0;32m"
#define PURPLE	"\033[0;35m" 

#ifndef PRINT_DEBUG
# define PRINT_DEBUG false
#endif

class RPN {

	private:
		std::string _input;
		RPN();

		RPN( const RPN &other );
		RPN &operator=( const RPN &other );

		void processStack( std::stack<int> &operands ) const;

	public:
		RPN(const int ac, const char *input);
		~RPN();

		void displayResult();

			class MissingArgument: public std::exception {
				public:
					const char *what() const throw() {
						return	MISSING_ARG_ERR_M;
					};
			};
			class TooManyArgument: public std::exception {
				public:
					const char *what() const throw() {
						return	TOO_MANY_ARG_ERR_M;
					};
			};
			class InsufficientOperands: public std::exception {
				public:
					const char *what() const throw() {
						return	INSUFFICIENT_OPERANDS_ERR_M;
					};
			};
			class TooManyOperands: public std::exception {
				public:
					const char *what() const throw() {
						return	TOO_MANY_OPERANDS_ERR_M;
					};
			};
			class UnexpectedToken: public std::exception {
				public:
					const char *what() const throw() {
						return	UNEXPECTED_TOK_ERR_M;
					};
			};
			class DivisionByZero: public std::exception {
				public:
					const char *what() const throw() {
						return	DIVISION_BY_ZERO_ERR_M;
					};
			};
			class Overflow: public std::exception {
				public:
					const char *what() const throw() {
						return	OVERFLOW_ERR_M;
					};
			};
			class Empty: public std::exception {
				public:
					const char * what() const throw() {
						return	EMPTY_STRING_ERR_M;
					};
			};
};