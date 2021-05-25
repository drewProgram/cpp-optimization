#include "Catch.h"
#include "../src/User.h"

TEST_CASE("User should inform your first name")
{
	User andrew("Andrew Filgueiras");

	std::string firstName = andrew.GetFirstName();

	REQUIRE("Andrew" == firstName);
}
