#include "ConsolePrinter.h"



ConsolePrinter::ConsolePrinter()
{
}


ConsolePrinter::~ConsolePrinter()
{
}

void ConsolePrinter::writeLine(std::string output)
{
    std::cout << output << std::endl;
}

void ConsolePrinter::write(std::string output)
{
    std::cout << output;
}
