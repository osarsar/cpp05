#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("HERO") , grade(1) 
{
    if (this->grade > 150)
        throw Bureaucrat::GradeTooLowException();
    if (this->grade < 1)
        throw Bureaucrat::GradeTooHighException(); 
    std::cout << "Bureaucrat: Constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat: Destructor called" << std::endl;
}
Bureaucrat::Bureaucrat(Bureaucrat const &obj) : name(obj.getName())
{
    std::cout << "Bureaucrat: Copy construtor called" << std::endl;
    *this = obj;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const& obj)
{
    std::cout << "Bureaucrat: Copy assignment operator called" << std::endl;
    if (this != &obj)
        this->grade = obj.getGrade();
    return (*this);
}

std::ostream& operator<<(std::ostream &x, Bureaucrat const &obj)
{
    x << obj.getName() << " , bureaucrat grade " << obj.getGrade();
    return (x);
}

void Bureaucrat::incre_grade(void)
{
    if (this->grade < 1)
        throw GradeTooHighException();
    this->grade--;
    if (this->grade < 1)
        throw GradeTooHighException();
}

void Bureaucrat::decre_grade(void)
{
    if (this->grade > 150)
        throw GradeTooLowException();
    this->grade++;
    if (this->grade > 150)
        throw GradeTooLowException();
}

const std::string Bureaucrat::getName() const
{
    return (this->name);
}

int Bureaucrat::getGrade(void) const
{
    return (this->grade);
}

void Bureaucrat::setGrade(int grade)
{
    this->grade = grade;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("grade too High");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("grade too Low");
}