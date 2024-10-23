#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
#include <exception>
# include <iostream>
#include <ostream>
//avoiding circular dependencies
class AForm;

class Bureaucrat
{
	private:
		const std::string name_;
		unsigned int grade_;
	public:
	   	class GradeTooHighException;
		class GradeTooLowException;
	    Bureaucrat();
		Bureaucrat(std::string, unsigned int);
		Bureaucrat(const Bureaucrat &);
		Bureaucrat &operator=(const Bureaucrat &);
		~Bureaucrat();
		std::string getName() const;
		unsigned int getGrade() const;
		Bureaucrat &operator++();
		Bureaucrat &operator--();
		void signForm(AForm &) const;
		void executeForm(AForm const &) const;
};

class Bureaucrat::GradeTooHighException : public std::exception
{
    private:
        std::string message_;
    public:
        GradeTooHighException(const std::string) throw();
        virtual const char *what() const throw();
        ~GradeTooHighException() throw();
};

class Bureaucrat::GradeTooLowException : public std::exception
{
    private:
        std::string message_;
    public:
        GradeTooLowException(const std::string) throw();
        virtual const char *what() const throw();
        ~GradeTooLowException() throw();
};

std::ostream &operator<<(std::ostream &, const Bureaucrat &);

#endif
