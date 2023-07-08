/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 17:16:20 by maparigi          #+#    #+#             */
/*   Updated: 2023/07/08 17:56:10 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class Form {
	private:
		std::string const	_Name;
		const int			_signReq;
		const int			_execReq; 
		bool				_isSigned;
	public:
		Form();
		Form( std::string Name, int signReq, int execReq, bool isSigned );
		Form( const Form &old );
		~Form();
	
		std::string const	getName() const;
		bool				getStatus() const;
		int			getSignReq() const;
		int			getExecReq() const;
};