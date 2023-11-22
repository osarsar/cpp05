#pragma once

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private:
        std::string target;
        
    public:
        RobotomyRequestForm();
        ~RobotomyRequestForm();
        RobotomyRequestForm(RobotomyRequestForm const& obj);
        RobotomyRequestForm& operator=(RobotomyRequestForm const& obj);
        RobotomyRequestForm(std::string filname);

        std::string get_target() const;

        void execute(Bureaucrat const & executor) const;
};