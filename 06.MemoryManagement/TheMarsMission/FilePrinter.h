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
    ~FilePrinter();

    // Inherited via BasePrinter
    virtual void writeLine(std::string output = "") override;
    virtual void write(std::string output = "") override;
};

#endif // !FILEPRINTER_h