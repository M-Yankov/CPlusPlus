#include "ConsolePrinter.h"

ConsolePrinter::ConsolePrinter()
{
}

ConsolePrinter::~ConsolePrinter()
{
}

void ConsolePrinter::writeLine(std::string output, bool clearScreen)
{
    this->locker.lock();
    if (clearScreen)
    {
        std::system("cls");
    }

    // TODO: should wait and for how long
    //  _sleep(w);
    std::cout << output << std::endl;
    this->locker.unlock();
}

void ConsolePrinter::write(std::string output)
{
    this->locker.lock();
    std::cout << output;
    this->locker.unlock();
}
