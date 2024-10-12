#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
#include <ostream>

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
};

class Bureaucrat::GradeTooHighException
{
    std::string message_;
    public:
        GradeTooHighException(const std::string);
        std::string getMessage() const;
};

class Bureaucrat::GradeTooLowException
{
    std::string message_;
    public:
        GradeTooLowException(const std::string);
        std::string getMessage() const;
};

std::ostream &operator<<(std::ostream &, const Bureaucrat &);

#endif
