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

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string msg)
{
    message_ = msg;
}

std::string Bureaucrat::GradeTooHighException::getMessage() const
{
    return (message_);
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string msg)
{
    message_ = msg;
}

std::string Bureaucrat::GradeTooLowException::getMessage() const
{
    return (message_);
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
        std::cerr << "Error : " << this->getName() << " has already reached the highest grade !\n";
    return *this;
}

Bureaucrat &Bureaucrat::operator--()
{
    if (this->getGrade() < 150)
        this->grade_ += 1;
    else
        std::cerr << "Error : " << this->getName() << " cannot be demoted from the lowest grade !\n";
    return *this;
}
