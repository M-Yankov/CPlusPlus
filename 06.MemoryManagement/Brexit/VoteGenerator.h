#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <list>

#include "VoteCollection.h"

namespace Brexit
{
	class VoteGenerator
	{
	private:
		int getRandomNumber(int min, int max, bool includeMax = false);

		// std::list<GenderType> genders = { GenderType::Man, GenderType::Women };
		// std::list<EthnosType> ethnoses = { EthnosType::British, EthnosType::England, EthnosType::Ireland, EthnosType::Other, EthnosType::Scottish };

		std::list<std::string> cities = { "London", "Manchester", "Newcastle", "Liverpool", "Leeds", "Oxford", "Bristol" };
		std::list<std::string> names = { "George", "John", "Jason", "Patrick", "Backbone", "Bercamp", "Jessica", "Claire", "Marie", "Sher" ,"Anson", "Merry" };
	public:
		VoteGenerator(VoteCollection & votes, unsigned int initialVotes);
		~VoteGenerator();
	};
}

