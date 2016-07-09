#include "VoteGenerator.h"

using namespace Brexit;

VoteGenerator::VoteGenerator(VoteCollection & votes, unsigned int initialVotes)
{
	std::srand(time(0));
	std::cout << "Loading data";

	for (int i = 0; i < initialVotes; i++)
	{
		int voteStatus = this->getRandomNumber(0, 1, true);
		int cityIndex = this->getRandomNumber(0, this->cities.size());
		int nameIndex = this->getRandomNumber(0, this->names.size());
		int genderIndex = this->getRandomNumber(1, 2, true);
		int ethnosTypeIndex = this->getRandomNumber(1, 5, true);
		int age = this->getRandomNumber(18, 22, true);

		auto citiesIterator = this->cities.begin();
		std::advance(citiesIterator, cityIndex);

		auto namesIterator = this->names.begin();
		std::advance(namesIterator, nameIndex);

		votes.addVote(new Vote((VoteStatus)voteStatus,  *namesIterator, *citiesIterator, (GenderType)genderIndex, (EthnosType)ethnosTypeIndex, age));

		if (i % 1500 == 0)
		{
			std::cout << ".";
		}
	}

	std::cout << "\n";
}

int VoteGenerator::getRandomNumber(int min, int max, bool includeMax)
{
	return std::rand() % ((max - min) + includeMax) + min;
}

VoteGenerator::~VoteGenerator()
{
	std::cout << "-- Generator" << std::endl;
}
