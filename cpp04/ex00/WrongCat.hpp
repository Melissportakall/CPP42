
#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
    WrongCat();                            // Varsayılan kurucu
    WrongCat(const WrongCat& other);       // Kopya kurucu
    WrongCat& operator=(const WrongCat& other); // Kopya atama operatörü
    ~WrongCat();                           // Yıkıcı

    void makeSound() const; // Bu işlev virtual değil, bu yüzden polymorphism çalışmayacak
};

#endif

