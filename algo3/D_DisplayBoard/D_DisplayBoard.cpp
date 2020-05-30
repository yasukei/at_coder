#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

const int cColSize = 5;
const int cFigWidth = 3;

int whatNum(std::vector<std::string> displayBoard, int base_col)
{
	std::vector<std::vector<std::string>> figures =
	{
		{
			"###",
			"#.#",
			"#.#",
			"#.#",
			"###",
		},
		{
			".#.",
			"##.",
			".#.",
			".#.",
			"###",
		},
		{
			"###",
			"..#",
			"###",
			"#..",
			"###",
		},
		{
			"###",
			"..#",
			"###",
			"..#",
			"###",
		},
		{
			"#.#",
			"#.#",
			"###",
			"..#",
			"..#",
		},
		{
			"###",
			"#..",
			"###",
			"..#",
			"###",
		},
		{
			"###",
			"#..",
			"###",
			"#.#",
			"###",
		},
		{
			"###",
			"..#",
			"..#",
			"..#",
			"..#",
		},
		{
			"###",
			"#.#",
			"###",
			"#.#",
			"###",
		},
		{
			"###",
			"#.#",
			"###",
			"..#",
			"###",
		},
	};

	for (int num = 0; num < figures.size(); num++)
	{
		bool match = true;
		for (int i = 0; i < cColSize; i++)
		{
			for (int j = 0; j < cFigWidth; j++)
			{
				if (displayBoard[i][base_col + j] != figures[num][i][j])
				{
					match = false;
					break;
				}
			}
		}

		if (match)
		{
			return num;
		}
	}
	
	return -1;
}

int main()
{
	int N; // num of digits
	std::cin >> N;
	std::string dummy;
	std::getline(std::cin, dummy); // consume new line

	std::vector<std::string> displayBoard(cColSize);

	std::getline(std::cin, displayBoard[0]);
	std::getline(std::cin, displayBoard[1]);
	std::getline(std::cin, displayBoard[2]);
	std::getline(std::cin, displayBoard[3]);
	std::getline(std::cin, displayBoard[4]);

	for (int i = 0; i < N; i++)
	{
		std::cout << whatNum(displayBoard, 4 * i + 1);
	}
	
	return 0;
}
