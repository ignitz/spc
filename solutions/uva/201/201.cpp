/*
 * Yuri Niitsuma
 * 2011039023
 * https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=137
 * 201 - Squares
*/

#include <iostream>
#include <set>
#include <unordered_map>
#include <utility>

typedef std::pair<int, int> pairs;

class Graph
{
  private:
	int n;
	std::unordered_map<char, std::set<pairs>> edges;

  public:
	Graph(int n);
	~Graph();
	void addEdge(char dir, int u, int v);
	bool haveSquare(int u, int v, int size);
	bool edgeExists(char dir, int u, int v);
	int countSquares(int size);
	int getSquares(int size);
};

Graph::Graph(int n)
{
	this->n = n;
	this->edges['H'] = std::set<pairs>();
	this->edges['V'] = std::set<pairs>();
}

Graph::~Graph()
{
	this->edges['H'].clear();
	this->edges['V'].clear();
	this->edges.clear();
}

bool Graph::edgeExists(char dir, int u, int v)
{
	// assert(dir == 'H' || dir == 'V');
	pairs pairToCompare = std::make_pair(u, v);
	return this->edges[dir].find(pairToCompare) != this->edges[dir].end();
}

void Graph::addEdge(char dir, int u, int v)
{
	// assert(dir == 'H' || dir == 'V');
	pairs pairToInsert = std::make_pair(u, v);
	this->edges[dir].insert(pairToInsert);
}

bool Graph::haveSquare(int u, int v, int size)
{
	int n = this->n;
	for (int i = 0; i < size; i++)
	{
		if (!this->edgeExists('H', u, v + i) || !this->edgeExists('H', u + size, v + i))
			return false;
		if (!this->edgeExists('V', v, u + i) || !this->edgeExists('V', v + size, u + i))
			return false;
	}
	return true;
}

int Graph::countSquares(int size)
{
	int numSquare = (size - 1) * (size - 1);
	int count = 0;
	int x_limit = this->n - size;
	int y_limit = this->n - size;

	for (int j = 1; j <= x_limit; j++)
	{
		for (int i = 1; i <= y_limit; i++)
		{
			// std::cout << i << '\t' << j << '\n';
			if (this->haveSquare(i, j, size))
				count++;
		}
	}
	return count;
}

int maratona()
{
	int n, m;
	char dir;
	int u, v;

	bool check = false;
	int count = 1;

	int res; // response

	while (std::cin >> n)
	{
		if (count & 0xFFFFFE)
			std::cout << "\n**********************************\n\n";
		std::cout << "Problem #" << count++ << "\n\n";
		std::cin >> m;

		{
			// pra garantir a desalocação do Graph
			Graph graph(n);

			// change to u v instead i,j because i use this var to indexes context
			for (int i = 1; i <= m; i++)
			{
				std::cin >> dir >> u >> v;
				// assert(dir == 'H' || dir == 'V');
				// assert(u >= 1 && u <= n);
				// assert(v >= 1 && v <= n - 1);
				graph.addEdge(dir, u, v);
			}

			for (int j = 1; j < n; j++)
			{
				// check square size j
				res = graph.countSquares(j);
				if (res > 0)
				{
					std::cout << res << " square (s) of size " << j << '\n';
					check = true;
				}
			}

			if (!check)
			{
				std::cout << "No completed squares can be found." << '\n';
			}
			check = false;
		}
	}

	return 0;
}

int main(int argc, char const *argv[])
{
	maratona();
	return 0;
}
