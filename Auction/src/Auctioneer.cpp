#include <iostream>
#include <algorithm>
#include "Auctioneer.h"

Auctioneer::Auctioneer()
{
	std::cout << "Creating a new auctioneer" << std::endl;
}

void Auctioneer::Evaluate(Auction auction)
{
	std::vector<Bid> bids = auction.GetBids();
	
	for (Bid bid : bids)
	{
		if (bid.GetValue() > highestValue)
		{
			highestValue = bid.GetValue();
		}
		
		if (bid.GetValue() < lowestValue)
		{
			lowestValue = bid.GetValue();
		}
	}

	// sort gets the first and last elements of an iterable and uses a function to compare the two.
	// if any function is given, it'll use the < operator to compare the two elements
	std::sort(bids.begin(), bids.end(), OrderBids);
	size_t size = bids.size() > 3 ? 3 : bids.size();
	threeHighestBids = std::vector<Bid>(bids.begin(), bids.begin() + size);
}

float Auctioneer::GetHighestValue() const
{
	return highestValue;
}

float Auctioneer::GetLowestValue() const
{
	return lowestValue;
}

std::vector<Bid> Auctioneer::GetThreeHighestBids() const
{
	return threeHighestBids;
}

bool Auctioneer::OrderBids(const Bid& bid1, const Bid& bid2)
{
	return bid1.GetValue() > bid2.GetValue();
}