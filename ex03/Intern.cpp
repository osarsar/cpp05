#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "Intern: Constructor called" << std::endl;
}

Intern::~Intern()
{
    std::cout << "Intern: Destructor called" << std::endl;
}
Intern::Intern(Intern const &obj)
{
    std::cout << "Intern: Copy construtor called" << std::endl;
    *this = obj;
}

Intern& Intern::operator=(Intern const& obj)
{
    (void)obj;
    std::cout << "Intern: Copy assignment operator called" << std::endl;
    return (*this);
}

AForm* Intern::make_ShrubberyCreationForm(std::string target)
{
    return (new ShrubberyCreationForm(target));
}
AForm* Intern::make_RobotomyRequestForm(std::string target)
{
    return (new RobotomyRequestForm(target));
}
AForm* Intern::make_PresidentialPardonForm(std::string target)
{
    return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(std::string name, std::string target)
{
    typedef AForm* (Intern::*t_mbr)(std::string target);
    t_mbr ptr_to_mbr[] = {&Intern::make_ShrubberyCreationForm, &Intern::make_RobotomyRequestForm, &Intern::make_PresidentialPardonForm};
    std::string all_Forms[] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
    int i = 0;
    while (i < 4)
    {
        if (name == all_Forms[i])
        {
            std::cout << "Intern creates " << name << std::endl;
            return ((this->*ptr_to_mbr[i])(target));
        }
        i++;
    }
    std::cout << "the name doesn't exist \n";
    return (0);
}