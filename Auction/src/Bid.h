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
    // copy constructor
    Bid(const Bid&) = default;
    // deleting copy constructor
    // Bid(const Bid&) = delete;

    float GetValue() const;
    std::string GetUsername() const;
};
