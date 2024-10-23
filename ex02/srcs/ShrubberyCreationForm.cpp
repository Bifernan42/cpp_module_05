#include "../includes/ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", 145, 137)
{
    if (target.empty())
    {
        std::cerr << "\033[34;2mSCF : Warning : provided empty target !\033[0m\n";
        setTarget("default_target");
    }
    else
        setTarget(target);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other): AForm(other),target_(other.getTarget()) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
    {
        setTarget(other.getTarget());
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

void ShrubberyCreationForm::setTarget(const std::string target)
{
    target_ = target;
}
std::string ShrubberyCreationForm::getTarget() const
{
    return target_;
}
void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
    AForm::execute(executor);
    std::string fileName = getTarget() + "_shrubbery";
    std::ofstream file(fileName.c_str(), std::ios::out | std::ios::trunc | std::ios::binary);
    if (!file)
    {
        std::cerr << "\033[31mSCF : Error : couldn't create <" << getTarget() << ">\033[0m\n";
    }
    else {
    file << "                 *\n"
            "                /|\\\n"
            "              o/*|*\\o\n"
            "              ///|\\\\\\\n"
            "            */*o/|\\o*\\*\n"
            "            /////|\\\\\\\\\\\n"
            "          ///////|\\\\\\\\\\\n"
            "                |||\n"
            "                |||\n";
    file.close();
}
}

void ShrubberyCreationForm::dummy() const {}
