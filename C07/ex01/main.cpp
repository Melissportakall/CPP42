#include <iostream>
#include "iter.hpp"

// Test fonksiyonları - non-const versiyonları
template<typename T>
void printElement(T& element) {
    std::cout << element << " ";
}

template<typename T>
void doubleElement(T& element) {
    element *= 2;
}

// Test fonksiyonları - const versiyonları
template<typename T>
void printElementConst(const T& element) {
    std::cout << element << " ";
}

template<typename T>
void printElementWithIndex(const T& element) {
    static int index = 0;
    std::cout << "[" << index++ << "]:" << element << " ";
}

int main() {
    std::cout << "=== Test 1: int array with non-const functions ===" << std::endl;
    int intArray[] = {1, 2, 3, 4, 5};
    std::cout << "Original array: ";
    iter(intArray, 5, printElement<int>);
    std::cout << std::endl;
    
    std::cout << "Doubling elements..." << std::endl;
    iter(intArray, 5, doubleElement<int>);
    
    std::cout << "After doubling: ";
    iter(intArray, 5, printElement<int>);
    std::cout << std::endl;
    
    std::cout << "\n=== Test 2: const int array with const functions ===" << std::endl;
    const int constIntArray[] = {10, 20, 30, 40, 50};
    std::cout << "Const array: ";
    iter(constIntArray, 5, printElementConst<int>);
    std::cout << std::endl;
    
    std::cout << "With index: ";
    iter(constIntArray, 5, printElementWithIndex<int>);
    std::cout << std::endl;
    
    std::cout << "\n=== Test 3: string array ===" << std::endl;
    std::string stringArray[] = {"Hello", "World", "C++", "Templates"};
    std::cout << "String array: ";
    iter(stringArray, 4, printElement<std::string>);
    std::cout << std::endl;
    
    std::cout << "\n=== Test 4: double array ===" << std::endl;
    double doubleArray[] = {1.1, 2.2, 3.3, 4.4};
    std::cout << "Double array: ";
    iter(doubleArray, 4, printElementConst<double>);
    std::cout << std::endl;
    
    return 0;
} 