#include "Bid.h"

Bid::Bid(User user, float value): user(user), value(value)
{
}

float Bid::GetValue() const
{
    return value;
}

std::string Bid::GetUsername() const
{
    return user.GetName();
}
