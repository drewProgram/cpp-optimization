#include "Auction.h"

Auction::Auction(std::string description) : description(description)
{
}

const std::vector<Bid>& Auction::GetBids() const
{
    return bids;
}

void Auction::SetBid(const Bid& bid)
{
    if (bids.size() == 0 || bids.back().GetUsername() != bid.GetUsername())
    {
        bids.push_back(bid);
    }
}
