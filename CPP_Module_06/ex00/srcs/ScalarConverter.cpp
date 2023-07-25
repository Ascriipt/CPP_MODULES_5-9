#include "ScalarConverter.hpp"

std::string	ScalarConverter::isPrintableChar( char c ) {
	if (c >= 33 && c <= 126) {
		std::cout << c;
		return	"";
	}
	return	"n/a";
}

void    ScalarConverter::convertFromInt( int x ) {
    std::cout << "char : " << isPrintableChar(static_cast<char>(x)) << std::endl;
    std::cout << "int : " << x << std::endl;
    std::cout << "float : " << static_cast<float>(x) << ".0f" << std::endl;
    std::cout << "double : " << static_cast<double>(x) << ".0" << std::endl;
}

void    ScalarConverter::convertFromChar( char c ) {
    std::cout << "char : " << c << std::endl;
    std::cout << "int : " << static_cast<int>(c) << std::endl;
    std::cout << "float : " << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << "double : " << static_cast<double>(c) << ".0" << std::endl;
}

void    ScalarConverter::convertFromFloat( float f ) {
	std::cout << "char : " << isPrintableChar(static_cast<char>(f)) << std::endl;
    std::cout << "int : " << static_cast<int>(f) << std::endl;
    std::cout << "float : " << f << std::endl;
    std::cout << "double : " << static_cast<double>(f) << std::endl;
}

void    ScalarConverter::convertFromDouble( double d ) {
    (void)d;
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
    if ( input.empty() || input.find(".") == std::string::npos ) return false;
    char* end;
    strtod(input.c_str(), &end);
    return (*end == '\0');
}

bool isFloat(const std::string& input) {
    if (input.empty()) return false;
    char* end;
    strtof(input.c_str(), &end);
    return (*end == 'f' && errno != ERANGE);
}

void    ScalarConverter::converter( const std::string &input ) {
    char*   end;

	if (isFloat(input)) {
		std::cout << "the input is a float" << std::endl;
        convertFromFloat(strtof(input.c_str(), &end));
    } else if (isDouble(input)) {
		std::cout << "the input is a double" << std::endl;
		convertFromDouble(strtod(input.c_str(), &end));
	} else if (isInt(input)) {
		std::cout << "the input is an int" << std::endl;
        convertFromInt(strtol(input.c_str(), &end, 10));
    } else if (isChar(input)) {
		std::cout << "the input is a char" << std::endl;
        convertFromChar(input[0]);
    } else {
        std::cout << "input is not valid" << std::endl;
    }
}