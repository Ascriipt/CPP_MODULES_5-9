/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 08:53:48 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/12 20:43:15 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(const int ac, const char *input) {
	if ( ac < 2 )
		throw MissingArgument();
	if ( ac > 2 )
		throw TooManyArgument();
	_input = static_cast< std::string >( input );
	if ( _input.empty() )
		throw	Empty();
	if ( PRINT_DEBUG ) {
		std::cout << "an instance of " << PURPLE << "RPN " << NC
		<< "has been " << GREEN << "created" << NC << "." << std::endl;
	}
	displayResult();
}

static bool isOperator(const std::string &token) {
	return token.size() == 1 && token.find_first_of(OPERATORS) != std::string::npos;
}

static int addition(const int nb1, const int nb2) {

	if (nb1 > INT_MAX - nb2)
		throw RPN::Overflow();
	return (nb1 + nb2);
}

static int substraction(const int nb1, const int nb2) {
	return (nb1 - nb2);
}

static int multiplication(const int nb1, const int nb2) {

	if (nb1 != 0 && nb2 != 0) {
		if (nb1 > INT_MAX / nb2)
			throw RPN::Overflow();
	}
	return (nb1 * nb2);
}

static int division(const int nb1, const int nb2) {
	if (nb2 == 0)
		throw RPN::DivisionByZero();
	return (nb1 / nb2);
}

static int performOperation(const int nb1, const int nb2, const std::string &op) {

	static int (*operations[])(const int, const int) = {
		addition,
		substraction,
		multiplication,
		division
	};
	static std::string operators = OPERATORS;
	return operations[operators.find(op)](nb1, nb2);
}

static int getOperand(const std::string &op) {
	if (op.size() == 1 && isdigit(op[0]))
		return op[0] - ASCII_NB_SHIFT;
	throw RPN::UnexpectedToken();
}


void	RPN::displayResult() {

	std::stack<int> operands;
	processStack( operands );
	if ( operands.size() > 1 )
		throw TooManyOperands();
	std::cout << operands.top() << std::endl;
}

void RPN::processStack( std::stack<int> &operands ) const {

	std::istringstream	iss( _input );
	std::string			token;
	while (iss >> token) {

		if (isOperator(token)) {
			if (operands.size() < 2) {
				throw InsufficientOperands();
			}
			const int operand1 = operands.top();
			operands.pop();
			const int	operand2 = operands.top();
			operands.pop();
			const int result = performOperation(operand2, operand1, token);
			operands.push(result);
		} else {
			const int operand = getOperand(token);
			operands.push(operand);
		}
	}
}

RPN::~RPN() {
	if (PRINT_DEBUG) {
		std::cout << "RPN has been " <<
		RED << "destroyed" << NC << std::endl;
	}
}