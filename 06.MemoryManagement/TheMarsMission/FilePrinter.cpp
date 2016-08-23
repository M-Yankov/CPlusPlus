#include "FilePrinter.h"

FilePrinter::FilePrinter(std::string filename)
{
    fileStream.open(filename);
}

FilePrinter::FilePrinter(FilePrinter & filerPrinter)
{
}

FilePrinter::~FilePrinter()
{
    fileStream.close();
}

void FilePrinter::writeLine(std::string output, bool clearScreen, bool shouldSleep, int timeForSleepInMs)
{
    this->locker.lock();
    fileStream << output << std::endl;
    this->locker.unlock();
}

void FilePrinter::write(std::string output)
{
    this->locker.lock();
    fileStream << output;
    this->locker.unlock();
}
