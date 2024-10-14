#include "../includes/Form.hpp"
#include "../includes/Form.hpp"
#include <string>

Form::Form(): name_("noname"), isSigned_(false), signGrade_(1), execGrade_(1) {}
//test if it works well with non constant parameters
Form::Form(const std::string name, const unsigned int signGrade, const unsigned int execGrade) :
name_(name), isSigned_(false), signGrade_(signGrade), execGrade_(execGrade)
{
    if (this->getSignGrade() < 1)
    {
        throw Form::GradeTooHighException("\033[31mError: Form : sign grade too high !\033[0m\n");
    }
    else if (this->getSignGrade() > 150)
    {
        throw Form::GradeTooLowException("\033[31mError: Form: sign grade too Low !\033[0m\n");
    }
    if (this->getExecGrade() < 1)
    {
        throw Form::GradeTooHighException("\033[31mError: Form : exec grade too high !\033[0m\n");
    }
    else if (this->getExecGrade() > 150)
    {
        throw Form::GradeTooLowException("\033[31mError: Form: exec grade too Low !\033[0m\n");
    }
}

Form &Form::operator=(const Form &)
{
    return *this;
}

Form::~Form() {};

std::string Form::getName() const
{
    return (name_);
}

bool Form::getStatus() const
{
    return (isSigned_);
}

unsigned int Form::getSignGrade() const
{
    return (signGrade_);
}

unsigned int Form::getExecGrade() const
{
    return (execGrade_);
}

std::ostream &operator<<(std::ostream &out, const Form &f)
{
    out << "FORM\nID : " << f.getName() << "\nEXEC GRADE : " << f.getExecGrade() << ".\nSIGN GRADE : "
    << f.getSignGrade() << ".\nSTATUS : " << f.getStatus() << "\n";
    return out;
}

void Form::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() <= this->getSignGrade())
        this->isSigned_ = true;
    else
        throw Form::GradeTooLowException("\033[31mError: Form: cannot be signed: grade too low !\033[0m\n");
}

Form::GradeTooHighException::GradeTooHighException(const std::string msg)
{
    errorMessage_ = msg;
}

Form::GradeTooHighException::~GradeTooHighException() throw (){}

const char *Form::GradeTooHighException::what() const throw()
{
    return errorMessage_.c_str();
}


Form::GradeTooLowException::GradeTooLowException(const std::string msg)
{
    errorMessage_ = msg;
}

Form::GradeTooLowException::~GradeTooLowException() throw (){}

const char *Form::GradeTooLowException::what() const throw()
{
    return errorMessage_.c_str();
}
