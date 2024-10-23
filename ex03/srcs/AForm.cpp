#include "../includes/AForm.hpp"
#include "../includes/AForm.hpp"
#include <string>

AForm::AForm(): name_("noname"), isSigned_(false), signGrade_(1), execGrade_(1) {}
//test if it works well with non constant parameters
AForm::AForm(const std::string name, const unsigned int signGrade, const unsigned int execGrade) :
name_(name), isSigned_(false), signGrade_(signGrade), execGrade_(execGrade)
{
    if (this->getSignGrade() < 1)
    {
        throw AForm::GradeTooHighException("\033[31mError: AForm : sign grade too high !\033[0m\n");
    }
    else if (this->getSignGrade() > 150)
    {
        throw AForm::GradeTooLowException("\033[31mError: AForm: sign grade too Low !\033[0m\n");
    }
    if (this->getExecGrade() < 1)
    {
        throw AForm::GradeTooHighException("\033[31mError: AForm : exec grade too high !\033[0m\n");
    }
    else if (this->getExecGrade() > 150)
    {
        throw AForm::GradeTooLowException("\033[31mError: AForm: exec grade too Low !\033[0m\n");
    }
}

AForm::AForm(const AForm &other): name_(other.getName()), isSigned_(other.getStatus()), signGrade_(other.getSignGrade()), execGrade_(other.getExecGrade()) {}

AForm &AForm::operator=(const AForm &)
{
    return *this;
}

AForm::~AForm() {};

std::string AForm::getName() const
{
    return (name_);
}

bool AForm::getStatus() const
{
    return (isSigned_);
}

unsigned int AForm::getSignGrade() const
{
    return (signGrade_);
}

unsigned int AForm::getExecGrade() const
{
    return (execGrade_);
}

std::ostream &operator<<(std::ostream &out, const AForm &f)
{
    out << "FORM\nID : " << f.getName() << "\nEXEC GRADE : " << f.getExecGrade() << ".\nSIGN GRADE : "
    << f.getSignGrade() << ".\nSTATUS : " << f.getStatus() << "\n";
    return out;
}

void AForm::beSigned(const Bureaucrat &b)
{
    if (getStatus() == true)
    {
        std::cout << "Form : " << getName() << " : Already signed !\n";
        return ;
    }
    if (b.getGrade() <= this->getSignGrade())
        this->isSigned_ = true;
    else
        throw AForm::GradeTooLowException("\033[31mError: AForm: cannot be signed: grade too low !\033[0m\n");
}

AForm::GradeTooHighException::GradeTooHighException(const std::string msg)
{
    errorMessage_ = msg;
}

AForm::GradeTooHighException::~GradeTooHighException() throw (){}

const char *AForm::GradeTooHighException::what() const throw()
{
    return errorMessage_.c_str();
}


AForm::GradeTooLowException::GradeTooLowException(const std::string msg)
{
    errorMessage_ = msg;
}

AForm::GradeTooLowException::~GradeTooLowException() throw (){}

const char *AForm::GradeTooLowException::what() const throw()
{
    return errorMessage_.c_str();
}

void AForm::execute(const Bureaucrat &b) const
{
    if (b.getGrade() > this->getExecGrade())
        throw AForm::GradeTooLowException("\033[31mError: AForm: cannot be executed: grade too low !\033[0m\n");
}
