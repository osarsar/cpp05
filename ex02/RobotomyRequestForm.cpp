#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45, false), target("Default")
{
    if (this->getsGrade() > 150 || this->geteGrade() > 150)
        throw Bureaucrat::GradeTooLowException();
    if (this->getsGrade() < 1 || this->geteGrade() < 1)
        throw Bureaucrat::GradeTooHighException(); 
    std::cout << "RobotomyRequestForm: Constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm: Destructor called" << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target, 72, 45, false), target(target)
{
    if (this->getsGrade() > 150 || this->geteGrade() > 150)
        throw Bureaucrat::GradeTooLowException();
    if (this->getsGrade() < 1 || this->geteGrade() < 1)
        throw Bureaucrat::GradeTooHighException(); 
    this->target = target;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &obj)
{
    if (this->getsGrade() > 150 || this->geteGrade() > 150)
        throw Bureaucrat::GradeTooLowException();
    if (this->getsGrade() < 1 || this->geteGrade() < 1)
        throw Bureaucrat::GradeTooHighException(); 
    std::cout << "RobotomyRequestForm: Copy construtor called" << std::endl;
    *this = obj;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const& obj)
{
    std::cout << "RobotomyRequestForm: Copy assignment operator called" << std::endl;
    if (this != &obj)
        this->target = obj.target;
    return (*this);
}

std::string RobotomyRequestForm::get_target() const
{
    return (this->target);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (executor.getGrade() > this->geteGrade())
        throw Bureaucrat::GradeTooHighException();
    else if (this->getsign() == false)
        throw AForm::UnsignedException();
    
    std::cout << "Making drilling noises" << std::endl;
    if (rand() % 2 == 0) 
        std::cout << this->get_target() << " has been robotomized successfully." << std::endl;
    else 
        std::cout << "Robotomy failed " << std::endl;
}