/*
 * Yuri Niitsuma
 * 2011039023
 * https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1112
 * 10171 - Meeting Prof. Miguel...
*/

#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
// #include <cassert>

class Graph
{
  private:
	int n;
	std::vector<std::vector<int>> edges;

  public:
	Graph(int n);
	~Graph();
	void addEdge(char dir, int u, int v, int w);
	void addEdge(char dir, char city1, char city2, int w);
	void floydWarshall();
	int getWeight(int u, int v);
	int getWeight(char city1, char city2);
	int getWeight(char city1, int v);
	void printEdges();
};

Graph::Graph(int n)
{
	this->n = n;
	this->edges.resize(n, std::vector<int>(n, std::numeric_limits<int>::max()));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			this->edges[i][j] = i == j ? 0 : std::numeric_limits<int>::max();
	// this->edges[i][j] = std::numeric_limits<int>::max();
}

Graph::~Graph()
{
	// clear vectors
	for (auto &edge : edges)
		edge.clear();
	edges.clear();
}

void Graph::addEdge(char dir, int u, int v, int w)
{
	switch (dir)
	{
	case 'B':
		w = std::min(w, edges[v - 1][u - 1]);
		w = std::min(w, edges[u - 1][v - 1]);
		edges[v - 1][u - 1] = w;
	case 'U':
		w = std::min(w, edges[u - 1][v - 1]);
		edges[u - 1][v - 1] = w;
		break;
	default:
		break;
	}
}

void Graph::addEdge(char dir, char city1, char city2, int w)
{
	int u = int(city1) - int('A') + 1;
	int v = int(city2) - int('A') + 1;
	// assert(u > 0);
	// assert(u <= 26);
	// assert(v > 0);
	// assert(v <= 26);
	this->addEdge(dir, u, v, w);
}

int Graph::getWeight(int u, int v)
{
	// assert(u > 0);
	// assert(u <= 26);
	// assert(v > 0);
	// assert(v <= 26);
	return edges[u - 1][v - 1];
}

int Graph::getWeight(char city1, char city2)
{
	int u = int(city1) - int('A') + 1;
	int v = int(city2) - int('A') + 1;
	return this->getWeight(u, v);
}

int Graph::getWeight(char city1, int v)
{
	int u = int(city1) - int('A') + 1;
	return this->getWeight(u, v);
}

void Graph::floydWarshall()
{
	int max_value = std::numeric_limits<int>::max();
	for (int k = 0; k < n; ++k)
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (edges[i][k] != max_value && edges[k][j] != max_value)
					this->edges[i][j] = std::min(edges[i][j], (edges[i][k] + edges[k][j]));
}

bool sortByDist(const std::pair<char, int> &a,
				const std::pair<char, int> &b)
{
	return (a.second < b.second);
}

void Graph::printEdges()
{
	for (auto &edge : edges)
	{
		for (auto &weight : edge)
			if (weight == std::numeric_limits<int>::max())
				std::cout << "MAX" << '\t';
			else
				std::cout << weight << '\t';
		std::cout << '\n';
	}
}

main()
{
	int n;
	char age, dir, city1, city2, initCity1, initCity2;
	int dist;

	std::vector<std::pair<char, int>> results;

	std::string listCities = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int manyCities = listCities.size();
	// assert(manyCities == 26);

	// int count = 1;

	while (std::cin >> n)
	{
		if (n == 0)
			break;
		// if (count++ != 1)
		// std::cout << '\n';

		Graph graphYoung(manyCities);
		Graph graphOld(manyCities);

		while (n--)
		{
			std::cin >> age >> dir >> city1 >> city2 >> dist;
			if (age == 'Y')
				graphYoung.addEdge(dir, city1, city2, dist);
			else
				graphOld.addEdge(dir, city1, city2, dist);
		}

		graphOld.floydWarshall();
		graphYoung.floydWarshall();

		// graphOld.printEdges();
		// graphYoung.printEdges();

		std::cin >> initCity1 >> initCity2;

		for (int i = 1; i <= manyCities; i++)
		{
			int dist1 = graphYoung.getWeight(initCity1, i);
			int dist2 = graphOld.getWeight(initCity2, i);
			if (dist1 != std::numeric_limits<int>::max() && dist2 != std::numeric_limits<int>::max())
				results.push_back(std::make_pair(char(i + int('A') - 1), dist1 + dist2));
		}

		if (results.size() > 0)
		{
			std::sort(results.begin(), results.end(), sortByDist);

			// std::cout << "DEBUG:";
			// for (auto &result : results)
			// 	std::cout << ' ' << result.second;
			// std::cout << '\n';

			int min_value = results[0].second;
			std::cout << min_value;

			std::sort(results.begin(), results.end());
			for (auto &result : results)
				if (result.second == min_value)
					std::cout << ' ' << result.first;
			results.clear();
		}
		else
		{
			std::cout << "You will never meet.";
		}

		// std::cout << city1 << ' ' << city2 << '\n';
		std::cout << '\n';

	} // end of while n

	return 0;
}
