/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uniix <uniix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 19:51:21 by uniix             #+#    #+#             */
/*   Updated: 2023/10/07 18:45:16 by uniix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void	BitcoinExchange::Init() {
	std::ifstream	data("data.csv");
	std::string		mapbuff[2];
	std::string		buff;

	if (!data.is_open()) {
		std::cerr << "data.csv could not open." << std::endl;
		return	;
	}
	
	while (std::getline(data, buff)) {
		std::stringstream	format;
		std::replace(buff.begin(), buff.end(), ',', ' ');
		format << buff;
		format >> mapbuff[0];
		format >> mapbuff[1];
		_data[mapbuff[0]] = mapbuff[1];
		// std::cout << mapbuff[0] << " () " << mapbuff[1] << std::endl;
	};
	data.close();
};

void	BitcoinExchange::printData() {
	std::map<std::string, std::string>::iterator	iter;

	for (iter = _data.begin(); iter != _data.end(); iter++) {
		std::cout << iter->first << " | " << iter->second << std::endl;
	}
};

BitcoinExchange::BitcoinExchange( std::string input ) {
	std::ifstream	data(input.c_str());
	std::string		mapbuff[2];
	std::string		buff;

	Init();
	if (!data.is_open()) {
		std::cerr << input << " could not open." << std::endl;
		return	;
	}

	while (std::getline(data, buff)) {
		std::stringstream	format;
		std::replace(buff.begin(), buff.end(), '|', ' ');
		format << buff;
		format >> mapbuff[0];
		format >> mapbuff[1];
		_input[mapbuff[0]] = mapbuff[1];
		// std::cout << mapbuff[0] << " 0 " << mapbuff[1] << std::endl;
	};
	data.close();
};

BitcoinExchange::~BitcoinExchange() {};

// void	BitcoinExchange::matchData() {};