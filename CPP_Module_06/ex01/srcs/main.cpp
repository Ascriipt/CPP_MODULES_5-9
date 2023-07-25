#include "Serializer.hpp"

static void printDataSet(const Data *dataSet) {
    std::cout << "int : " << dataSet->d_int << std::endl;
    std::cout << "char : " << dataSet->d_char << std::endl;
    std::cout << "size_t : " << dataSet->d_size_t << std::endl;
    std::cout << "string : " << dataSet->d_string << std::endl;
    std::cout << "void : " << dataSet->d_void << std::endl;
}

int main( void ) {
    Data    *otherRandomSet = NULL;
    Data    *randomDataSet = new Data;

    randomDataSet->d_int = -12;
    randomDataSet->d_char = 'x';
    randomDataSet->d_size_t = 41;
    randomDataSet->d_void = NULL;
    randomDataSet->d_string = "je suis un tset";

    std::cout << "\033[0;32m";
    printDataSet(randomDataSet);
    otherRandomSet = Serializer::deserialize(Serializer::serialize(randomDataSet));
    std::cout << "\033[0;31m";
    printDataSet(randomDataSet);
    std::cout << "\033[0m";
    delete otherRandomSet;
}