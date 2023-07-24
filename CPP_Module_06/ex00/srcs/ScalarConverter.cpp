#include "ScalarConverter.hpp"

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

void    ScalarConverter::resType( const std::string &input ) {
    
    if (isInt(input)) {
        std::cout << "The input is an int." << std::endl;
    } else if (isChar(input)) {
        std::cout << "The input is a char." << std::endl;
    } else if (isDouble(input)) {
        std::cout << "The input is a double." << std::endl;
    } else if (isFloat(input)) {
        std::cout << "The input is a float." << std::endl;
    } else {
        std::cout << "The input is not a char, int, double, or float." << std::endl;
    }
}