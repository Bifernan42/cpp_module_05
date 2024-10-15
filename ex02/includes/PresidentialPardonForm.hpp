#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include "AForm.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm
{
    virtual void beSigned(const Bureaucrat &);


};

#endif
