#ifndef FILEPRINTER_h
#define FILEPRINTER_h

#include <iostream>
#include <fstream>

#include "BasePrinter.h"

class FilePrinter : public BasePrinter
{
private:
    std::ofstream fileStream;
public:
    FilePrinter(std::string filename);
    FilePrinter(FilePrinter & filerPrinter);
    ~FilePrinter();

    // Inherited via BasePrinter
    virtual void writeLine(std::string output = "", bool clearScreen = true) override;
    virtual void write(std::string output = "") override;
};

#endif // !FILEPRINTER_h