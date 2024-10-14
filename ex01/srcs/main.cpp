#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"
#include <exception>
#include <iostream>
#include <mutex>
#include <ostream>

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

    //ex01
    /////////////////////////////////////////////////////////////////////////////
    test("Forms exceptions handling...");
    cmsg("The logic is the same as before");
    try{
        Form test("test form", 0, 160);
    }
    catch (std::exception &e1)
    {
        cmsg("catch's parameter should match the type of exception thrown\nWe pass it by reference to avoid object slicing.");
        std::cerr << e1.what();
        testOk(0);
    }
    try {
        cmsg("We can instanciate an object with the same identifier as the one before since it wasn't able to construct itself properly");
        Form test("test form", 1, 160);
    }
    catch (std::exception e2)
    {
        std::cerr << e2.what();
        testOk(0);
        cmsg("\nSince we didn't pass e2 by reference, object slicing occured and we obtained standard message\n");
    }
    testOk(1);


    /////////////////////////////////////////////////////////////////////////////
    test("forms constructors, overloads etc...");
    cmsg("Here we basically perform the same basic tests as before \nwhile also checking the stream insertion overload <<");
    Form f1("first form of the day", 3, 5);
    Form f2(f1);
    Form f3("third form of the day", 76, 88);
    std::cout << "[f1] " << f1 << std::endl;
    std::cout << "[f2] " << f2 << std::endl;
    std::cout << "[f3] " <<f3 << std::endl;
    cmsg("assignign f2 to f3 : nothing should happen");
    f3 = f2;
    std::cout << "[f3] " << f3 << std::endl;
    testOk(1);


    /////////////////////////////////////////////////////////////////////////////
    test("Form's getter functions...");
    std::cout << "[f3] exec grade = " << f3.getExecGrade() << std::endl;
    std::cout << "[f3] sign grade = " << f3.getSignGrade() << std::endl;
    std::cout << "[f3] name       = " << f3.getName() << std::endl;
    std::cout << "[f3] status     = " << f3.getStatus() << std::endl;
    testOk(1);

    /////////////////////////////////////////////////////////////////////////////
    test("Bureaucrats & Forms interaction...");
    cmsg("Bureaucrat [k][75] tries to sign form [f1][3][5], this should throw an exception !");
    std::cout << "[f1] status     = " << f1.getStatus() << std::endl;
    try{
        k.signForm(f1);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what();
        testOk(0);
    }
    cmsg("Let's try with someone more competent :");
    Bureaucrat b("Boss", 1);
    b.signForm(f1);
    std::cout << "[f1] status     = " << f1.getStatus() << std::endl;
    testOk(1);
    return (0);
}
