#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <sstream>

std::vector<std::string> splitLine(std::string line)
{
    std::vector<std::string> values;
    std::string n;
    std::stringstream stream(line);
    while (stream >> n)
    {
        values.push_back(n);
    }

    return values;
}

void cutLastSymbol(std::string & text, char symbol)
{
    if (*(text.end() - 1) == symbol)
    {
        text.erase(text.end() - 1);
    }
}

void processLine(std::set<std::string> &  ints, std::set<std::string> & doubles, std::vector<std::string> lineWords)
{
    int length = lineWords.size();
    for (int i = 0; i < length; i++)
    {
        if ((int)lineWords[i].find("int") != -1 && i + 1 < length)
        {
            cutLastSymbol(lineWords[i + 1], ';');
            cutLastSymbol(lineWords[i + 1], ')');
            ints.insert(lineWords[i + 1]);
            return;
        }

        if ((int)lineWords[i].find("double") != -1 && i + 1 < length)
        {
            cutLastSymbol(lineWords[i + 1], ';');
            cutLastSymbol(lineWords[i + 1], ')');
            doubles.insert(lineWords[i + 1]);
            return;
        }
    }
}



std::string printResults(const std::string variableType, std::set<std::string> * varNames)
{
    std::stringstream ss;
    ss << variableType << ": ";
    int length = varNames->size();

    if (length > 0)
    {
        std::set<std::string>::iterator begin = varNames->begin();
        std::set<std::string>::iterator end = varNames->end();
        auto last = end;
        last--;

        for (; begin != end; begin++)
        {
            if (begin == last)
            {
                ss << *begin;
            }
            else
            {
                ss << *begin << ", ";
            }
        }
    }
    else
    {
        ss << "None";
    }

    return ss.str();
}

int main()
{
    std::set<std::string> doubleVariablesNames;
    std::set<std::string> intVariablesNames;

    std::string input;
    while (input != "//END_OF_CODE")
    {
        std::getline(std::cin, input);
        std::vector<std::string> parts = splitLine(input);
        processLine(intVariablesNames, doubleVariablesNames, parts);
    }

    std::cout << printResults("Doubles", &doubleVariablesNames) << std::endl;
    std::cout << printResults("Ints", &intVariablesNames) << std::endl;

    return 0;
}