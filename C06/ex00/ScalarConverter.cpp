/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melisportakal <melisportakal@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 12:12:50 by melisportak       #+#    #+#             */
/*   Updated: 2025/07/19 12:15:49 by melisportak      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
    (void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

static bool isChar(const std::string& literal) {
    return literal.length() == 3 && !std::isdigit(literal[0]);
}

static bool isInt(const std::string& literal) {
    char* endptr;
    std::strtol(literal.c_str(), &endptr, 10);
    return *endptr == '\0' && !literal.empty();
}

static bool isFloat(const std::string& literal) {
    if (literal == "-inff" || literal == "+inff" || literal == "nanf") 
        return true;
    
    if (literal.empty() || literal[literal.length() - 1] != 'f') 
        return false;
    
    std::string withoutF = literal.substr(0, literal.length() - 1);
    char* endptr;
    std::strtof(withoutF.c_str(), &endptr);
    return *endptr == '\0' && !withoutF.empty();
}

static bool isDouble(const std::string& literal) {
    if (literal == "-inf" || literal == "+inf" || literal == "nan") 
        return true;
    
    char* endptr;
    std::strtod(literal.c_str(), &endptr);
    return *endptr == '\0' && !literal.empty();
}



void ScalarConverter::convert(const std::string& literal) {
    if (isChar(literal)) {
        char c = literal[1];
        
        
        if (std::isprint(c)) {
            std::cout << "char: '" << c << "'" << std::endl;
        } else {
            std::cout << "char: Non displayable" << std::endl;
        }
        
    
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        
        
        float f = static_cast<float>(c);
        if (f == static_cast<int>(f)) {
            std::cout << "float: " << f << ".0f" << std::endl;
        } else {
            std::cout << "float: " << f << "f" << std::endl;
        }
        
       
        double d = static_cast<double>(c);
        if (d == static_cast<int>(d)) {
            std::cout << "double: " << d << ".0" << std::endl;
        } else {
            std::cout << "double: " << d << std::endl;
        }
    }
    else if (isInt(literal)) {
        long long int_val = std::atoll(literal.c_str());
        
        if (int_val < std::numeric_limits<int>::min() || int_val > std::numeric_limits<int>::max()) {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
            return;
        }
        
        int i = static_cast<int>(int_val);
        
       
        if (i < 0 || i > 127) {
            std::cout << "char: impossible" << std::endl;
        } else {
            if (std::isprint(static_cast<char>(i))) {
                std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
            } else {
                std::cout << "char: Non displayable" << std::endl;
            }
        }
        
        
        std::cout << "int: " << i << std::endl;
        
        
        float f = static_cast<float>(i);
        std::cout << "float: " << f << ".0f" << std::endl;
        
        
        double d = static_cast<double>(i);
        std::cout << "double: " << d << ".0" << std::endl;
    }
    else if (isFloat(literal)) {
        if (literal == "-inff" || literal == "+inff" || literal == "nanf") {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            if (literal == "nanf") {
                std::cout << "float: nanf" << std::endl;
                std::cout << "double: nan" << std::endl;
            } else {
                std::cout << "float: " << literal << std::endl;
                std::cout << "double: " << literal.substr(0, literal.length() - 1) << std::endl;
            }
            return;
        }
        
        std::string withoutF = literal.substr(0, literal.length() - 1);
        float f = std::atof(withoutF.c_str());
        
        
        if (f < 0 || f > 127 || std::isnan(f) || std::isinf(f)) {
            std::cout << "char: impossible" << std::endl;
        } else {
            if (std::isprint(static_cast<char>(f))) {
                std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
            } else {
                std::cout << "char: Non displayable" << std::endl;
            }
        }
        
        
        if (std::isnan(f) || std::isinf(f) || f < std::numeric_limits<int>::min() || f > std::numeric_limits<int>::max()) {
            std::cout << "int: impossible" << std::endl;
        } else {
            std::cout << "int: " << static_cast<int>(f) << std::endl;
        }
        
        
        if (std::isnan(f) || std::isinf(f)) {
            if (std::isnan(f)) {
                std::cout << "float: nanf" << std::endl;
            } else if (f > 0) {
                std::cout << "float: +inff" << std::endl;
            } else {
                std::cout << "float: -inff" << std::endl;
            }
        } else if (f == static_cast<int>(f)) {
            std::cout << "float: " << f << ".0f" << std::endl;
        } else {
            std::cout << "float: " << f << "f" << std::endl;
        }
        
        
        double d = static_cast<double>(f);
        if (std::isnan(d) || std::isinf(d)) {
            if (std::isnan(d)) {
                std::cout << "double: nan" << std::endl;
            } else if (d > 0) {
                std::cout << "double: +inf" << std::endl;
            } else {
                std::cout << "double: -inf" << std::endl;
            }
        } else if (d == static_cast<int>(d)) {
            std::cout << "double: " << d << ".0" << std::endl;
        } else {
            std::cout << "double: " << d << std::endl;
        }
    }
    else if (isDouble(literal)) {
        if (literal == "-inf" || literal == "+inf" || literal == "nan") {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            if (literal == "nan") {
                std::cout << "float: nanf" << std::endl;
                std::cout << "double: nan" << std::endl;
            } else {
                std::cout << "float: " << literal << "f" << std::endl;
                std::cout << "double: " << literal << std::endl;
            }
            return;
        }
        
        double d = std::atof(literal.c_str());
        
        
        if (d < 0 || d > 127 || std::isnan(d) || std::isinf(d)) {
            std::cout << "char: impossible" << std::endl;
        } else {
            if (std::isprint(static_cast<char>(d))) {
                std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
            } else {
                std::cout << "char: Non displayable" << std::endl;
            }
        }
        
        
        if (std::isnan(d) || std::isinf(d) || d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max()) {
            std::cout << "int: impossible" << std::endl;
        } else {
            std::cout << "int: " << static_cast<int>(d) << std::endl;
        }
        
        
        float f = static_cast<float>(d);
        if (std::isnan(f) || std::isinf(f)) {
            if (std::isnan(f)) {
                std::cout << "float: nanf" << std::endl;
            } else if (f > 0) {
                std::cout << "float: +inff" << std::endl;
            } else {
                std::cout << "float: -inff" << std::endl;
            }
        } else if (f == static_cast<int>(f)) {
            std::cout << "float: " << f << ".0f" << std::endl;
        } else {
            std::cout << "float: " << f << "f" << std::endl;
        }
        
        
        if (std::isnan(d) || std::isinf(d)) {
            if (std::isnan(d)) {
                std::cout << "double: nan" << std::endl;
            } else if (d > 0) {
                std::cout << "double: +inf" << std::endl;
            } else {
                std::cout << "double: -inf" << std::endl;
            }
        } else if (d == static_cast<int>(d)) {
            std::cout << "double: " << d << ".0" << std::endl;
        } else {
            std::cout << "double: " << d << std::endl;
        }
    }
    else {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
} 