#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) { (void)other; return *this; }
ScalarConverter::~ScalarConverter() {}


static bool isChar(const std::string& literal) {
   
    if (literal.length() == 1 && !std::isdigit(literal[0]) && std::isprint(literal[0])) {
        return true;
    }
    
    if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'') {
        return true;
    }
    return false;
}

static bool isInt(const std::string& literal) {
    if (literal.empty()) return false;
    
    
    size_t start = 0;
    if (literal[0] == '-' || literal[0] == '+') {
        if (literal.length() == 1) return false;
        start = 1;
    }
    
    
    for (size_t i = start; i < literal.length(); i++) {
        if (!std::isdigit(literal[i])) return false;
    }
    
    return true;
}

static bool isFloat(const std::string& literal) {
    if (literal == "-inff" || literal == "+inff" || literal == "nanf") 
        return true;
    if (literal.empty() || literal[literal.length() - 1] != 'f') 
        return false;
    std::string withoutF = literal.substr(0, literal.length() - 1);
    char* endptr;
    std::strtod(withoutF.c_str(), &endptr);
    return *endptr == '\0';
}

static bool isDouble(const std::string& literal) {
    if (literal == "-inf" || literal == "+inf" || literal == "nan") 
        return true;
    if (literal.empty()) return false;
    char* endptr;
    std::strtod(literal.c_str(), &endptr);
    return *endptr == '\0';
}


void ScalarConverter::convert(const std::string& literal) {
    
    if (isChar(literal)) {
        char c;
        if (literal.length() == 1) {
            c = literal[0];
        } else {
            c = literal[1]; 
        }
        
        if (std::isprint(c)) {
            std::cout << "char: '" << c << "'" << std::endl;
        } else {
            std::cout << "char: Non displayable" << std::endl;
        }
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
        return;
    }
    
    
    if (isInt(literal)) {
        
        std::string maxInt = "2147483647";
        std::string minInt = "-2147483648";
        
        bool overflow = false;
        if (literal[0] == '-') {
            if (literal.length() > minInt.length() || 
                (literal.length() == minInt.length() && literal > minInt)) {
                overflow = true;
            }
        } else {
            if (literal.length() > maxInt.length() || 
                (literal.length() == maxInt.length() && literal > maxInt)) {
                overflow = true;
            }
        }
        
        if (overflow) {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
            return;
        }
        
        int i = std::atoi(literal.c_str());
        
        if (i < 0 || i > 127 || !std::isprint(static_cast<char>(i))) {
            std::cout << "char: Non displayable" << std::endl;
        } else {
            std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
        }
        std::cout << "int: " << i << std::endl;
        std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
        return;
    }
    
    
    if (isFloat(literal)) {
        if (literal == "-inff" || literal == "+inff" || literal == "nanf") {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: " << literal << std::endl;
            std::cout << "double: " << literal.substr(0, literal.length() - 1) << std::endl;
            return;
        }
        
        std::string withoutF = literal.substr(0, literal.length() - 1);
        float f = std::atof(withoutF.c_str());
        
        if (std::isnan(f) || std::isinf(f) || f < 0 || f > 127 || !std::isprint(static_cast<char>(f))) {
            std::cout << "char: impossible" << std::endl;
        } else {
            std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
        }
        
        if (std::isnan(f) || std::isinf(f)) {
            std::cout << "int: impossible" << std::endl;
        } else {
            std::cout << "int: " << static_cast<int>(f) << std::endl;
        }
        
        if (f == static_cast<int>(f)) {
            std::cout << "float: " << f << ".0f" << std::endl;
        } else {
            std::cout << "float: " << f << "f" << std::endl;
        }
        if (static_cast<double>(f) == static_cast<int>(static_cast<double>(f))) {
            std::cout << "double: " << static_cast<double>(f) << ".0" << std::endl;
        } else {
            std::cout << "double: " << static_cast<double>(f) << std::endl;
        }
        return;
    }
    
    
    if (isDouble(literal)) {
        if (literal == "-inf" || literal == "+inf" || literal == "nan") {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: " << literal << "f" << std::endl;
            std::cout << "double: " << literal << std::endl;
            return;
        }
        
        double d = std::atof(literal.c_str());
        
        if (std::isnan(d) || std::isinf(d) || d < 0 || d > 127 || !std::isprint(static_cast<char>(d))) {
            std::cout << "char: impossible" << std::endl;
        } else {
            std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
        }
        
        if (std::isnan(d) || std::isinf(d)) {
            std::cout << "int: impossible" << std::endl;
        } else {
            std::cout << "int: " << static_cast<int>(d) << std::endl;
        }
        
        if (static_cast<float>(d) == static_cast<int>(static_cast<float>(d))) {
            std::cout << "float: " << static_cast<float>(d) << ".0f" << std::endl;
        } else {
            std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
        }
        if (d == static_cast<int>(d)) {
            std::cout << "double: " << d << ".0" << std::endl;
        } else {
            std::cout << "double: " << d << std::endl;
        }
        return;
    }
    
    
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
} 