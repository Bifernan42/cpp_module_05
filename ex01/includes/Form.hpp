#ifndef FORM_HPP
# define FORM_HPP
# include "Bureaucrat.hpp"
#include <exception>

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
        bool getStatus();
        unsigned int getSignGrade() const;
        unsigned int getExecGrade() const;
        class GradeTooHighException;
        class GradeTooLowException;
        void beSigned(const Bureaucrat &);
};

std::ostream &operator<<(std::ostream &, const Form &)


#endif
