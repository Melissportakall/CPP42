#include <iostream>
#include <string>
#include "Array.hpp"

int main() {
    std::cout << "=== Array Template Class Test ===" << std::endl;
    
    std::cout << "\n--- Test 1: Default constructor ---" << std::endl;
    Array<int> emptyArray;
    std::cout << "Empty array size: " << emptyArray.size() << std::endl;
    
    std::cout << "\n--- Test 2: Parameterized constructor ---" << std::endl;
    Array<int> intArray(5);
    std::cout << "Int array size: " << intArray.size() << std::endl;
    
    // Set some values
    for (unsigned int i = 0; i < intArray.size(); i++) {
        intArray[i] = i * 10;
    }
    
    std::cout << "Int array values: ";
    for (unsigned int i = 0; i < intArray.size(); i++) {
        std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;
    
    std::cout << "\n--- Test 3: Copy constructor ---" << std::endl;
    Array<int> copiedArray(intArray);
    std::cout << "Copied array size: " << copiedArray.size() << std::endl;
    std::cout << "Copied array values: ";
    for (unsigned int i = 0; i < copiedArray.size(); i++) {
        std::cout << copiedArray[i] << " ";
    }
    std::cout << std::endl;
    
    std::cout << "\n--- Test 4: Assignment operator ---" << std::endl;
    Array<int> assignedArray;
    assignedArray = intArray;
    std::cout << "Assigned array size: " << assignedArray.size() << std::endl;
    std::cout << "Assigned array values: ";
    for (unsigned int i = 0; i < assignedArray.size(); i++) {
        std::cout << assignedArray[i] << " ";
    }
    std::cout << std::endl;
    
    std::cout << "\n--- Test 5: String array ---" << std::endl;
    Array<std::string> stringArray(3);
    stringArray[0] = "Hello";
    stringArray[1] = "World";
    stringArray[2] = "C++";
    
    std::cout << "String array values: ";
    for (unsigned int i = 0; i < stringArray.size(); i++) {
        std::cout << stringArray[i] << " ";
    }
    std::cout << std::endl;
    
    std::cout << "\n--- Test 6: Exception handling ---" << std::endl;
    try {
        std::cout << "Trying to access index 10 in array of size 5..." << std::endl;
        int value = intArray[10];
        std::cout << "Value: " << value << std::endl;
    } catch (const IndexOutOfBoundsException& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    try {
        std::cout << "Trying to access index -1..." << std::endl;
        int value = intArray[-1];
        std::cout << "Value: " << value << std::endl;
    } catch (const IndexOutOfBoundsException& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    std::cout << "\n--- Test 7: Const array ---" << std::endl;
    const Array<int> constArray = intArray;
    std::cout << "Const array size: " << constArray.size() << std::endl;
    std::cout << "Const array values: ";
    for (unsigned int i = 0; i < constArray.size(); i++) {
        std::cout << constArray[i] << " ";
    }
    std::cout << std::endl;
    
    std::cout << "\n--- Test 8: Deep copy test ---" << std::endl;
    std::cout << "Original array before modification: ";
    for (unsigned int i = 0; i < intArray.size(); i++) {
        std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;
    
    // Modify copied array
    copiedArray[0] = 999;
    
    std::cout << "Original array after modifying copy: ";
    for (unsigned int i = 0; i < intArray.size(); i++) {
        std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Modified copy: ";
    for (unsigned int i = 0; i < copiedArray.size(); i++) {
        std::cout << copiedArray[i] << " ";
    }
    std::cout << std::endl;
    
    return 0;
} 