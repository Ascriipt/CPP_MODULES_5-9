#include "ScalarConverter.hpp"

std::string	ScalarConverter::hasNoMantissaFloat( float f ) {
	std::cout << f;
	if (!(std::abs(f - trunc(f)) < 1e-5) && !(std::abs(f - trunc(f)) < 1e-4))
		return	"f";
	return	".0f";
}

std::string	ScalarConverter::hasNoMantissaDouble( double d ) {
	std::cout << d;
	if (!(std::abs(d - trunc(d)) < 1e-5) && !(std::abs(d - trunc(d)) < 1e-4))
		return	"";
	return	".0";
}

std::string	ScalarConverter::isPrintableChar( char c ) {
	if (c >= 33 && c <= 126) {
		std::cout << c;
		return	"";
	}
	return	"n/a";
}

void    ScalarConverter::convertFromInt( int x ) {
	std::cout << "\033[0;32mchar : " << isPrintableChar(static_cast<char>(x)) << std::endl;
	std::cout << "\033[0;33mint : " << x << std::endl;
	std::cout << "\033[0;34mfloat : " << hasNoMantissaFloat(static_cast<float>(x)) << std::endl;
	std::cout << "\033[1;35mdouble : " << hasNoMantissaDouble(static_cast<double>(x)) << std::endl;
	std::cout << "\033[0m";
}

void    ScalarConverter::convertFromChar( char c ) {
	std::cout << "\033[0;32mchar : " << c << std::endl;
	std::cout << "\033[0;33mint : " << static_cast<int>(c) << std::endl;
	std::cout << "\033[0;34mfloat : " << hasNoMantissaFloat(static_cast<float>(c)) << std::endl;
	std::cout << "\033[1;35mdouble : " << hasNoMantissaDouble(static_cast<double>(c)) << std::endl;
	std::cout << "\033[0m";
}

void    ScalarConverter::convertFromFloat( float f ) {
	std::cout << "\033[0;32mchar : " << isPrintableChar(static_cast<char>(f)) << std::endl;
	std::cout << "\033[0;33mint : " << static_cast<int>(f) << std::endl;
	std::cout << "\033[0;34mfloat : " << hasNoMantissaFloat(f) << std::endl;
	std::cout << "\033[1;35mdouble : " << hasNoMantissaDouble(static_cast<double>(f)) << std::endl;
	std::cout << "\033[0m";
}

void    ScalarConverter::convertFromDouble( double d ) {
	std::cout << "\033[0;32mchar : " << isPrintableChar(static_cast<char>(d)) << std::endl;
	std::cout << "\033[0;33mint : " << static_cast<int>(d) << std::endl;
	std::cout << "\033[0;34mfloat : " << hasNoMantissaFloat(static_cast<float>(d)) << std::endl;
	std::cout << "\033[1;35mdouble : " << hasNoMantissaDouble(d) << std::endl;
	std::cout << "\033[0m";
}

bool isChar( const std::string &input ) {
	return input.length() == 1;
}

bool isInt( const std::string &input ) {
	if (input.empty()) return false;
	char* end;
	strtol(input.c_str(), &end, 10);
	return (*end == '\0');
}

bool isDouble( const std::string &input ) {
	if ( input.empty() || input.find(".") == std::string::npos || input.find(".") + 1 == input.length()) return false;
	char* end;
	strtod(input.c_str(), &end);
	return (*end == '\0');
}

bool isFloat(const std::string& input) {
	if ( input.empty() || input.find(".") == std::string::npos || input.find("f") - 1 == input.find(".")) return false;
	char* end;
	strtof(input.c_str(), &end);
	return (*end == 'f' && errno != ERANGE);
}

void    ScalarConverter::converter( const std::string &input ) {
	char*   end;

	if (isFloat(input)) {
		// std::cout << "the input is a float" << std::endl;
		convertFromFloat(strtof(input.c_str(), &end));
	} else if (isDouble(input)) {
		// std::cout << "the input is a double" << std::endl;
		convertFromDouble(strtod(input.c_str(), &end));
	} else if (isInt(input)) {
		// std::cout << "the input is an int" << std::endl;
		convertFromInt(strtol(input.c_str(), &end, 10));
	} else if (isChar(input)) {
		// std::cout << "the input is a char" << std::endl;
		convertFromChar(input[0]);
	} else {
		std::cout << "\033[1;31minput is not valid\033[0m" << std::endl;
	}
}
