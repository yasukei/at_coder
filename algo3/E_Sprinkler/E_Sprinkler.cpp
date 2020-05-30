#include <iostream>
#include <sstream>
#include <vector>

int main()
{
	int N; // num of vertexes
	int M; // num of edges
	int Q; // num of queries
	std::cin >> N >> M >> Q;

	// make empty graph
	std::vector<std::vector<bool>> graph;
	graph.resize(N);
	for (int i = 0; i < graph.size(); i++)
	{
		graph[i].resize(N);
	}

	// make edges on graph
	for (int i = 0; i < M; i++)
	{
		std::string dummy;
		std::getline(std::cin, dummy); // consume new line

		int u, v;
		std::cin >> u >> v;
		u -= 1;
		v -= 1;

		graph[u][v] = true;
		graph[v][u] = true;
	}

	// paint color on vertex
	std::vector<int> vertexes(N);
	std::string dummy;
	std::getline(std::cin, dummy); // consume new line
	for (int i = 0; i < N; i++)
	{
		int color;

		std::cin >> color;

		vertexes[i] = color;
	}

	for (int i = 0; i < Q; i++)
	{
		std::string dummy;
		std::getline(std::cin, dummy); // consume new line

		int order;
		std::cin >> order;
		if (order == 1)
		{
			int x;
			std::cin >> x;
			x -= 1;

			// print color of vertex
			std::cout << vertexes[x] << std::endl;
			// invoke sprinkler
			for (int j = 0; j < graph[x].size(); j++)
			{
				if (graph[x][j])
				{
					vertexes[j] = vertexes[x];
				}
			}
		}
		else
		{
			int x, y;
			std::cin >> x >> y;
			x -= 1;

			// print color of vertex
			std::cout << vertexes[x] << std::endl;
			// overwrite color of vertex
			vertexes[x] = y;
		}
	}

	return 0;
}
