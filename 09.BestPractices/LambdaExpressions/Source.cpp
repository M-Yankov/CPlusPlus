#include <iostream>
#include <string>

int main()
{
    auto printSomething = [](std::string text)->void
    {
        std::printf("%s\n", text.c_str());
    };


    int mainValue = 2;
    // copy of the value
    auto lambdaWithExternal = [=]()->void
    {
        std::printf("%d\n", mainValue);
    };

    int another = 6;
    // reference
    auto lambdaChangeValue = [&]()->void
    {
        another = 129;
        std::printf("%d\n", another);
    };


    printSomething("Lambda ");
    lambdaWithExternal();
    lambdaChangeValue();
    return 0;
}