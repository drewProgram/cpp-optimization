#include <iostream>
#include <string>
#include <memory>
#include "User.h"

 overloading new operator to watch when something is allocated on heap
void* operator new(size_t bytes)
{
	std::cout << "Allocating " << bytes << " bytes" << std::endl;
	return malloc(bytes);
}

void PrintName(std::string_view name)
{
	std::cout << name << std::endl;
}

void PrintUserName(std::shared_ptr<User> user)
{
	std::cout << user->GetName() << std::endl;
}

int main()
{
	std::cout << "--------------" << std::endl;
	// small strings are allocated on stack (Small String Optimization)

	std::string couple = "Andrew Galvão Las Casas Filgueiras Guimarães & Lorena Moeller da Silva";
	//std::string myName = couple.substr(0, couple.find('&') - 1);
	
	// string_view is a pointer to the start of a string address and an int with the number of bytes
	// this type is available only after C++ 17
	
	// c_str returns a pointer to a char
	// when u need just to show a string, consider using string_view as it doesn't allocated anything in the stack
	std::string_view myName(couple.c_str(), couple.find('&') - 1);
	std::string_view herName(couple.c_str() + couple.find('&') + 2);

	PrintName(myName);
	PrintName(herName);
	PrintName("Blablablabla");

	// allocating User on heap with smart pointers (unique_ptr)
	// make_unique assures the allocation is valid
	//std::unique_ptr<User> user = std::make_unique<User>(new User("Andrew"));

	// Shared pointers only call the delete function when the last reference to the pointer copy
	// have it's scope ended

	// allocating User on heap with shared_ptr (with shared u can have pointer copies)
	// with shared pointers u can't use the new keyword
	std::shared_ptr<User> user = std::make_shared<User>(User("Andrew"));

	PrintUserName(user);

	return 0;
}