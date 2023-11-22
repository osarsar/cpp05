#pragma once

#include "Bureaucrat.hpp"

class AForm
{
    private:
        const std::string name;
        bool sign;
        const int egrade;
        const int sgrade;
    
    public:
        AForm();
        virtual ~AForm();
        AForm(AForm const &obj);
        AForm& operator=(AForm const &obj);
        AForm(std::string name, int egrade, int sgrade, bool sign);

        const std::string getName() const;
        int getsGrade() const;
        int geteGrade() const ;
        bool getsign() const;

        void beSigned(const Bureaucrat& obj);
        void signAForm(void);

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class UnsignedException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        
        virtual void execute(Bureaucrat const& executor) const = 0;
};

std::ostream& operator<<(std::ostream &x, AForm const &obj);