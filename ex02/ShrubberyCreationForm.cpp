#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm" , 145, 137, false), target("Default")
{
    if (this->getsGrade() > 150 || this->geteGrade() > 150)
        throw Bureaucrat::GradeTooLowException();
    if (this->getsGrade() < 1 || this->geteGrade() < 1)
        throw Bureaucrat::GradeTooHighException(); 
    std::cout << "ShrubberyCreationForm: Constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm: Destructor called" << std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(target , 145, 137, false) , target(target)
{
    if (this->getsGrade() > 150 || this->geteGrade() > 150)
        throw Bureaucrat::GradeTooLowException();
    if (this->getsGrade() < 1 || this->geteGrade() < 1)
        throw Bureaucrat::GradeTooHighException(); 
    this->target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &obj)
{
    if (this->getsGrade() > 150 || this->geteGrade() > 150)
        throw Bureaucrat::GradeTooLowException();
    if (this->getsGrade() < 1 || this->geteGrade() < 1)
        throw Bureaucrat::GradeTooHighException(); 
    std::cout << "ShrubberyCreationForm: Copy construtor called" << std::endl;
    *this = obj;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const& obj)
{   
    std::cout << "ShrubberyCreationForm: Copy assignment operator called" << std::endl;
    if (this != &obj)
        this->target = obj.target;
    return (*this);
}

std::string ShrubberyCreationForm::get_target() const
{
    return (this->target);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (executor.getGrade() > this->geteGrade())
        throw Bureaucrat::GradeTooHighException();
    else if (this->getsign() == false)
        throw AForm::UnsignedException();
    else
    {
        std::ofstream file(this->target + "_shrubbery");

        if (file.is_open())
        {
            file <<
			"         v" << std::endl <<
			"        >X<" << std::endl <<
			"         A" << std::endl <<
			"        d$b" << std::endl <<
			"      .d\\$$b." << std::endl <<
			"    .d$i$$\\$$b." << std::endl <<
			"       d$$@b" << std::endl <<
			"      d\\$$$ib" << std::endl <<
			"    .d$$$\\$$$b" << std::endl <<
			"  .d$$@$$$$\\$$ib." << std::endl <<
			"      d$$i$$b" << std::endl <<
			"     d\\$$$$@$b" << std::endl <<
			"  .d$@$$\\$$$$$@b." << std::endl <<
			".d$$$$i$$$\\$$$$$$b." << std::endl <<
			"        ###" << std::endl <<
			"        ###" << std::endl <<
			"        ###" << std::endl;
            file.close();
        }
        else
            std::cout << "Error: open file failed" << std::endl;
    }
}