#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        std::string target;
        
    public:
        PresidentialPardonForm();
        ~PresidentialPardonForm();
        PresidentialPardonForm(PresidentialPardonForm const& obj);
        PresidentialPardonForm& operator=(PresidentialPardonForm const& obj);
        PresidentialPardonForm(std::string target);

        std::string get_target() const;
        
        void execute(Bureaucrat const & executor) const;
};