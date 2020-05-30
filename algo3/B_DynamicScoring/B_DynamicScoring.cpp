#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

class Problem
{
public:
	Problem() :
		_num_of_participants(0),
		_num_of_solved(0)
	{
	}

	void setNumofParticipants(int num)
	{
		_num_of_participants = num;
	}

	int getCurrentScore()
	{
		return _num_of_participants - _num_of_solved;
	}

	void solvedThisProblemBySomeone()
	{
		_num_of_solved++;
	}

private:
	int _num_of_participants;
	int _num_of_solved;
};

class Participant
{
public:
	void printScore()
	{
		int score = 0;

		std::for_each(_solved_problems.begin(), _solved_problems.end(),
			[&](Problem* p)
			{
				score += p->getCurrentScore();
			}
		);
		std::cout << std::to_string(score) << std::endl;
	}

	void solvedThisProblem(Problem* p)
	{
		_solved_problems.push_back(p);
	}

private:
	std::vector<Problem*> _solved_problems;
};

int main()
{
	int N; // num of participants 
	int M; // num of problems
	int Q; // num of queries

	std::cin >> N >> M >> Q;
	std::vector<Participant> participants(N);
	std::vector<Problem> problems(M);
	std::for_each(problems.begin(), problems.end(),
		[=](Problem& p)
		{
			p.setNumofParticipants(N);
		}
	);

	for (int i = 0; i < Q; i++)
	{
		std::string dummy;
		std::getline(std::cin, dummy); // consume new line

		int order;
		std::cin >> order;

		if (order == 1)
		{
			int n;
			std::cin >> n;
			n -= 1;
			participants[n].printScore();
		}
		else
		{
			int n;
			int m;
			std::cin >> n >> m;
			n -= 1;
			m -= 1;

			problems[m].solvedThisProblemBySomeone();
			participants[n].solvedThisProblem(&problems[m]);
		}
	}

	return 0;
}
