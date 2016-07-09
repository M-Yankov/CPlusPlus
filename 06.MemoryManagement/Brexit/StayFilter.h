#pragma once

#include <memory>
#include "Vote.h"

namespace Brexit
{
	struct StayFilter
	{
		bool operator()(std::shared_ptr<Vote> vote) const
		{
			return vote->getStatus() == VoteStatus::Stay;
		}
	};
}