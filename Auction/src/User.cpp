#include "User.h"

User::User(std::string name) : name(name)
{
}

std::string User::GetName() const
{
    return name;
}

std::string User::GetFirstName() const
{
    // substr gets a part of a string. Params: start of what u want to get; end of what u want to get
    return name.substr(0, name.find(' ')); // start of the name and end when u find a space
}
