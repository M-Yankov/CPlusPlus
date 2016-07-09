#pragma once

#include <map>
#include <memory>
#include <list>
#include <sstream>
#include <iostream>
#include <algorithm>

#include "Vote.h"
#include "StayFilter.h"

namespace Brexit
{
	class VoteCollection
	{
	private:
		std::map<std::string, std::list<std::shared_ptr<Vote>>> voteByNames;
		std::map<std::string, std::list<std::shared_ptr<Vote>>> voteByCity;
		std::map<GenderType, std::list<std::shared_ptr<Vote>>> voteByGender;
		std::map<EthnosType, std::list<std::shared_ptr<Vote>>> voteByEthnos;
		std::map<unsigned int, std::list<std::shared_ptr<Vote>>> voteByAge;
		std::list< std::shared_ptr<Vote>> allVotes;
		bool isForStay(std::shared_ptr<Vote> vote);

		const char * GenderStringEnums[2] = { "Man" , "Women" };
		const char * EthnosStringEnums[5] = { "British", "Scottish", "England", "Ireland","Other" };
	public:
		VoteCollection();
		~VoteCollection();
		void addVote(Vote * vote);
		std::string votesByName(std::string name);
		std::string votesByAge(unsigned int age);
		std::string votesByGender(GenderType gender);
		std::string votesByEthnos(EthnosType ethnos);
		std::string getByCity(std::string cityName);
		std::string getResultsInNumbers();
		std::string getResultsInPercents();
	};
}
