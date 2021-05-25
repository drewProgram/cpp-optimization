#pragma once

#include <string>
#include "User.h"

class Bid
{
private:
    User user;
    float value;
public:
    Bid(User user, float value);

    float GetValue() const;
    std::string GetUsername() const;
};
