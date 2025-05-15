#include "Base.hpp"
#include "identify.cpp" // direkt çağırmak için
#include "generate.cpp"
#include <iostream>

int main() {
    Base* obj = generate();

    std::cout << "Pointer ile identify: ";
    identify(obj);

    std::cout << "Referans ile identify: ";
    identify(*obj);

    delete obj;
    return 0;
}

/*
$ ./identify
Pointer ile identify: B
Referans ile identify: B

*/