#include "Fixed.hpp"
#include <iostream>

int main(void){

    std::cout << "a;";
    Fixed a;
    std::cout << "b;";
    Fixed b(a);
    std::cout << "c;";
    Fixed c;

    c = b;

    std::cout << "a->" << a.getRawBits() << std::endl;
    std::cout << "b->" << b.getRawBits() << std::endl;
    std::cout << "c->" << c.getRawBits() << std::endl;

    return 0;
}