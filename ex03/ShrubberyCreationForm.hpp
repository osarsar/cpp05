#pragma once

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    private:
        std::string target;
        
    public:
        ShrubberyCreationForm();
        ~ShrubberyCreationForm();
        ShrubberyCreationForm(ShrubberyCreationForm const& obj);
        ShrubberyCreationForm& operator=(ShrubberyCreationForm const& obj);

        ShrubberyCreationForm(std::string filname);
        std::string get_target() const;

        void execute(Bureaucrat const & executor) const;
};

std::ostream& operator<<(std::ostream &x, ShrubberyCreationForm const &obj);