#include <iostream>

#include "VoteCollection.h"
#include "VoteGenerator.h"
#include "CollectionMenuOption.h"

using namespace Brexit;

const char * SPECIAL_PASSWORD = "12344321";
const int MAX_AGE = 120;
const int MIN_AGE = 18;
const int INITIAL_VOTES_COUNT = 15000;

void addVoterInfo(VoteCollection & voteCollection, std::string ageInput);
void handleCollectorChoice(VoteCollection & voteCollection);
void printCollectorMenu();
bool getEthnosInfo(EthnosType & ethnos);
bool getGenderType(GenderType & gender);

/// <summary>
/// If you see any differences with homework requirements, please tell me in the comment.
/// Many times I cannot understand the requirements, so implement the parts that are clear for me.
/// </summary>
/// <returns>The whenever if the program has error.</returns>
int main()
{
	VoteCollection collection = VoteCollection();
	VoteGenerator * generator = new VoteGenerator(collection, INITIAL_VOTES_COUNT);
	delete generator;

	while (true)
	{
		std::string ageInput;
		std::cout << "Enter your age: ";
		std::cin >> ageInput;

		if (ageInput == SPECIAL_PASSWORD)
		{
			printCollectorMenu();
			handleCollectorChoice(collection);
		}
		else
		{
			addVoterInfo(collection, ageInput);
		}
	}

	return 0;
}

// Should be separated to small method.
void addVoterInfo(VoteCollection & voteCollection, std::string ageInput)
{
	// if you enter a string, it throws an exception.
	int age;
	age = std::stoi(ageInput);

	if (MIN_AGE > age || age > MAX_AGE)
	{
		std::cout << "Age must be a number between " << MIN_AGE << " and " << MAX_AGE << "!! " << std::endl;
		return;
	}

	std::cout << "Enter your name: ";
	std::string name;
	std::cin.clear();
	std::cin.ignore();
	std::getline(std::cin, name);

	GenderType gender;
	if (!getGenderType(gender))
	{
		return;
	}

	EthnosType ethnos;
	if (!getEthnosInfo(ethnos))
	{
		return;
	}

	std::cout << "Enter your city: ";
	std::string city;
	std::cin.clear();
	std::cin.ignore();
	std::getline(std::cin, city);

	std::cout << "Enter your vote (number):\n\t1.Stay\n\t2.Leave" << std::endl;
	std::string voteInput;
	std::cin >> voteInput;
	VoteStatus vote ;

	int voteNumber = std::stoi(voteInput);
	voteNumber--;
	switch (voteNumber)
	{
	case Brexit::Stay:
		vote = VoteStatus::Stay;
		break;
	case Brexit::Leave:
		vote = VoteStatus::Leave;
		break;
	default:
		std::cout << "Wrong vote!" << std::endl;
		return;
	}

	voteCollection.addVote(new Vote(vote, name, city, gender, ethnos, age));
	std::cout << "Vote added." << std::endl;
}

bool getEthnosInfo(EthnosType & ethnos)
{
	std::cout << "Enter your ethnos: (number) \n";
	const char * ethoses[5] = { "British", "Scottish", "England", "Ireland","Other" };
	for (size_t i = 0; i < 5; i++)
	{
		std::cout << "\t" << i + 1 << ". " << ethoses[i] << std::endl;
	}

	std::string ethnosInput;
	std::cin >> ethnosInput;

	int ethnosNumber = std::stoi(ethnosInput);

	switch (ethnosNumber)
	{
	case Brexit::British:
		ethnos = EthnosType::British;
		break;
	case Brexit::Scottish:
		ethnos = EthnosType::Scottish;
		break;
	case Brexit::England:
		ethnos = EthnosType::England;
		break;
	case Brexit::Ireland:
		ethnos = EthnosType::Ireland;
		break;
	case Brexit::Other:
		ethnos = EthnosType::Other;
		break;
	default:
		std::cout << "Wrong ethnos! " << std::endl;
		return false;
	}

	return true;
}

bool getGenderType(GenderType & gender)
{
	std::cout << "Enter your gender(number):\n\t1.Man\n\t2.Women\n";
	std::string genderInput;
	std::cin >> genderInput;

	int genderNumber = std::stoi(genderInput);
	if (genderNumber == GenderType::Man)
	{
		gender = GenderType::Man;
	}
	else if (genderNumber == GenderType::Women)
	{
		gender = GenderType::Women;
	}
	else
	{
		std::cout << "Wrong gender! " << std::endl;
		return false;
	}

	return true;
}

void printCollectorMenu()
{
	std::cout << "Collector menu:" << std::endl;
	std::cout << "1. Results in percent \n"
		"2. Results in numbers \n"
		"3. Results based on Age\n"
		"4. Results based on Name\n" 
		"5. Results based on Ethnos\n"
		"6. Results based on Living city\n"
		"7. Results based on Gender\n";
}

void handleCollectorChoice(VoteCollection & voteCollection)
{
	std::cout << "> ";
	std::string input;
	std::cin >> input;
	
	int choice = std::stoi(input);

	// cannot be inserted in switch statement , char * also doesn't work
	std::string nameInput;
	std::string cityInput;

	switch (choice)
	{
	case Brexit::ByPercent:
		std::cout << voteCollection.getResultsInPercents() << std::endl;
		break;
	case Brexit::ByNumbers:
		std::cout << voteCollection.getResultsInNumbers() << std::endl;
		break;
	case Brexit::ByAge:
		int ageEnter;
		std::cout << "Enter age: ";
		std::cin >> ageEnter;

		std::cout << voteCollection.votesByAge(ageEnter) << std::endl;
		break;
	case Brexit::ByName:
		std::cout << "Enter name: ";
		std::cin.clear();
		std::cin.ignore();
		std::getline(std::cin, nameInput);

		std::cout << voteCollection.votesByName(nameInput) << std::endl;
		break;
	case Brexit::ByEthnos:
		EthnosType ethnos;
		if (!getEthnosInfo(ethnos))
		{
			return;
		}

		std::cout << voteCollection.votesByEthnos(ethnos) << std::endl;
		break;
	case Brexit::ByLivingCity:
		std::cout << "Enter name: ";
		std::cin.clear();
		std::cin.ignore();
		std::getline(std::cin, cityInput);

		std::cout << voteCollection.getByCity(cityInput) << std::endl;
		break;
	case Brexit::ByGender:
		GenderType gender;
		if (!getGenderType(gender))
		{
			return;
		}

		std::cout << voteCollection.votesByGender(gender) << std::endl;
		break;
	default:
		std::cout << "Wrong option:" << std::endl;
		return;
	}
}