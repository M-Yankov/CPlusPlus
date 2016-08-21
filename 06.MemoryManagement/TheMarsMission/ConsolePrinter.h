#ifndef CONSOLEPRINTER_h
#define CONSOLEPRINTER_h

#include <iostream>

#include "BasePrinter.h"

class ConsolePrinter : public BasePrinter
{
public:
    ConsolePrinter();
    ~ConsolePrinter();

    // Inherited via BasePrinter
    virtual void writeLine(std::string output = "", bool clearScreen = true) override;
    virtual void write(std::string output = "") override;
};

#endif // !CONSOLEPRINTER_h