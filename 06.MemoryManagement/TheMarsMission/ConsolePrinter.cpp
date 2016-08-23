#include "ConsolePrinter.h"

ConsolePrinter::ConsolePrinter()
{
}

ConsolePrinter::~ConsolePrinter()
{
}

void ConsolePrinter::writeLine(std::string output, bool clearScreen, bool shouldSleep, int timeForSleepInMs)
{
    this->locker.lock();
    if (clearScreen)
    {
        std::system("cls");
    }

    std::cout << output << std::endl;
    if (shouldSleep)
    {
        _sleep(timeForSleepInMs);
    }

    this->locker.unlock();
}

void ConsolePrinter::write(std::string output)
{
    this->locker.lock();
    std::cout << output;
    this->locker.unlock();
}
