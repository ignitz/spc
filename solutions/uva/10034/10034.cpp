/*
 * Yuri Niitsuma
 * 2011039023
 * https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=975
 * 10034 - Freckles
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
#include <iomanip>

// spanning tree problem with coordinates

/*****************************************/
// https://www.geeksforgeeks.org/kruskals-minimum-spanning-tree-using-stl-in-c/
// To represent Disjoint Sets
struct DisjointSets
{
	int *parent, *rnk;
	int n;

	// Constructor.
	DisjointSets(int n)
	{
		// Allocate memory
		this->n = n;
		parent = new int[n + 1];
		rnk = new int[n + 1];

		// Initially, all vertices are in
		// different sets and have rank 0.
		for (int i = 0; i <= n; i++)
		{
			rnk[i] = 0;

			//every element is parent of itself
			parent[i] = i;
		}
	}

	// Find the parent of a node 'u'
	// Path Compression
	int find(int u)
	{
		/* Make the parent of the nodes in the path 
           from u--> parent[u] point to parent[u] */
		if (u != parent[u])
			parent[u] = find(parent[u]);
		return parent[u];
	}

	// Union by rank
	void merge(int x, int y)
	{
		x = find(x), y = find(y);

		/* Make tree with smaller height 
           a subtree of the other tree  */
		if (rnk[x] > rnk[y])
			parent[y] = x;
		else // If rnk[x] <= rnk[y]
			parent[x] = y;

		if (rnk[x] == rnk[y])
			rnk[y]++;
	}
};

double calcDist(double x1, double x2, double y1, double y2)
{
	return std::sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

/******************************************/

class Graph
{
  private:
	int n; // Number of Nodes
	int m; // Numbver of edges
	// source, destiny and weight
	std::vector<std::pair<double, std::pair<int, int>>> edges;

  public:
	Graph(int n);
	~Graph();
	void addEdge(int source, int destiny, double weight);
	double kruskalMST();
};

Graph::Graph(int n)
{
	this->n = n;
	this->m = 0;
}

Graph::~Graph()
{
	this->edges.clear();
}

void Graph::addEdge(int source, int destiny, double weight)
{
	this->edges.push_back(std::make_pair(weight, std::make_pair(destiny, source)));
	this->m++;
}

double Graph::kruskalMST()
{
	double mst_wt = 0; // Initialize result

	// Sort edges in increasing order on basis of cost
	std::sort(edges.begin(), edges.end());

	// Create disjoint sets
	DisjointSets ds(this->n);

	// Iterate through all sorted edges
	std::vector<std::pair<double, std::pair<int, int>>>::iterator it;
	for (it = edges.begin(); it != edges.end(); it++)
	{
		int u = it->second.first;
		int v = it->second.second;

		int set_u = ds.find(u);
		int set_v = ds.find(v);

		// Check if the selected edge is creating
		// a cycle or not (Cycle is created if u
		// and v belong to same set)
		if (set_u != set_v)
		{
			// Update MST weight
			mst_wt += it->first;

			// Merge two sets
			ds.merge(set_u, set_v);
		}
	}

	return mst_wt;
}

int main()
{
	int numberOfCases, n;
	double x, y;
	std::vector<std::pair<double, double>> nodes;

	std::cin >> numberOfCases;

	int caseNum = 0;
	while (caseNum++ < numberOfCases)
	{
		if (caseNum != 1)
			std::cout << '\n';
		std::cin >> n;
		Graph graph(n);

		int indexNode = 0;
		while (indexNode++ < n)
		{
			std::cin >> x >> y;
			nodes.push_back(std::make_pair(x, y));
		}

		// compute the edges
		for (int i = 0; i < nodes.size(); i++)
		{
			for (int j = i + 1; j < nodes.size(); j++)
			{
				graph.addEdge(i + 1, j + 1, calcDist(nodes[i].first, nodes[j].first, nodes[i].second, nodes[j].second));
			}
		}

		// compute
		std::cout << std::fixed << std::setprecision(2) << graph.kruskalMST() << '\n';

		// clear
		nodes.clear();
	}

	return 0;
}
