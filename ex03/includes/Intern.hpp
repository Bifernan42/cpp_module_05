#ifndef INTERN_HPP
# define INTERN_HPP
# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"

typedef AForm*(*fpointer)(const std::string &);

class Intern
{
    public:
        Intern();
        Intern(const Intern &);
        Intern &operator=(const Intern &);
        ~Intern();
        AForm *makeForm(const std::string &, const std::string &);
};

#endif
