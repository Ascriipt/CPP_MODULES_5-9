/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 17:34:50 by maparigi          #+#    #+#             */
/*   Updated: 2023/07/08 18:01:28 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _Name("default_form"), _signReq(150), _execReq(150), _isSigned(0) {
	return;
}

Form::Form( std::string Name, int signReq, int execReq,  bool isSigned ) : _Name(Name), _signReq(signReq), _execReq(execReq), _isSigned(isSigned) {
	return;
}

Form::~Form() {
	return;
}

std::string	const Form::getName() const {
	return	_Name;
}

int	Form::getSignReq() const {
	return	_signReq;
}

int	Form::getExecReq() const {
	return	_execReq;
}

bool	Form::getStatus() const {
	return	_isSigned;
}