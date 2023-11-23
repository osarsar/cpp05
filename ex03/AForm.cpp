#include "AForm.hpp"

AForm::AForm() : name("Default") , sign(false) , egrade(1), sgrade(1) 
{
    if (this->sgrade > 150 || this->egrade > 150)
        throw Bureaucrat::GradeTooLowException();
    if (this->sgrade < 1 || this->egrade < 1)
        throw Bureaucrat::GradeTooHighException();  
    std::cout << "AForm: Constructor called" << std::endl;
}

AForm::~AForm()
{
    std::cout << "AForm: Destructor called" << std::endl;
}
AForm::AForm(AForm const &obj) : name(obj.name) , egrade(obj.egrade), sgrade(obj.sgrade)
{
    if (this->sgrade > 150 || this->egrade > 150)
        throw Bureaucrat::GradeTooLowException();
    if (this->sgrade < 1 || this->egrade < 1)
        throw Bureaucrat::GradeTooHighException();  
    std::cout << "AForm: Copy construtor called" << std::endl;
    *this = obj;
}

AForm& AForm::operator=(AForm const& obj)
{
    std::cout << "AForm: Copy assignment operator called" << std::endl;
    if (this != &obj)
        this->sign = obj.getsign();
    return (*this);
}

std::ostream& operator<<(std::ostream &x, AForm const &obj)
{
    x << obj.getName() << " , AForm sgrade " << obj.getsGrade() << " , AForm egrade " << obj.getsGrade() << " , sign = " << obj.getsign() << std::endl;
    return (x);
}

AForm::AForm(std::string name, int egrade, int sgrade, bool sign) : name(name) , sign(sign), egrade(egrade), sgrade(sgrade)
{
    if (this->sgrade > 150 || this->egrade > 150)
        throw Bureaucrat::GradeTooLowException();
    if (this->sgrade < 1 || this->egrade < 1)
        throw Bureaucrat::GradeTooHighException();  
    std::cout << "AForm: Setter Constructor called" << std::endl;
}
const std::string AForm::getName() const
{
    return (this->name);
}

int AForm::geteGrade(void) const
{
    return (this->egrade);
}

int AForm::getsGrade(void) const
{
    return (this->sgrade);
}

bool AForm::getsign(void) const
{
    return (this->sign);
}


const char* AForm::GradeTooHighException::what() const throw()
{
    return ("grade too High");
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return ("grade too Low");
}

const char* AForm::UnsignedException::what() const throw()
{
    return ("unsigned");
}
void AForm::beSigned(const Bureaucrat& b)
{
	if (this->sgrade > b.getGrade())
		throw GradeTooLowException();
	this->sign = true;
};

void AForm::signAForm()
{
    if (this->sign)
        std::cout << "Signed" << std::endl;
    else
        std::cout << "couldn't sign " << std::endl;
}