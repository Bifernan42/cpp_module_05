#ifndef FORM_HPP
# define FORM_HPP
#include "Bureaucrat.hpp"
#include <exception>

class Bureaucrat;

class Form
{
    private:
        const std::string name_;
        bool isSigned_;
        const unsigned int signGrade_;
        const unsigned int execGrade_;
    public:
        Form();
        Form(const std::string, const unsigned int, const unsigned int);
        Form &operator=(const Form &);
        ~Form();
        std::string getName() const;
        bool getStatus() const;
        unsigned int getSignGrade() const;
        unsigned int getExecGrade() const;
        class GradeTooHighException;
        class GradeTooLowException;
        void beSigned(const Bureaucrat &);
};

std::ostream &operator<<(std::ostream &, const Form &);

class Form::GradeTooHighException : public std::exception
{
    private:
        std::string errorMessage_;
    public:
        GradeTooHighException(const std::string);
        ~GradeTooHighException() throw();
        virtual const char *what() const throw();
};

class Form::GradeTooLowException : public std::exception
{
    private:
        std::string errorMessage_;
    public:
        GradeTooLowException(const std::string);
        ~GradeTooLowException() throw();
        virtual const char *what() const throw();
};

#endif
