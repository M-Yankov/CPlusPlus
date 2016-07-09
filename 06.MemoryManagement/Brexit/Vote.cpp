#include "Vote.h"

using namespace Brexit;

Vote::Vote(VoteStatus voteStatus, std::string voteName, std::string voteCity, GenderType genderVote, EthnosType ethnosVote, unsigned int voterAge)
	: status(voteStatus),
	name(voteName),
	city(voteCity),
	gender(genderVote),
	ethnos(ethnosVote),
	age(voterAge)
{
}

Vote::~Vote()
{
	std::cout << "--Vote" << std::endl;
}

bool Vote::getStatus() const
{
	return this->status;
}

std::string Vote::getName()
{
	return this->name;
}

std::string Vote::getCity()
{
	return this->city;
}

GenderType Vote::getGender()
{
	return this->gender;
}

EthnosType Vote::getEthnos()
{
	return this->ethnos;
}

unsigned int Vote::getAge()
{
	return this->age;
}

