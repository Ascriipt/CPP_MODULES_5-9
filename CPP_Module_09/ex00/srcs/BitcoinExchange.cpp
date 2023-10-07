/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uniix <uniix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 19:51:21 by uniix             #+#    #+#             */
/*   Updated: 2023/10/07 23:55:48 by uniix            ###   ########.fr       */
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
		_data.insert(std::make_pair(mapbuff[0], mapbuff[1]));
		// std::cout << mapbuff[0] << " () " << mapbuff[1] << std::endl;
	};
	data.close();
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
		// std::cout << "Read line: " << buff << std::endl;
		format << buff;
		format >> mapbuff[0];
		format >> mapbuff[1];
		_input.insert(std::make_pair(mapbuff[0], mapbuff[1]));
		// std::cout << mapbuff[0] << " " << mapbuff[1] << std::endl;
	};
	data.close();
	printData();
};

void	BitcoinExchange::printData() {
	std::multimap<std::string, std::string>::iterator	iter;

	for (iter = _input.begin(); iter != _input.end(); iter++) {
		std::cout << iter->first << " | " << iter->second << std::endl;
		isValidDateFormat(iter->first);
	}
};

bool	BitcoinExchange::isValidDateFormat(const std::string& date) {
    if (date.length() != 10)
        return false;

    if (date[4] != '-' || date[7] != '-')
        return false;

    std::string yearStr = date.substr(0, 4);
    std::string monthStr = date.substr(5, 2);
    std::string dayStr = date.substr(8, 2);

    int year, month, day;
    if (!(std::istringstream(yearStr) >> year) || 
        !(std::istringstream(monthStr) >> month) || 
        !(std::istringstream(dayStr) >> day)) {
        return false;
    }

    if (year >= 1 && month >= 1 && month <= 12 && day >= 1 && day <= 31) {
        if (month == 2) {
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
                return day <= 29;
            } else {
                return day <= 28;
            }
        } else if ((month == 4 || month == 6 || month == 9 || month == 11)) {
            return day <= 30;
        }
		std::cout << date << " is valid" << std::endl;
        return true;
    }
	std::cout << date << " is not valid" << std::endl;
    return false;
};

BitcoinExchange::~BitcoinExchange() {};