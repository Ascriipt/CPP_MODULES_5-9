#include "ScalarConverter.hpp"

int main(int ac, char **av) {
    for (int i = 1; i < ac; i++) {
        ScalarConverter::resType(av[i]);
    }
}