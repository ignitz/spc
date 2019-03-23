/*
 * Yuri Niitsuma
 * 2011039023
 * https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=989
 * 10048 - Audiophobia
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <limits>

/*
 Mini-Max
 O problema consiste em determinar de
 todos os caminhos possiveis entre dois
 vertices o caminho que possui a menor
 maior aresta.
*/
// void floydWarshallMiniMax()
// {
// 	for (int k = 0; k < n; ++k)
// 		for (int i = 0; i < n; ++i)
// 			for (int j = 0; j < n; ++j)
// 				graph[i][j] = std::min(graph[i][j], std::max(graph[i][k], graph[k][j]));
// }
// void floydWarshallMaxMini()
// {
// 	for (int k = 0; k < n; ++k)
// 		for (int i = 0; i < n; ++i)
// 			for (int j = 0; j < n; ++j)
// 				graph[i][j] = std::max(graph[i][j], std::min(graph[i][k], graph[k][j]));
// }
class Graph
{
  private:
	int n;
	std::vector<std::vector<int>> edges;

  public:
	Graph(int n);
	~Graph();
	void addEdge(int u, int v, int w);
	void floydWarshallMiniMax();
	void printEdges();
	int getWeightEdge(int u, int v);
};

Graph::Graph(int n)
{
	auto max = std::numeric_limits<int>::max();
	this->n = n;
	this->edges.resize(n, std::vector<int>(n, max));
	for (int i = 0; i < n; i++)
		this->edges[i][i] = 0;
}

Graph::~Graph()
{
	for (auto &edge : edges)
		edge.clear();
	edges.clear();
}

void Graph::addEdge(int u, int v, int w)
{
	edges[u - 1][v - 1] = edges[v - 1][u - 1] = std::min(edges[u - 1][v - 1], w);
}

void Graph::floydWarshallMiniMax()
{
	for (int k = 0; k < n; ++k)
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				this->edges[i][j] = std::min(edges[i][j], std::max(edges[i][k], edges[k][j]));
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

int Graph::getWeightEdge(int u, int v)
{
	return edges[u - 1][v - 1];
}

int main()
{
	int C, S, Q;
	int c1, c2, d;
	int countCase = 1;

	while (std::cin >> C >> S >> Q)
	{
		Graph graph(C);
		// std::cout << C << ' ' << S << ' ' << Q << '\n';
		if (!(C | S | Q))
			break;

		if (countCase != 1)
			std::cout << '\n';
		std::cout << "Case #" << countCase++ << '\n';

		while (S--)
		{
			std::cin >> c1 >> c2 >> d;
			graph.addEdge(c1, c2, d);
			// std::cout << c1 << ' ' << c2 << ' ' << d << '\n';
		}

		// graph.printEdges();
		// std::cout << "\n\n";

		// floydwarshall
		graph.floydWarshallMiniMax();

		// graph.printEdges();

		//queries
		while (Q--)
		{
			std::cin >> c1 >> c2;
			// std::cout << c1 << ' ' << c2 << '\n';
			int res = graph.getWeightEdge(c1, c2);
			if (res == std::numeric_limits<int>::max())
				std::cout << "no path\n";
			else
				std::cout << res << '\n';
		}
	}

	return 0;
}
