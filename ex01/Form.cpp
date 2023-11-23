#include "Form.hpp"

Form::Form() : name("HERO") , sign(false) , egrade(1), sgrade(1) 
{
    if (this->sgrade > 150 || this->egrade > 150)
        throw Bureaucrat::GradeTooLowException();
    if (this->sgrade < 1 || this->egrade < 1)
        throw Bureaucrat::GradeTooHighException();
    std::cout << "Form: Constructor called" << std::endl;
}

Form::~Form()
{
    std::cout << "Form: Destructor called" << std::endl;
}
Form::Form(Form const &obj) : name(obj.name) , egrade(obj.egrade), sgrade(obj.sgrade) 
{
    if (this->sgrade > 150 || this->egrade > 150)
        throw Bureaucrat::GradeTooLowException();
    if (this->sgrade < 1 || this->egrade < 1)
        throw Bureaucrat::GradeTooHighException();
    std::cout << "Form: Copy construtor called" << std::endl;
    *this = obj;
}

Form& Form::operator=(Form const& obj)
{
    std::cout << "Form: Copy assignment operator called" << std::endl;
    if (this != &obj)
        this->sign = obj.getsign();
    return (*this);
}

std::ostream& operator<<(std::ostream &x, Form const &obj)
{
    x << obj.getName() << " , Form sgrade " << obj.getsGrade() << " , Form egrade " << obj.getsGrade() << " , sign = " << obj.getsign() << std::endl;
    return (x);
}

const std::string Form::getName() const
{
    return (this->name);
}

int Form::geteGrade(void) const
{
    return (this->egrade);
}

int Form::getsGrade(void) const
{
    return (this->sgrade);
}

bool Form::getsign(void) const
{
    return (this->sign);
}

const char* Form::GradeTooHighException::what() const throw()
{
    return ("grade too High");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return ("grade too Low");
}

void Form::beSigned(const Bureaucrat& b)
{
	if (this->sgrade > b.getGrade())
		throw GradeTooLowException();
	this->sign = true;
};

void Form::signForm()
{
    if (this->sign)
        std::cout << "Signed" << std::endl;
    else
        std::cout << "couldn't sign " << std::endl;
}