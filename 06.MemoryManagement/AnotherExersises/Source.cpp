#include <iostream>
#include <string>
#include <map>
#include <list>
#include <memory>

class VoteTest
{
public:
	inline VoteTest(bool sta) : status(sta)
	{
		std::cout << "++" << std::endl;
	};

	~VoteTest()
	{
		std::cout << "--" << std::endl;
	}

	bool status;
};


/// <summary>
/// If you see any differences with homework requirements, please tell me in the comment.
/// Many times I cannot understand the requirements, so implement the parts that are clear for me.
/// LOL - main function is complied even if it returns boolean.
/// </summary>
/// <returns>The successful or unsuccessful status.</returns>
bool main()
{
	std::map<std::string, int> tests = std::map<std::string, int>();
	tests["one"] = 1;
	tests["two"] = 2;
	tests["three"] = 3;
	tests["four"] = 4;
	tests["five"] = 5;

	std::list<std::string> texts = { 
		"one", "two", "two", "three", "four",
		"five", "three", "four", "five", "six",
		"two", "three", "four", "five" };

	for (std::list<std::string>::iterator it = texts.begin(); it != texts.end() ; it++)
	{
		tests[*it]++;
	}


	for (std::map<std::string, int>::iterator it = tests.begin(); it != tests.end(); it++)
	{
		std::cout << "[" << it->first << "] - " << it->second << std::endl;
	}

	std::map<std::string, std::list<std::auto_ptr<VoteTest>>> strangeList;

	strangeList["yes"].push_back(std::auto_ptr<VoteTest>(new VoteTest(false)));
	strangeList["yes"].push_back(std::auto_ptr<VoteTest>(new VoteTest(true)));
	strangeList["no"].push_back(std::auto_ptr<VoteTest>(new VoteTest(false)));
	strangeList["no"].push_back(std::auto_ptr<VoteTest>(new VoteTest(true)));
	strangeList["no"].push_back(std::auto_ptr<VoteTest> (new VoteTest(false)));
	
	for (auto it = strangeList.begin(); it != strangeList.end(); it++)
	{
		std::cout << it->first << " -> " << it->second.size() << std::endl;
		for (auto listIteartor = it->second.begin(); listIteartor != it->second.end(); listIteartor++)
		{
			bool status = listIteartor->get()->status;

			std::cout << "    ";
			if (status)
			{
				std::cout << "true";
			}
			else
			{
				std::cout << "false";
			}
			std::cout << std::endl;
		}
	}

	std::cout << "test" << std::endl;
	return 0;
}