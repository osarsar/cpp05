#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
    public:
        Intern();
        ~Intern();
        Intern(Intern const& obj);
        Intern& operator=(Intern const& obj);

        AForm *makeForm(std::string name, std::string target);
        AForm *make_ShrubberyCreationForm(std::string target);
        AForm *make_RobotomyRequestForm(std::string target);
        AForm *make_PresidentialPardonForm(std::string target);
};


