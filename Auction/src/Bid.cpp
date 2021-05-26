#include <iostream>
#include "Bid.h"

Bid::Bid(User user, float value): user(user), value(value)
{
}

//Bid::Bid(const Bid& anotherBid) 
//    : user(anotherBid.user), value(anotherBid.value)
//{
//    std::cout << "Executing copy of bid of value " << value << std::endl;
//}

float Bid::GetValue() const
{
    return value;
}

std::string Bid::GetUsername() const
{
    return user.GetName();
}
