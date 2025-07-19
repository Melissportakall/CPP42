#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

// Exception class
class IndexOutOfBoundsException : public std::exception {
public:
    virtual const char* what() const throw() {
        return "Index out of bounds";
    }
};

template<typename T>
class Array {
private:
    T* _array;
    unsigned int _size;

public:
    // Default constructor
    Array() : _array(NULL), _size(0) {
    }
    
    // Parameterized constructor
    Array(unsigned int n) : _size(n) {
        if (n > 0) {
            _array = new T[n];
        } else {
            _array = NULL;
        }
    }
    
    // Copy constructor
    Array(const Array& other) : _size(other._size) {
        if (_size > 0) {
            _array = new T[_size];
            for (unsigned int i = 0; i < _size; i++) {
                _array[i] = other._array[i];
            }
        } else {
            _array = NULL;
        }
    }
    
    // Destructor
    ~Array() {
        delete[] _array;
    }
    
    // Assignment operator
    Array& operator=(const Array& other) {
        if (this != &other) {
            delete[] _array;
            _size = other._size;
            if (_size > 0) {
                _array = new T[_size];
                for (unsigned int i = 0; i < _size; i++) {
                    _array[i] = other._array[i];
                }
            } else {
                _array = NULL;
            }
        }
        return *this;
    }
    
    // Size function
    unsigned int size() const {
        return _size;
    }
    
    // Non-const operator[]
    T& operator[](unsigned int index) {
        if (index >= _size) {
            throw IndexOutOfBoundsException();
        }
        return _array[index];
    }
    
    // Const operator[]
    const T& operator[](unsigned int index) const {
        if (index >= _size) {
            throw IndexOutOfBoundsException();
        }
        return _array[index];
    }
};

#endif 