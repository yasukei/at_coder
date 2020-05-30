#include <iostream>
#include <cmath>

int main()
{
	uint64_t A; // initial term
	uint64_t R; // common ratio
	uint64_t N; // Nth term

	uint64_t max = std::pow(10, 9);

	std::cin >> A >> R >> N;

	uint64_t answer = A;
	for (uint64_t i = 0; i < N-1; i++)
	{
		answer *= R;

		if (answer > max)
		{
			std::cout << "large";
			return 0;
		}
	}

	std::cout << answer;

	return 0;
}
