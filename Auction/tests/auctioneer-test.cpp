#include <iostream>
#include "../src/Auctioneer.h"
#include "Catch.h"

/*
* ARRANGE ACT ASSERT (Triple A)
*
* 1. Arrange all necessary preconditions and inputs.
* 2. Act on the object or method under test.
* 3. Assert that the expected results have occurred.
*/

Auction AscendingOrder()
{
	Bid firstBid(User("Andrew"), 1000.0f);
	std::cout << "The user name is " << firstBid.GetUsername() << std::endl;
	Bid secondBid(User("Lorena"), 2000.0f);
	Auction auction("Predator Helios 300");
	auction.SetBid(firstBid);
	auction.SetBid(secondBid);

	return auction;
}

Auction DescendingOrder()
{
	Bid firstBid(User("Andrew"), 2000.0f);
	Bid secondBid(User("Lorena"), 1000.0f);
	Auction auction("Predator Helios 300");
	auction.SetBid(firstBid);
	auction.SetBid(secondBid);

	return auction;
}

TEST_CASE("Auctioneer")
{
	// Arrange - Given
	Auctioneer auctioneer;

	SECTION("Ordered auctions")
	{
		// GENERATE macro
		// This code will be executed for each section
		Auction auction = GENERATE(AscendingOrder(), DescendingOrder());

		SECTION("Should get highest bid of the auction")
		{
			// Act - When
			auctioneer.Evaluate(auction);

			// Assert - Then
			REQUIRE(2000.0f == auctioneer.GetHighestValue());

			/*
			* The above macro will do something like this code:
			*
			* float expectedValue = 1200.0f;
			*
			* if (expectedValue == auctioneer.GetHighestValue())
			* {
			*	 std::cout << "TEST OK" << std::endl;
			* }
			* else
			* {
			* 	 std::cout << "TEST FAILED" << std::endl;
			* }
			*/
		}

		SECTION("Should get lowest bid of the auction")
		{
			// Arrange - Given
			auctioneer.Evaluate(auction);

			// Assert - Then
			REQUIRE(1000.0f == auctioneer.GetLowestValue());
		}
	}

	SECTION("Should get the 3 highest bids")
	{
		// Arrange - Given
		Bid firstBid(User("Andrew"), 2000.0f);
		Bid secondBid(User("Lorena"), 1000.0f);
		Bid thirdBid(User("Leonardo"), 1500.0f);
		Bid fourthBid(User("Daniela"), 4000.0f);

		Auction auction("Predator Helios 300");
		auction.SetBid(firstBid);
		auction.SetBid(secondBid);
		auction.SetBid(thirdBid);
		auction.SetBid(fourthBid);

		// Act - When
		auctioneer.Evaluate(auction);

		// Assert - Then
		auto threeHighestBids = auctioneer.GetThreeHighestBids();
		REQUIRE(threeHighestBids.size() == 3);
		REQUIRE(threeHighestBids[0].GetValue() == 4000.0f);
		REQUIRE(threeHighestBids[1].GetValue() == 2000.0f);
		REQUIRE(threeHighestBids[2].GetValue() == 1500.0f);
	}
}
