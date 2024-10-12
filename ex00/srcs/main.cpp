#include "../includes/Bureaucrat.hpp"
#include <exception>
#include <mutex>

int main(void)
{
    try {
        Bureaucrat("Hervé", 0);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what();
    }
    return (0);
}
