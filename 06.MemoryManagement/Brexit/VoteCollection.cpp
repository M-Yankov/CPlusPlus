#include "VoteCollection.h"

using namespace Brexit;

VoteCollection::VoteCollection()
{
}

VoteCollection::~VoteCollection()
{
	std::cout << "---VoteCollection " << std::endl;
}

void VoteCollection::addVote(Vote * vote)
{
	std::shared_ptr<Vote> votePointer = std::shared_ptr<Vote>(vote);
	this->voteByNames[vote->getName()].push_back(votePointer);
	this->voteByAge[vote->getAge()].push_back(votePointer);
	this->voteByCity[vote->getCity()].push_back(votePointer);
	this->voteByEthnos[vote->getEthnos()].push_back(votePointer);
	this->voteByGender[vote->getGender()].push_back(votePointer);
	this->allVotes.push_back(votePointer);
}

bool VoteCollection::isForStay(std::shared_ptr<Vote> vote)
{
	return vote->getStatus() == VoteStatus::Leave;
}

std::string VoteCollection::votesByName(std::string name)
{
	int countForStay = std::count_if(
		this->voteByNames[name].begin(), 
		this->voteByNames[name].end(),
		StayFilter());

	int size = this->voteByNames[name].size();

	char buffer[100];
	sprintf(buffer, "%s - %d Stay, %d Leave\n", name.c_str(), countForStay, size - countForStay);
	return buffer;
}

std::string VoteCollection::votesByAge(unsigned int age)
{
	int countForStay = std::count_if(
		this->voteByAge[age].begin(),
		this->voteByAge[age].end(),
		StayFilter());

	int size = this->voteByAge[age].size();

	char buffer[100];
	sprintf(buffer, "%d y - %d Stay, %d Leave\n", int(age), countForStay, size - countForStay);
	return buffer;
}

std::string Brexit::VoteCollection::votesByGender(GenderType gender)
{
	int countForStay = std::count_if(
		this->voteByGender[gender].begin(),
		this->voteByGender[gender].end(),
		StayFilter());

	int size = this->voteByGender[gender].size();

	char buffer[100];
	sprintf(buffer, "Sex %s  - %d Stay, %d Leave\n", this->GenderStringEnums[gender - 1], countForStay, size - countForStay);
	return buffer;
}

std::string VoteCollection::votesByEthnos(EthnosType ethnos)
{
	int countForStay = std::count_if(
		this->voteByEthnos[ethnos].begin(),
		this->voteByEthnos[ethnos].end(),
		StayFilter());

	int size = this->voteByEthnos[ethnos].size();

	char buffer[100];
	sprintf(buffer, "Sex %s  - %d Stay, %d Leave\n", this->EthnosStringEnums[ethnos - 1], countForStay, size - countForStay);
	return buffer;
}

std::string VoteCollection::getByCity(std::string cityName)
{
	int countForStay = std::count_if(
		this->voteByCity[cityName].begin(),
		this->voteByCity[cityName].end(),
		StayFilter());

	int size = this->voteByCity[cityName].size();

	char buffer[100];
	sprintf(buffer, "City %s  - %d Stay, %d Leave\n", cityName.c_str(), countForStay, size - countForStay);
	return buffer;
}

std::string Brexit::VoteCollection::getResultsInNumbers()
{
	int countForStay = std::count_if(
		this->allVotes.begin(),
		this->allVotes.end(),
		StayFilter());

	int size = this->allVotes.size();

	char buffer[100];
	sprintf(buffer, "Numbers - %d Stay, %d Leave\n", countForStay, size - countForStay);
	return buffer;
}

std::string Brexit::VoteCollection::getResultsInPercents()
{
	int countForStay = std::count_if(
		this->allVotes.begin(),
		this->allVotes.end(),
		StayFilter());

	int size = this->allVotes.size();

	const int MAX_PERCENTAGE = 100;

	int percentageForStay = 0;
	int percentageForLeave = 0;

	if (size != 0)
	{
		percentageForStay = (countForStay * MAX_PERCENTAGE) / size;
		percentageForLeave = MAX_PERCENTAGE - percentageForStay;
	}

	char buffer[100];
	sprintf(buffer, "Percentage - %d%% Stay, %d\%% Leave\n", percentageForStay, percentageForLeave);
	return buffer;
}