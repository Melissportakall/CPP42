#include "Fixed.hpp"

int main( void ) {

    std::cout << "a :";
    Fixed a;
    std::cout << "b :";
    Fixed const b( Fixed(5.05f) * Fixed(2) );

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << b << std::endl;

    std::cout << Fixed::max( a, b ) << std::endl;

    std::cout << Fixed::min( a, b ) << std::endl;

    if(a < b)
        std::cout << "a is less than b" << std::endl;
    if(b < a)
        std::cout << "a is greater than b" << std::endl;

    return 0;
}