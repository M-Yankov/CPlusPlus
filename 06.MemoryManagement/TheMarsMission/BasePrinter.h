#ifndef BASEPRINTER_h
#define BASEPRINTER_h

#include <string>

class BasePrinter
{
public:
    virtual void writeLine(std::string output = "") = 0;
    virtual void write(std::string output = "") = 0;
};

#endif // !BASEPRINTER_h

