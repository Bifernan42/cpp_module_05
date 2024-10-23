#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include <fstream>

class ShrubberyCreationForm : public AForm
{
    private:
        std::string target_;
        void dummy() const;
    public:
        ShrubberyCreationForm(std::string);
        ShrubberyCreationForm(const ShrubberyCreationForm &);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &);
        ~ShrubberyCreationForm();
        void setTarget(const std::string);
        std::string getTarget() const;
        void execute(const Bureaucrat &) const;
};

#endif
