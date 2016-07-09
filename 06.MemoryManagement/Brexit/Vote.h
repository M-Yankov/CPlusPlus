#pragma once

#include <string>
#include <iostream>

#include "VoteStatus.h"
#include "GenderType.h"
#include "EthnosType.h"

namespace Brexit
{
	class Vote
	{
	private:		
		/// <summary>
		/// Leave Or Stay
		/// </summary>
		bool status;
		unsigned int age;
		std::string name;
		std::string city;
		GenderType gender;
		EthnosType ethnos;
	public:
		Vote(VoteStatus status, std::string name, std::string city, GenderType gender, EthnosType ethnos, unsigned int age);
		~Vote();
		bool getStatus() const;
		std::string getName();
		std::string getCity();
		GenderType getGender();
		EthnosType getEthnos();
		unsigned int getAge();
	};
}
