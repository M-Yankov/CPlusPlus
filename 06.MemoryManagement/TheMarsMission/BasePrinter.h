#ifndef BASEPRINTER_h
#define BASEPRINTER_h

#include <string>
#include <mutex>

class BasePrinter
{
protected:
    std::mutex locker;
public:
    virtual void writeLine(std::string output = "", bool clearScreen = true, bool shouldSleep = false, int timeForSleepInMs = 500) = 0;
    virtual void write(std::string output = "") = 0;
};

#endif // !BASEPRINTER_h

