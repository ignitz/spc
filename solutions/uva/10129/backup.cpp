/*
 * Yuri Niitsuma
 * 2011039023
 * https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1070
 * 10129 - Play on Words
*/

#include <iostream>
#include <list>
#include <utility>
#include <vector>
#include <unordered_map>
#include <set>

// tirei o algoritmo de caminho euleriano daqui
// https://www.geeksforgeeks.org/euler-circuit-directed-graph/

// A C++ program to check if a given directed graph is Eulerian or not
#include <iostream>
#include <list>
#define CHARS 26
using namespace std;

// A class that represents an undirected graph
class Graph
{
	int V;			// No. of vertices
	list<int> *adj; // A dynamic array of adjacency lists
	int *in;

  public:
	// Constructor and destructor
	Graph(int V);
	~Graph()
	{
		delete[] adj;
		delete[] in;
	}

	// function to add an edge to graph
	void addEdge(int v, int w)
	{
		adj[v].push_back(w);
		(in[w])++;
	}

	// Method to check if this graph is Eulerian or not
	bool isEulerianCycle();

	// Method to check if all non-zero degree vertices are connected
	bool isSC();

	// Function to do DFS starting from v. Used in isConnected();
	void DFSUtil(int v, bool visited[]);

	Graph getTranspose();
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
	in = new int[V];
	for (int i = 0; i < V; i++)
		in[i] = 0;
}

/* This function returns true if the directed graph has an eulerian 
   cycle, otherwise returns false  */
bool Graph::isEulerianCycle()
{
	// Check if all non-zero degree vertices are connected
	if (isSC() == false)
		return false;

	// Check if in degree and out degree of every vertex is same
	for (int i = 0; i < V; i++)
		if (adj[i].size() != in[i])
			return false;

	return true;
}

// A recursive function to do DFS starting from v
void Graph::DFSUtil(int v, bool visited[])
{
	// Mark the current node as visited and print it
	visited[v] = true;

	// Recur for all the vertices adjacent to this vertex
	list<int>::iterator i;

	if (!adj[v].empty())
		for (i = adj[v].begin(); i != adj[v].end(); ++i)
		{
			if (!visited[*i])
				DFSUtil(*i, visited);
		}
}

// Function that returns reverse (or transpose) of this graph
// This function is needed in isSC()
Graph Graph::getTranspose()
{
	Graph g(V);
	for (int v = 0; v < V; v++)
	{
		// Recur for all the vertices adjacent to this vertex
		list<int>::iterator i;
		for (i = adj[v].begin(); i != adj[v].end(); ++i)
		{
			g.adj[*i].push_back(v);
			(g.in[v])++;
		}
	}
	return g;
}

// This function returns true if all non-zero degree vertices of
// graph are strongly connected (Please refer
// https://www.geeksforgeeks.org/connectivity-in-a-directed-graph/ )
bool Graph::isSC()
{
	// Mark all the vertices as not visited (For first DFS)
	bool visited[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	// Find the first vertex with non-zero degree
	int n;
	for (n = 0; n < V; n++)
		if (adj[n].size() > 0)
			break;

	// Do DFS traversal starting from first non zero degree vertex.
	DFSUtil(n, visited);

	// If DFS traversal doesn't visit all vertices, then return false.
	for (int i = 0; i < V; i++)
		if (adj[i].size() > 0 && visited[i] == false)
			return false;

	// Create a reversed graph
	Graph gr = getTranspose();

	// Mark all the vertices as not visited (For second DFS)
	for (int i = 0; i < V; i++)
		visited[i] = false;

	// Do DFS for reversed graph starting from first vertex.
	// Staring Vertex must be same starting point of first DFS
	gr.DFSUtil(n, visited);

	// If all vertices are not visited in second DFS, then
	// return false
	for (int i = 0; i < V; i++)
		if (adj[i].size() > 0 && visited[i] == false)
			return false;

	return true;
}

int maratona()
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

		Graph graph(n);

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
		for (auto &pair : pares)
		{
			for (auto &x : charMap[pair.first])
			{
				// std::cout << x << pair.first << '\t';
				// add edge com cada no adicionando a saida
				for (auto &y : charMap[pair.second])
				{
					std::cout << y << pair.second << ' ';
					graph.addEdge(x, y);
					std::cout << x << ' ' << y << '\n';
				}
				// std::cout << '\n';
			}
		}

		// se tem eulerian
		if (graph.isEulerianCycle())
			cout << "Given directed graph is eulerian n\n";
		else
			cout << "Given directed graph is NOT eulerian n\n";

		// output

		chars.clear();
		pares.clear();
		charMap.clear();
	}

	"Ordering is possible.";
	"The door cannot be opened.";

	return 0;
}

int main(int argc, char const *argv[])
{
	maratona();
	// test();
	return 0;
}
