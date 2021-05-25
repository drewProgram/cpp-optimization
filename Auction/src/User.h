#pragma once

#include <string>

class User
{
private:
    std::string name;
public:
    User(std::string);
    std::string GetName() const;
    std::string GetFirstName() const;
};
