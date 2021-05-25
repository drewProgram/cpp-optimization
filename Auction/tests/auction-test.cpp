#include "Catch.h"
#include "../src/User.h"
#include "../src/Auction.h"

TEST_CASE("Auction shouldn't receive consecutive bids from the same user")
{
	// Arrange
	Auction auction("Predator Helios 300");
	User user("Andrew");

	Bid firstBid(user, 1000.0f);
	Bid secondBid(user, 2000.0f);

	// Act
	auction.SetBid(firstBid);
	auction.SetBid(secondBid);

	// Assert
	REQUIRE(auction.GetBids().size() == 1);
	REQUIRE(auction.GetBids()[0].GetValue() == 1000.0f);
}