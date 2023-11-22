#include "Bureaucrat.hpp"

class Form
{
    private:
        const std::string name;
        bool sign;
        const int egrade;
        const int sgrade;
    
    public:
        Form();
        ~Form();
        Form(Form const &obj);
        Form& operator=(Form const &obj);

        const std::string getName() const;
        int getsGrade() const;
        int geteGrade() const ;
        bool getsign() const;

        void beSigned(const Bureaucrat& obj);
        void signForm(void);

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
};

std::ostream& operator<<(std::ostream &x, Form const &obj);