#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name_("noname"), grade_(150) {}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade): name_(name)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException("Error : provided grade is too High!");
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException("Error : provided grade is too Low!");
    else
        grade_ = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other): name_(other.getName())
{
    this->grade_ = other.getGrade();
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat & other)
{
    if (this != &other)
    {
        this->grade_ = other.getGrade();
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const
{
    return name_;
}

unsigned int Bureaucrat::getGrade() const
{
    return grade_;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string msg) throw()
{
    message_ = msg;
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string msg) throw()
{
    message_ = msg;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return (message_.c_str());
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return (message_.c_str());
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b)
{
    out << b.getName() << ", bureaucrat grade " << b.getGrade() << ".\n";
    return out;
}

Bureaucrat &Bureaucrat::operator++()
{
    if (this->getGrade() > 1)
        this->grade_ -= 1;
    else
        throw Bureaucrat::GradeTooHighException("Error : Bureaucrat cannot be promoted: grade too high !\n");
    return *this;
}

Bureaucrat &Bureaucrat::operator--()
{
    if (this->getGrade() < 150)
        this->grade_ += 1;
    else
        throw Bureaucrat::GradeTooLowException("Error : Bureaucrat cannot be demoted :grade too low !\n");
    return *this;
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {}
