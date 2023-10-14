/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:10:20 by maparigi          #+#    #+#             */
/*   Updated: 2023/10/14 23:45:27 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

static std::string removeWhiteSpaces(const std::string str) {

    std::string	newStr;

    for (size_t i = 0; i < str.size(); ++i) {
	if (!std::isspace(str[i])) {
	    newStr += str[i];
	}
    }
    return newStr;
}

static std::string findClosestKey(const std::map<std::string, float>& myMap, const std::string& inputKey) {
    std::string closestKey = "";
    for (std::map<std::string, float>::const_iterator it = myMap.begin(); it != myMap.end(); ++it) {
		if (it->first <= inputKey)
	    	closestKey = it->first;
		else
	    	break;
    }
    return closestKey;
}

static bool	isValidDateFormat( const std::string & date ) {
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
	return true;
    }
    return false;
};

BitcoinExchange::BitcoinExchange( const int ac, const char *filename ) {

    if ( ac > 2 )
	throw	BitcoinExchange::InvalidArgumentNumber();
    else if ( ac < 2 )
	throw	BitcoinExchange::InvalidArgumentNumber();
    initDataBase();
    initFile( filename );
    if ( PRINT_DEBUG ) {
	std::cout << "an instance of " << PURPLE << "BitcoinExchange " << NC
	    << "has been " << GREEN << "created" << NC << "." << std::endl;
    }
}

void BitcoinExchange::displayConversion() {

    std::string line;

    while (std::getline(_file, line)) {
	try {
	    exchange(line);
	} catch (std::exception &e) {
	    std::cout << "Error: " << e.what() << std::endl;
	}}
}

BitcoinExchange::~BitcoinExchange() {

    if (PRINT_DEBUG) {
	std::cout << "an instance of " << PURPLE << "BitcoinExchange " << NC
	    << "has been " << RED << "destroyed" << NC << std::endl;
    }
}

BitcoinExchange::BadInput::BadInput( const std::string & message ) {
    _errorMessage = BAD_INPUT_ERR_M + message;
}

BitcoinExchange::BadInput::~BadInput() throw() {}

const char *BitcoinExchange::BadInput::what() const throw() {
    return _errorMessage.c_str();
}

BitcoinExchange::InvalidDateFormat::InvalidDateFormat(const std::string & message) {
    _errorMessage = INVALID_DATE_ERR_M + message;
}

BitcoinExchange::InvalidDateFormat::~InvalidDateFormat() throw() {}

const char *BitcoinExchange::InvalidDateFormat::what() const throw() {
    return _errorMessage.c_str();
}

void BitcoinExchange::initDataBase() {

    std::ifstream file("data.csv");
    if (!file.is_open())
		throw BitcoinExchange::InvalidFile();
    file.close();
    _database.open("data.csv");
    fillDatabase();
}

void BitcoinExchange::initFile(const char *fileName) {

    std::ifstream file(fileName);
    if (!file.is_open()) {
		throw BitcoinExchange::InvalidFile();
    }
    file.close();
    _fileName = fileName;
    _file.open(fileName);
}

void BitcoinExchange::fillDate(const std::string line) {

    std::string lineWithoutSpaces = removeWhiteSpaces(line);
    std::size_t separatorPos = line.find_first_of(DB_SEPARATORS);

    if (separatorPos != std::string::npos) {
	std::string datePart = lineWithoutSpaces.substr(0, separatorPos);
	std::string valuePart = lineWithoutSpaces.substr(separatorPos + 1);

	std::istringstream valueStream(valuePart);
	float value;
	if (valueStream >> value) {
	    checkDateFormat(datePart);
	    _dataMap[datePart] = value;
	    return;
	}
    }
    else {throw InvalidFile();}
}

void BitcoinExchange::fillDatabase() {

    std::string	line;

    while (std::getline(_database, line)) {
	fillDate(line);
    }
    _database.close();
}

void BitcoinExchange::execute(std::ifstream &file) {

    std::string	line;
    while (std::getline(file, line))
		std::cout << line << std::endl;
    _file.close();
}

void BitcoinExchange::checkDateFormat(const std::string &date) const {

    if (!isValidDateFormat(date))
		throw InvalidDateFormat(date);
}

void BitcoinExchange::checkValueRequirements(const float value) const {

    if (value < 0)
		throw NegativeValue();
    if (value > 100)
		throw TooLargeValue();
}

std::string BitcoinExchange::findClosestDate(const std::map<std::string, float>& myMap, const std::string& input) const {

    std::string closestDate = findClosestKey(myMap, input);

    if (closestDate.empty())
		throw TooEarlyDate();
    return closestDate;
}

void BitcoinExchange::exchange(const std::string line) const {

    std::string lineWithoutSpaces = removeWhiteSpaces( line );
    std::size_t separatorPos = lineWithoutSpaces.find_first_of( SEPARATORS );

    if (separatorPos != std::string::npos) {
	std::string datePart = lineWithoutSpaces.substr(0, separatorPos);
	std::string valuePart = lineWithoutSpaces.substr(separatorPos + 1);

	std::istringstream valueStream(valuePart);
	float value;
	if ( valueStream >> value ) {
	    checkDateFormat( datePart );
	    checkValueRequirements( value );
	    std::string closestDate = findClosestDate( _dataMap, datePart );
	    std::cout << datePart << " => " << value
		<< " = " << value * _dataMap.at( closestDate ) << std::endl;
	}
    } else {
		throw BadInput(line);
	}
}
