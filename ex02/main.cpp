#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() 
{
    try
    {
        Bureaucrat const br;
        ShrubberyCreationForm Sobj;
        RobotomyRequestForm Robj;
        PresidentialPardonForm  Pobj;

        Sobj.beSigned(br);
        Robj.beSigned(br);
        Pobj.beSigned(br);
        std::cout << "target = " << Sobj.get_target() << std::endl;
        std::cout << "sgrade = " << Sobj.getsGrade() << std::endl;
        std::cout << "egrade = " << Sobj.geteGrade() << std::endl;
        std::cout << "name = " << Sobj.getName() << std::endl;
        std::cout << "sign = " << Sobj.getsign() << std::endl;
        Sobj.execute(br);
        std::cout << "target = " << Robj.get_target() << std::endl;
        std::cout << "sgrade = " << Robj.getsGrade() << std::endl;
        std::cout << "egrade = " << Robj.geteGrade() << std::endl;
        std::cout << "name = " << Robj.getName() << std::endl;
        std::cout << "sign = " << Robj.getsign() << std::endl;
        Robj.execute(br);
        std::cout << "target = " << Pobj.get_target() << std::endl;
        std::cout << "sgrade = " << Pobj.getsGrade() << std::endl;
        std::cout << "egrade = " << Pobj.geteGrade() << std::endl;
        std::cout << "name = " << Pobj.getName() << std::endl;
        std::cout << "sign = " << Pobj.getsign() << std::endl;
        Pobj.execute(br);
        br.executeForm(Sobj);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}