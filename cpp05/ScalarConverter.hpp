#include <iostream>
#include <sstream>
#include <limits>

class  ScalarConverter
{
    public:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(ScalarConverter & obj) ;
        ScalarConverter& operator=(ScalarConverter & obj) ;
        static void convert( std::string& input);
};