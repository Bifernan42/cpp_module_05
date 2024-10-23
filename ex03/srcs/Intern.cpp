#include "../includes/Intern.hpp"

AForm *createRobotomyRequestForm(const std::string &target)
{
    return new RobotomyRequestForm(target);
}

AForm *createPresidentialPardonForm(const std::string &target)
{
    return new PresidentialPardonForm(target);
}

AForm *createShrubberyCreationForm(const std::string &target)
{
    return new ShrubberyCreationForm(target);
}

Intern::Intern(){}

Intern::Intern(const Intern &other) {
    if (this != &other)
        return ;
}

Intern &Intern::operator=(const Intern &other)
{
    if (this == &other)
        return *this;
    return *this;
}

Intern::~Intern(){}

AForm *Intern::makeForm(const std::string &form_name, const std::string &target_name)
{
    if (form_name.empty() || target_name.empty())
    {
        std::cerr << "Intern: Error : provided string is empty !" << std::endl;
        return NULL;
    }
    AForm *form = NULL;
    std::string s[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
    fpointer f[3] = {&createRobotomyRequestForm, &createPresidentialPardonForm, &createShrubberyCreationForm};
    for (int i = 0 ; i < 3 ; i++)
    {
       if (form_name == s[i])
       {
           std::cout << "Intern creates form" << std::endl;
           form = f[i](target_name);
           return form;
       }
    }
    std::cout << "Intern : Error: form name '" << form_name << "'does not exist" << std::endl;
    return (form);
}
