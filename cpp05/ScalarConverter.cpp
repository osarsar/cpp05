#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
    std::cout << "ScalarConverter: Constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "ScalarConverter: Destructor called" << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter & obj) 
{
    std::cout << "ScalarConverter: Copy constructor called" << std::endl;
    *this = obj;
}

ScalarConverter& ScalarConverter::operator=(ScalarConverter & obj)
{
    std::cout << "ScalarConverter: assignement operator called" << std::endl;
    if (this != &obj)
    {

    }
    return (*this);
}

void ScalarConverter::convert( std::string& input) {
    // Convert to char
    try 
    {
        char charValue = std::stoi(input);
        if (isprint(charValue)) 
        {
            std::cout << "char: '" << charValue << "'" << std::endl;
        }
        else 
        {
            std::cerr << "Cannot convert to displayable char." << std::endl;
        }
    } 
    catch (const std::invalid_argument& e) 
    {
        std::cerr << "Invalid input for char conversion." << std::endl;
    }

    // Convert to int
    try 
    {
        int intValue = std::stoi(input);
        std::cout << "int: " << intValue << std::endl;
    } catch (const std::invalid_argument& e) 
    {
        std::cerr << "Invalid input for int conversion." << std::endl;
    }

    // Convert to float
    try 
    {
        size_t pos;
        float floatValue = std::stof(input, &pos);
        if (pos == input.size()) {
            std::cout << "float: " << floatValue << "f" << std::endl;
        } 
        else 
        {
            std::cerr << "Invalid input for float conversion." << std::endl;
        }
    } catch (const std::invalid_argument& e)
     {
        std::cerr << "Invalid input for float conversion." << std::endl;
    }

    // Convert to double
    try {
        size_t pos;
        double doubleValue = std::stod(input, &pos);
        if (pos == input.size()) {
            std::cout << "double: " << doubleValue << std::endl;
        } else {
            std::cerr << "Invalid input for double conversion." << std::endl;
        }
    } catch (const std::invalid_argument& e) {
        std::cerr << "Invalid input for double conversion." << std::endl;
    }
}

int main() {
    std::string input;
    std::cout << "Enter a C++ literal: ";
    std::cin >> input;

    ScalarConverter::convert(input);

    return 0;
}
