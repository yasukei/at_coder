#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>

int main()
{
	int N; // length
	std::cin >> N;

	// make matrix
	std::vector<std::string> matrix(N);
	for (int i = 0; i < N; i++)
	{
		std::string dummy;
		std::getline(std::cin, dummy); // consume new line

		std::cin >> matrix[i];
	}

	if (N == 1)
	{
		std::cout << matrix[0][0];
		return 0;
	}

	std::string palindrome = "";
	for (int i = 0; i < N/2; i++)
	{
		std::set<char> upper;
		for (int j = 0; j < N; j++)
		{
			upper.insert(matrix[i][j]);
		}

		std::set<char> lower;
		for (int j = 0; j < N; j++)
		{
			lower.insert(matrix[N-1-i][j]);
		}

		std::set<char> intersection;
		std::set_intersection(
			upper.begin(), upper.end(),
			lower.begin(), lower.end(),
			std::inserter(intersection, intersection.end())
		);
		if (intersection.empty())
		{
			std::cout << -1;
			return 0;
		}

		palindrome += *(intersection.begin());
	}

	std::string reversed = "";
	for (int i = palindrome.size() - 1; i >= 0; i--)
	{
		reversed.push_back(palindrome[i]);
	}

	std::string center = "";
	if (N % 2 != 0)
	{
		center.push_back(matrix[N / 2][0]);
	}

	std::cout << palindrome << center << reversed;

	return 0;
}
