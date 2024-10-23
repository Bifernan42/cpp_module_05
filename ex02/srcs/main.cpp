#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include <exception>
#include <iostream>
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

    //ex02
        test("########## ex02 :: Constructors etc ... : ###################");
    cmsg("first we instantiance a Shrubbery object [shrub_1] :");
    ShrubberyCreationForm shrub_1("bigTarget");
    cmsg("Here is [shrub_1] target :");
    std::cout << shrub_1.getTarget() << std::endl;
    cmsg("Then we instanciate a second object, [shrub_2] using the copy constructor : ");
    ShrubberyCreationForm shrub_2(shrub_1);
    cmsg("Here is [shrub_2] target :");
    std::cout << shrub_2.getTarget() << std::endl;
    cmsg("Now let's create a third Shruberry object [shrub_3] :");
    ShrubberyCreationForm shrub_3("smallTarget");
    cmsg("Here is [shrub_2] target :");
    std::cout << shrub_3.getTarget() << std::endl;
    cmsg("Now let's assign [shrub_2] to [shrub_3] and then display [shrub_3]'s target :");
    shrub_3 = shrub_2;
    std::cout << shrub_3.getTarget() << std::endl;
    cmsg("We notice that everything works perfectly !");
    testOk(1);

    test("Polymorphism : ");
    cmsg("Now we will be testing polymorphism through the declaration of 3 AForm * pointing to derived forms");
    AForm *form_1 = new PresidentialPardonForm("target_1");
    AForm *form_2 = new ShrubberyCreationForm("target_2");
    AForm *form_3 = new RobotomyRequestForm("target_3");

    cmsg("Let's display all 3 form informations using << overload:");
    std::cout << "[form_1] : " << *form_1 << std::endl;
    std::cout << "[form_2] : " << *form_2 << std::endl;
    std::cout << "[form_3] : " << *form_3 << std::endl;
    cmsg("That is followed by the instanciation of 3 more Bureaucrats");
    Bureaucrat b1("A+", 1);
    Bureaucrat b2("B", 75);
    Bureaucrat b3("C", 150);
    cmsg("Here are the Bureaucrats infos :");
    std::cout << b1 << std::endl;
    std::cout << b2 << std::endl;
    std::cout << b3 << std::endl;
    cmsg("Now let's try to call the execute member function to check that polymorphism works properly :");
    form_1->execute(b1);
    cmsg("since the form_1 * (pointer) points to a PresidentialPardonForm object, we can see that polymorphism works properly");
    testOk(1);

    test("Executing 3 different forms with top-grade Bureaucrat");
    try {
        b1.executeForm(*form_1);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try {
            b1.executeForm(*form_2);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try {
            b1.executeForm(*form_3);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    testOk(1);

    test("Executing 3 different forms with mid-grade Bureaucrat, this time using [shrub_3] to prove that we get 2 files and that execute is working properly");
    try {
            b2.executeForm(*form_1);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try {
            b2.executeForm(shrub_3);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try {
        b2.executeForm(*form_3);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    testOk(1);

    test("Executing 3 different forms with low-grade Bureaucrat");
    try {
            b3.executeForm(*form_1);
    }
    catch (std::exception &e)
    {
            std::cout << e.what() << std::endl;
    }
    try {
            b3.executeForm(*form_2);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try {
        b3.executeForm(*form_3);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    testOk(1);

    test("Randomness");
    cmsg("Lastly, let's see if Robotomy's randomness is implemented correctly :");
    for (int i = 0 ; i < 100 ; ++i)
    {
        b1.executeForm(*form_3);
    }
    cmsg("Just run the command : <./forms.exe | grep failed | wc -l> the result should be around 50");
    testOk(1);
    delete form_1;
    delete form_2;
    delete form_3;
    return (0);
}
