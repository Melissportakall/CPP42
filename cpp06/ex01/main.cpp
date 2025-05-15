#include "Serializer.hpp"
#include <iostream>

int main() {
    Data original;
    original.id = 42;
    original.name = "Melis";

    std::cout << "Original Data:\n";
    std::cout << "Address: " << &original << "\n";
    std::cout << "ID: " << original.id << ", Name: " << original.name << "\n\n";

    uintptr_t raw = Serializer::serialize(&original);
    Data* deserialized = Serializer::deserialize(raw);

    std::cout << "Deserialized Data:\n";
    std::cout << "Address: " << deserialized << "\n";
    std::cout << "ID: " << deserialized->id << ", Name: " << deserialized->name << "\n";

    if (deserialized == &original)
        std::cout << "\n✅ Pointerlar eşleşiyor, başarıyla serileştirildi ve çözüldü.\n";
    else
        std::cout << "\n❌ Pointerlar eşleşmiyor!\n";

    return 0;
}

/*
ÖRNEK ÇIKTI
$ ./serializer
Original Data:
Address: 0x7ffee73e1a20
ID: 42, Name: Melis

Deserialized Data:
Address: 0x7ffee73e1a20
ID: 42, Name: Melis

✅ Pointerlar eşleşiyor, başarıyla serileştirildi ve çözüldü.

*/