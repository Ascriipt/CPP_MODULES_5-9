#include "ScalarConverter.hpp"

void    ScalarConverter::convertFromInt( int x ) {
    std::cout << "char : n/a " << std::endl;
    std::cout << "int : " << x << std::endl;
    std::cout << "float : " << static_cast<float>(x) << std::endl;
    std::cout << "double : " << static_cast<double>(x) << std::endl;
}

void    ScalarConverter::convertFromChar( char c ) {
    (void)c;
}

void    ScalarConverter::convertFromFloat( float f ) {
    (void)f;
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
    if (input.empty()) return false;
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

    if (isInt(input)) {
        convertFromInt(strtol(input.c_str(), &end, 10));
    } else if (isChar(input)) {
        
    } else if (isDouble(input)) {
        
    } else if (isFloat(input)) {
        
    } else {
        std::cout << "input is not valid" << std::endl;
    }
}