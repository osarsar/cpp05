#include "Form.hpp"

int main()
{
    Form obj;
    Bureaucrat Br;
    try
    {
        Br.setGrade(9);
        Br.decre_grade();
        std::cout << Br.getGrade() << std::endl;
        obj.beSigned(Br);
        obj.signForm();
        std::cout << obj << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}