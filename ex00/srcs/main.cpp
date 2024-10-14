#include "../includes/Bureaucrat.hpp"
#include <exception>
#include <mutex>

void test(const std::string &testmsg)
{
    static int i;
    std::cout << "\n\033[34m #TEST [" << i << "] : " << testmsg << "\033[0m\n";
    i++;
}

void testOk(bool value)
{
    if (value)
        std::cout << "\033[32m[OK]\033[0m\n";
    else
        std::cout << "\033[31m[KO]\033[0m\n";
}

void cmsg(const std::string &msg)
{
    std::cout << std::endl << "\033[33m[INFO]: " << msg << "\033[0m" << std::endl;
}

int main(void)
{
    cmsg("Bureaucrats tests");


    /////////////////////////////////////////////////////////////////////////////
    test("Out of range grades 0 and 160");
    cmsg("This must fail and throw catchable exceptions with std::exception for cleaner code");
    try {
        Bureaucrat b("Boss", 0);

    }
    catch (std::exception &e)
    {
        std::cerr << e.what();
        testOk(0);
    }
    try {
    Bureaucrat s("Slave",160);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what();
        testOk(0);
    }
    testOk(1);


    /////////////////////////////////////////////////////////////////////////////
    test("Constructor, Copy Constructor, Copy Assignment Overload & Stream insertion Overload <<");
    cmsg("Constructing j out of i and assigning j to k");
    Bureaucrat i("First man", 75);
    Bureaucrat j(i);
    Bureaucrat k("third man", 12);
    std::cout << "[i] " << i << std::endl;
    std::cout << "[j] " << j << std::endl;
    std::cout << "[k] " << k << std::endl;
    k = j;
    std::cout << "[k] " << k << std::endl;
    testOk(1);



    /////////////////////////////////////////////////////////////////////////////
    test("Member Functions...");
    std::cout << k.getName() << ", has a lvl " << k.getGrade() << "grade.";
    testOk(1);



    /////////////////////////////////////////////////////////////////////////////
    test("Let's promote [i][75] 75 times using the precremement operator ++");
    cmsg("it should throw a GradeTooHighException but still promote i to grade 1");
    try {

        for (int index = 0 ; index < 75 ; ++index)
            ++i;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what();
        testOk(0);
    }
    std::cout << i;
    testOk(1);




    /////////////////////////////////////////////////////////////////////////////
    test("And now let's demote it using -- operator !");
    cmsg("it should throw a GradeTooLowException but still demote i to grade 1");
    try {
        for (int index = 0 ; index < 151 ; ++index)
            --i;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what();
        testOk(0);
    }
    std::cout << i;
    testOk(1);
    return (0);
}
