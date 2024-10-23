#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include "AForm.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        std::string target_;
        void dummy() const;
    public:
    PresidentialPardonForm(const std::string);
    PresidentialPardonForm(const PresidentialPardonForm &);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &);
    ~PresidentialPardonForm();
    void setTarget(const std::string);
    std::string getTarget() const;
    void execute(const Bureaucrat &) const;
};

#endif
