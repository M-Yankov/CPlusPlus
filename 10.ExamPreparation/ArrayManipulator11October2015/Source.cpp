#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <set>
#include <algorithm> 

//std::vector<std::string> parseCommand(std::string input);
//std::vector<int> parseArray(std::string input);
//void exchange(int index, std::vector<int> & numbers);
//void printNumbersInArrayFormat(std::vector<int> & numbers);
//void findMinMaxEvenOdd(std::vector<std::string> & commandParts,std::vector<int> & numbers);
//void findFirstLastEvenOddNumbers(std::vector<std::string>& commandParts, std::vector<int> numbers);
//

std::vector<int> parseArray(std::string input)
{
    std::vector<int> values;
    int n;
    std::stringstream stream(input);
    while (stream >> n)
    {
        values.push_back(n);
    }

    return values;
}

std::vector<std::string> parseCommand(std::string input)
{
    std::vector<std::string> values;
    std::string n;
    std::stringstream stream(input);
    while (stream >> n)
    {
        values.push_back(n);
    }

    return values;
}

void printNumbersInArrayFormat(std::vector<int> & numbers)
{
    std::cout << "[";

    int indexLastElement = numbers.size() - 1;
    int currentIndex = 0;
    for (std::vector<int>::iterator iterator = numbers.begin(); iterator != numbers.end(); iterator++, currentIndex++)
    {
        if (currentIndex == indexLastElement)
        {
            std::cout << *iterator;
        }
        else
        {
            std::cout << *iterator << ", ";
        }
    }

    std::cout << "]" << std::endl;
}

void findMinMaxEvenOdd(std::vector<std::string>& commandParts, std::vector<int>& numbers)
{
    if (numbers.size() == 0)
    {
        std::cout << "No matches" << std::endl;
    }

    std::vector<int>::iterator iter = numbers.begin();
    int indexOfMin = 0;
    int indexOfMax = 0;

    int currentMin = 10000;
    int currentMax = -1;

    bool isEven = commandParts[1] == "even";

    int currentIndex = 0;
    for (; iter != numbers.end(); iter++, currentIndex++)
    {
        if (currentMin >= *iter)
        {
            if (isEven && *iter % 2 == 0)
            {
                currentMin = *iter;
                indexOfMin = currentIndex;
            }
            else if (!isEven && *iter % 2 == 1)
            {
                currentMin = *iter;
                indexOfMin = currentIndex;
            }
        }

        if (currentMax <= *iter)
        {
            if (isEven && *iter % 2 == 0)
            {
                currentMax = *iter;
                indexOfMax = currentIndex;
            }
            else if (!isEven && *iter % 2 == 1)
            {
                currentMax = *iter;
                indexOfMax = currentIndex;
            }
        }
    }

    if (commandParts[0] == "min")
    {
        if (currentMin == 10000)
        {
            std::cout << "No matches" << std::endl;
        }
        else
        {
            std::cout << indexOfMin << std::endl;
        }
    }
    else
    {
        if (currentMax == -1)
        {
            std::cout << "No matches" << std::endl;
        }
        else
        {
            std::cout << indexOfMax << std::endl;
        }
    }
}

void findFirstLastEvenOddNumbers(std::vector<std::string>& commandParts, std::vector<int> numbers)
{
    std::vector<int> result;
    std::vector<int>::iterator begin;
    std::vector<int>::iterator end;

    bool isFirst = commandParts[0] == "first";
    bool isEven = commandParts[2] == "even";
    int count = stoi(commandParts[1]);

    if (numbers.size() < count)
    {
        std::cout << "Invalid count" << std::endl;
        return;
    }


    // wrong logic;
    if (isFirst)
    {
        begin = numbers.begin();
        end = numbers.end();
    }
    else
    {
        begin = numbers.end();
        begin--;
        end = numbers.begin();
    }

    for (; begin != end && numbers.size() > 1;)
    {
        if (count == result.size())
        {
            break;
        }

        if (isEven && *begin % 2 == 0)
        {
            result.push_back(*begin);
        }
        else if (!isEven && *begin % 2 == 1)
        {
            result.push_back(*begin);
        }

        if (isFirst)
        {
            begin++;
        }
        else
        {
            begin--;

            if (count == result.size())
            {
                break;
            }

            if (begin == end && !isEven && *begin % 2 == 1)
            {
                result.push_back(*begin);

                if (!isFirst)
                {
                    std::reverse(result.begin(), result.end());
                }

                printNumbersInArrayFormat(result);
                return;
            }
        }
    }

    if (!isFirst)
    {
        std::reverse(result.begin(), result.end());
    }

    printNumbersInArrayFormat(result);
}

void exchange(int index, std::vector<int> & numbers)
{
    if (index >= numbers.size())
    {
        std::cout << "Invalid index" << std::endl;
        return;
    }

    if (index == numbers.size() - 1 && numbers.size() > 0)
    {
        return;
    }

    std::vector<int> newNumbers;

    for (int i = index + 1; i < numbers.size(); i++)
    {
        newNumbers.push_back(numbers[i]);
    }

    for (int i = 0; i <= index; i++)
    {
        newNumbers.push_back(numbers[i]);
    }

    numbers = newNumbers;
}

int main()
{
    std::string input;
    std::getline(std::cin, input);
    std::vector<int> numbers = parseArray(input);

    while (true)
    {
        std::getline(std::cin, input);
        std::vector<std::string> commandParts = parseCommand(input);
        if (commandParts[0] == "end")
        {
            break;
        }
        else if (commandParts[0] == "exchange")
        {
            exchange(std::stoi(commandParts[1]), numbers);
        }
        else if (commandParts[0] == "min" || commandParts[0] == "max")
        {
            findMinMaxEvenOdd(commandParts, numbers);
        }
        else if (commandParts[0] == "first" || commandParts[0] == "last")
        {
            findFirstLastEvenOddNumbers(commandParts, numbers);
        }
    }

    printNumbersInArrayFormat(numbers);
    return 0;
}
