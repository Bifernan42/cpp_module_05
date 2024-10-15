#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include "AForm.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm
{
    virtual void beSigned(const Bureaucrat &);


};

#endif
