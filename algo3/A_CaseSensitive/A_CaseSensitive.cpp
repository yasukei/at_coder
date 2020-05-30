#include <iostream>
#include <cstring>

bool iequals(const std::string& a, const std::string& b)
{
	return std::equal(a.begin(), a.end(),
		b.begin(), b.end(),
		[](char a, char b) {
			return tolower(a) == tolower(b);
		});
}

int main()
{
	std::string s;
	std::string t;

	std::cin >> s;
	std::cin >> t;

	if (strcmp(s.c_str(), t.c_str()) == 0)
	{
		std::cout << "same";
	}
	else if (iequals(s.c_str(), t.c_str()))
	{
		std::cout << "case-insensitive";
	}
	else
	{
		std::cout << "different";
	}

	return 0;
}
