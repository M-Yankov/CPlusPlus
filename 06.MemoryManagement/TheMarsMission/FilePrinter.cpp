#include "FilePrinter.h"

FilePrinter::FilePrinter(std::string filename)
{
    fileStream.open(filename);
}

FilePrinter::~FilePrinter()
{
    fileStream.close();
}

void FilePrinter::writeLine(std::string output)
{
    fileStream << output << std::endl;
}

void FilePrinter::write(std::string output)
{
    fileStream << output;
}
