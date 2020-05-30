#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <algorithm>

int main()
{
	int N; // length of sequence
	int Q; // num of queries

	std::cin >> N >> Q;

	std::vector<int> v(N);
	for (int i = 0; i < v.size(); i++)
	{
		v[i] = i + 1;
	}

	for (int i = 0; i < Q; i++)
	{
		std::string dummy;
		std::getline(std::cin, dummy); // consume new line

		int order;
		int x;
		int y;
		std::cin >> order >> x >> y;
		x -= 1;
		y -= 1;

		if (order == 1)
		{
			std::swap(v[x], v[x + 1]);
		}
		else
		{
			std::sort(v.begin() + x, v.begin() + y + 1);
		}
	}

	for (int i = 0; i < v.size(); i++)
	{
		std::cout << v[i] << " ";
	}


	return 0;
}
