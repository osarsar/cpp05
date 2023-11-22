#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm" , 25, 5, false) , target("Default")
{
    if (this->getsGrade() > 150 || this->geteGrade() > 150)
        throw Bureaucrat::GradeTooLowException();
    if (this->getsGrade() < 1 || this->geteGrade() < 1)
        throw Bureaucrat::GradeTooHighException(); 
    std::cout << "PresidentialPardonForm: Constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm: Destructor called" << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(target , 25, 5, false) , target(target)
{
    if (this->getsGrade() > 150 || this->geteGrade() > 150)
        throw Bureaucrat::GradeTooLowException();
    if (this->getsGrade() < 1 || this->geteGrade() < 1)
        throw Bureaucrat::GradeTooHighException(); 
    this->target = target;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &obj)
{
    if (this->getsGrade() > 150 || this->geteGrade() > 150)
        throw Bureaucrat::GradeTooLowException();
    if (this->getsGrade() < 1 || this->geteGrade() < 1)
        throw Bureaucrat::GradeTooHighException(); 
    std::cout << "PresidentialPardonForm: Copy construtor called" << std::endl;
    *this = obj;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const& obj)
{
    std::cout << "PresidentialPardonForm: Copy assignment operator called" << std::endl;
    if (this != &obj)
        this->target = obj.target;
    return (*this);
}

std::string PresidentialPardonForm::get_target() const
{
    return (this->target);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (executor.getGrade() > this->geteGrade())
        throw Bureaucrat::GradeTooHighException();
    else if (this->getsign() == false)
        throw AForm::UnsignedException();

    std::cout << this->get_target() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}