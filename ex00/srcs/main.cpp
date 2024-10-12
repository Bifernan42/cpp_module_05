#include "../includes/Bureaucrat.hpp"
#include <mutex>

int main(void)
{
    try {
        Bureaucrat("Hervé", 0);
    }
    catch (Bureaucrat::GradeTooHighException h)
    {
        std::cerr << h.getMessage();
    }
    catch (Bureaucrat::GradeTooLowException l)
    {
        std::cerr << l.getMessage();
    }

}
