#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat obj;
    try
    {
        obj.incre_grade();
        std::cout << obj << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}