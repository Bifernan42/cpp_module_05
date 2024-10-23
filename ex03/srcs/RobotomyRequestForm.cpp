#include "../includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45)
{
    if (target.empty())
        {
            std::cerr << "\033[34;2mRRF : Warning : provided empty target !\033[0m\n";
            setTarget("default_target");
        }
    else
            setTarget(target);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other): AForm(other), target_(other.getTarget()){}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this != &other)
    {
        setTarget(other.getTarget());
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(){}


void RobotomyRequestForm::setTarget(const std::string target)
{
    target_ = target;
}
std::string RobotomyRequestForm::getTarget() const
{
    return target_;
}
void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
    AForm::execute(executor);
    std::cout << "\033[35;12mRRF : * drilling noise *\033[0m\n";
    int r = std::rand();
    if (r % 2 == 0)
        std::cout << "\033[32;12mRRF : " << "target [" << getTarget() << "] has been robotomized successfully\033[0m\n";
    else
        std::cout << "\033[35;12mRRF : " << "target [" << getTarget() << "] robotomization failed\033[0m\n";
}

void RobotomyRequestForm::dummy() const {}
