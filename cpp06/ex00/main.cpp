#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: ./convert <literal>" << std::endl;
        return 1;
    }

    ScalarConverter::convert(argv[1]);
    return 0;
}
/* bu sekilde olucak
$ ./convert 'a'
char: 'a'
int: 97
float: 97.0f
double: 97.0

$ ./convert 42.0f
char: '*'
int: 42
float: 42.0f
double: 42.0

$ ./convert nan
char: impossible
int: impossible
float: nanf
double: nan*/
