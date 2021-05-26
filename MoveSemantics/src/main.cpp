#include <iostream>

class String
{
private:
	char* data;
	size_t size;

public:
	String(const char* string)
	{
		// get string size
		size = strlen(string);
		// allocate space
		data = new char[size];
		// adding null terminated char
		data[size] = 0;
		// copy data to allocated space
		memcpy(data, string, size);

		std::cout << "string created" << std::endl;
	}

	String(const String& anotherString)
	{
		// get string size
		size = strlen(anotherString.data);
		// allocate space
		data = new char[size];
		// copy data to allocated space
		memcpy(data, anotherString.data, size);

		std::cout << "Copied string" << std::endl;
	}

	String(String&& anotherString) noexcept
	{
		size = anotherString.size;
		data = anotherString.data;

		// when moving data u need to set to a invalid state the place where u got the data
		anotherString.size = 0;
		anotherString.data = nullptr;

		std::cout << "Moved string" << std::endl;
	}

	~String()
	{
		delete data;
	}
};

class User
{
private:
	String name;

public:
	User(const String& string) : name(string)
	{
	}

	// move constructor
	User(String&& string) : name(std::move (string)) // std::move (string) = (String&&) string
	{
	}
};

int main()
{
	User(String("Andrew"));

	std::cin.get();
}
