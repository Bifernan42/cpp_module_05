#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string target): AForm("PresidentialPardonForm", 25, 5)
{
    if (target.empty())
    {
        std::cerr << "\033[34;2mPPF : Warning : provided empty target !\033[0m\n";
        setTarget("default_target");
    }
    else
        setTarget(target);
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other): AForm(other), target_(other.getTarget()) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    if (this != &other)
    {
        setTarget(other.getTarget());
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(){}

void PresidentialPardonForm::setTarget(const std::string target)
{
    target_ = target;
}
std::string PresidentialPardonForm::getTarget() const
{
    return target_;
}
void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
    AForm::execute(executor);
    std::cout << getTarget() << " has been pardoned by Zaphod Beeblbrox\n";
}

void PresidentialPardonForm::dummy() const {}
