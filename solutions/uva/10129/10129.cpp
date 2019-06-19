/*
 * Yuri Niitsuma
 * 2011039023
 * https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1070
 * 10129 - Play on Words
*/

#include <iostream>
#include <vector>

#include <utility>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

// data structure to store graph edges
struct Edge
{
	int src, dest;
};

// class to represent a graph object
class Graph
{
  public:
	// An array of vectors to represent adjacency list
	vector<int> *adjList;
	vector<int> in;
	vector<int> out;

	// Constructor
	Graph(vector<Edge> const &edges, int N)
	{
		// allocate memory
		adjList = new vector<int>[N];
		in.resize(N, 0);
		out.resize(N, 0);

		// add edges to the undirected graph
		for (unsigned i = 0; i < edges.size(); i++)
		{
			int src = edges[i].src;
			int dest = edges[i].dest;

			adjList[src].push_back(dest);
			in[dest]++;
			out[src]++;
			// adjList[dest].push_back(src);
		}
	}

	~Graph()
	{
		// delete adjList;
		in.clear();
		out.clear();
	}
};

bool printAllHamiltonianPaths(Graph const &g, int v, vector<bool> visited, vector<int> &path, int N)
{
	// if all the vertices are visited, then
	// Hamiltonian path exists
	if (path.size() == N)
	{
		// print Hamiltonian path
		// for (int i : path)
		// 	cout << i << " ";
		// cout << endl;

		return true;
	}

	// Check if every edge starting from vertex v leads
	// to a solution or not
	for (int w : g.adjList[v])
	{
		// process only unvisited vertices as Hamiltonian
		// path visits each vertex exactly once
		if (!visited[w])
		{
			visited[w] = true;
			path.push_back(w);

			// check if adding vertex w to the path leads
			// to solution or not
			if (printAllHamiltonianPaths(g, w, visited, path, N))
				return true;

			// Backtrack
			visited[w] = false;
			path.pop_back();
		}
	}
	return false;
}

// main function
bool isHamiltonian(int N, vector<Edge> edges)
{
	// create a graph from edges

	Graph g(edges, N);

	set<int> inDegrees;
	set<int> outDegrees;
	set<int> startSet;

	for (int i = 0; i < N; i++)
	{
		inDegrees.insert(g.in[i]);
		outDegrees.insert(g.out[i]);
	}

	if (inDegrees.find(0) != inDegrees.end())
	{
		int count = 0;
		for (int i = 0; i < N; i++)
		{
			if (g.in[i] == 0)
				count++;
			if (count > 1)
				return false;
			startSet.insert(i);
		}
	}
	else
	{
		if (outDegrees.find(1) != outDegrees.end())
		{
			int count = 0;
			for (int i = 0; i < N; i++)
			{
				if (g.out[i] == 1)
					count++;
				if (count > 1)
					return false;
				startSet.insert(i);
			}
		}
		else
		{
			for (int i = 0; i < N; i++)
			{
				startSet.insert(i);
			}
		}
	}

	for (int start : startSet)
	{
		// add starting node to the path
		vector<int> path;
		path.push_back(start);

		// mark start node as visited
		vector<bool> visited(N);
		visited[start] = true;
		if (printAllHamiltonianPaths(g, start, visited, path, N))
			return true;
	}

	return false;
}

int main()
{
	int t, n;
	std::string input;
	std::vector<std::pair<char, char>> pares;
	std::unordered_map<char, std::vector<int>> charMap;
	std::set<char> chars;

	std::cin >> t;
	while (t--)
	{
		std::cin >> n;

		int count = 0;
		while (count < n)
		{
			std::cin >> input;
			// std::cout << input << '\n';

			// pair entrada saida

			// std::cout << input.front() << ' ' << input.back() << '\n';
			pares.push_back(std::make_pair(input.front(), input.back()));
			chars.insert(input.front());
			charMap[input.front()].push_back(count);

			count++;
		}
		// vector entrada com qual indice do no
		// for (auto &pair : pares)
		// 	std::cout << pair.first << ' ' << pair.second << '\n';

		std::vector<Edge> edges;
		for (auto &pair : pares)
		{
			for (auto &x : charMap[pair.first])
			{
				// std::cout << x << pair.first << '\t';
				// add edge com cada no adicionando a saida
				for (auto &y : charMap[pair.second])
				{
					// std::cout << y << pair.second << ' ';
					// graph.addEdge(x, y);
					// std::cout << x << ' ' << y << '\n';
					edges.push_back({x, y});
				}
				// std::cout << '\n';
			}
		}

		// se tem hamiltoniano
		if (isHamiltonian(n, edges))
			std::cout << "Ordering is possible.\n";
		else
			std::cout << "The door cannot be opened.\n";

		chars.clear();
		pares.clear();
		charMap.clear();
	}

	// "Ordering is possible.\n";
	// "The door cannot be opened.\n";

	return 0;
}