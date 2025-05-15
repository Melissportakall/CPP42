#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <limits>
#include <cstdlib>
#include <cmath>
#include <cctype>

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) { return *this; }

static bool isCharLiteral(const std::string& str) {
    return str.length() == 3 && str.front() == '\'' && str.back() == '\'';
}

void ScalarConverter::convert(const std::string& literal) {
    double value;
    bool isFloatLiteral = false;

    if (isCharLiteral(literal)) {
        char c = literal[1];
        value = static_cast<double>(c);
    } else if (literal == "nan" || literal == "+inf" || literal == "-inf" ||
               literal == "nanf" || literal == "+inff" || literal == "-inff") {
        std::string modified = literal;
        if (modified.back() == 'f') {
            modified.pop_back();
            isFloatLiteral = true;
        }
        if (modified == "nan") value = std::numeric_limits<double>::quiet_NaN();
        else if (modified == "+inf") value = std::numeric_limits<double>::infinity();
        else value = -std::numeric_limits<double>::infinity();
    } else {
        try {
            size_t pos;
            value = std::stod(literal, &pos);
            if (pos < literal.length() && literal[pos] == 'f') {
                isFloatLiteral = true;
            }
        } catch (...) {
            std::cout << "Invalid input\n";
            return;
        }
    }

    // CHAR
    std::cout << "char: ";
    if (std::isnan(value) || value < 0 || value > 127)
        std::cout << "impossible\n";
    else if (!std::isprint(static_cast<char>(value)))
        std::cout << "Non displayable\n";
    else
        std::cout << "'" << static_cast<char>(value) << "'\n";

    // INT
    std::cout << "int: ";
    if (std::isnan(value) || value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
        std::cout << "impossible\n";
    else
        std::cout << static_cast<int>(value) << "\n";

    // FLOAT
    std::cout << "float: ";
    std::cout << std::fixed << std::setprecision(1)
              << static_cast<float>(value) << "f\n";

    // DOUBLE
    std::cout << "double: ";
    std::cout << std::fixed << std::setprecision(1)
              << value << "\n";
}
