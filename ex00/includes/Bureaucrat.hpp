#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>

class Bureaucrat
{
	private:
		const std::string name_;
		unsigned int grade_;
	public:
		Bureaucrat();
		Bureaucrat(const std::string, unsigned int);
		Bureaucrat(const Bureaucrat &);
		Bureaucrat &operator=(const Bureaucrat &);
		~Bureaucrat();
		std::string getName();
		unsigned int getGrade();
};



#endif
