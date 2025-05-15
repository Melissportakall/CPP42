#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "A\n";
    else if (dynamic_cast<B*>(p))
        std::cout << "B\n";
    else if (dynamic_cast<C*>(p))
        std::cout << "C\n";
}

void identify(Base& p) {
    // pointer kullanmak yasak! Bu yüzden try-catch yapısı kullanılır
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A\n";
    } catch (...) {
        try {
            (void)dynamic_cast<B&>(p);
            std::cout << "B\n";
        } catch (...) {
            try {
                (void)dynamic_cast<C&>(p);
                std::cout << "C\n";
            } catch (...) {
                std::cout << "Unknown\n";
            }
        }
    }
}
