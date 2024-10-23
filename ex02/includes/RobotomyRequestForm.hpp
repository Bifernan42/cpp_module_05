#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include <random>

class RobotomyRequestForm : public AForm
{
    private:
        std::string target_;
        void dummy() const;
    public:
        RobotomyRequestForm(std::string);
        RobotomyRequestForm(const RobotomyRequestForm &);
        RobotomyRequestForm &operator=(const RobotomyRequestForm &);
        ~RobotomyRequestForm();
        void setTarget(const std::string);
        std::string getTarget() const;
        void execute(const Bureaucrat &) const;
};

#endif
