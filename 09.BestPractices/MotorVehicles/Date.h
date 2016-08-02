#ifndef DATE_h
#define DATE_h

#include <string>
#include <sstream>

/// <summary>
/// There are already date-like structure defined in c++ <ctime>, but in the tasks it wants a custom class.
/// </summary>
class Date
{
private:
    unsigned int year;
    unsigned short month;
    unsigned short day;
    void setYear(unsigned int newYear);
    void setMonth(unsigned short newMonth);
    void setDay(unsigned short newDay);
public:
    Date();
    Date(Date & date);
    Date(unsigned int dateYear, unsigned short dateMonth, unsigned short dateDay);
    ~Date();   

    /// <summary>
    /// Returns the date as string in format "dd/MM/YYYY".
    /// </summary>
    /// <returns></returns>
    std::string toString();
};
#endif // !DATE_h

