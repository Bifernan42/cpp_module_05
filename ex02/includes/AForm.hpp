#ifndef AFORM_HPP
# define AFORM_HPP
#include "Bureaucrat.hpp"
#include <exception>
#include <cstdlib>
class Bureaucrat;

class AForm
{
    private:
        const std::string name_;
        bool isSigned_;
        const unsigned int signGrade_;
        const unsigned int execGrade_;
    public:
        AForm();
        AForm(const std::string, const unsigned int, const unsigned int);
        AForm(const AForm &);
        AForm &operator=(const AForm &);
        virtual ~AForm();
        std::string getName() const;
        bool getStatus() const;
        unsigned int getSignGrade() const;
        unsigned int getExecGrade() const;
        class GradeTooHighException;
        class GradeTooLowException;
        void beSigned(const Bureaucrat &);
        virtual void execute(const Bureaucrat &) const;
        virtual void dummy() const = 0;
};

std::ostream &operator<<(std::ostream &, const AForm &);

class AForm::GradeTooHighException : public std::exception
{
    private:
        std::string errorMessage_;
    public:
        GradeTooHighException(const std::string);
        ~GradeTooHighException() throw();
        virtual const char *what() const throw();
};

class AForm::GradeTooLowException : public std::exception
{
    private:
        std::string errorMessage_;
    public:
        GradeTooLowException(const std::string);
        ~GradeTooLowException() throw();
        virtual const char *what() const throw();
};

#endif
