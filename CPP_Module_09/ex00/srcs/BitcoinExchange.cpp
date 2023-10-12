/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:10:20 by maparigi          #+#    #+#             */
/*   Updated: 2023/10/12 18:30:07 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

static void	resetFile(std::ifstream &file) {

	file.clear();
	file.seekg(0);
}

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
	std::string closestKey = "";  // Initialize with an empty key
	for (std::map<std::string, float>::const_iterator it = myMap.begin(); it != myMap.end(); ++it) {
		if (it->first < inputKey) {
			closestKey = it->first;
		} else {
			// Since the keys are sorted, we break as soon as we find a key greater than the input
			break;
		}
	}
	return closestKey;
}

static bool isValidDateFormat(const std::string& date) {

	// Check the format: YYYY-MM-DD
	if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
		return false;
	}

	// Check if each character is a digit
	for (int i = 0; i < 10; ++i) {
		if (i != 4 && i != 7 && !isdigit(date[i])) {
			return false;
		}
	}
	return true;
}

BitcoinExchange::BitcoinExchange( const int ac, const char *filename ) {

	if ( ac > 2 )
		throw	BitcoinExchange::TooManyArguments();
	else if ( ac < 2 )
		throw	BitcoinExchange::TooFewArguments();
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
		}
		catch (std::exception &e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
}

BitcoinExchange::~BitcoinExchange() {

	_file.close();
	_database.close();
	if (PRINT_DEBUG) {
		std::cout << PURPLE << "BitcoinExchange " << NC << "has been " <<
		RED << "destroyed" << NC << std::endl;
	}
}

BitcoinExchange::BadInput::BadInput( const std::string &message ) {
	_errorMessage = BAD_INPUT_ERR_M + message;
}

BitcoinExchange::BadInput::~BadInput() throw() {}

const char *BitcoinExchange::BadInput::what() const throw() {
	return _errorMessage.c_str();
}

BitcoinExchange::InvalidDateFormat::InvalidDateFormat(const std::string &message) {
	_errorMessage = INVALID_DATE_ERR_M + message;
}

BitcoinExchange::InvalidDateFormat::~InvalidDateFormat() throw() {}

const char *BitcoinExchange::InvalidDateFormat::what() const throw() {
	return _errorMessage.c_str();
}

void BitcoinExchange::initDataBase() {

	std::ifstream file(DB_NAME);
	if (!file.is_open()) {
		throw BitcoinExchange::InvalidDatabase();
	}
	file.close();
	_database.open(DB_NAME);
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
	else {throw InvalidDatabase();}
}

void BitcoinExchange::fillDatabase() {

	std::string	line;

	while (std::getline(_database, line)) {
		fillDate(line);
	}
	resetFile(_database);
}

void BitcoinExchange::displayFile(std::ifstream &file) const {
	
	std::string	line;
	while (std::getline(file, line)) {
		std::cout << line << std::endl;
	}
	resetFile(file);
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
			std::cout << closestDate << " => " << value
				<< " = " << value * _dataMap.at( closestDate ) << std::endl;
		}
	} else {throw BadInput(line);}
}