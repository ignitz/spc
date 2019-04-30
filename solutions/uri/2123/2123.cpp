/*
 * Yuri Niitsuma
 * 2011039023
 * https://www.urionlinejudge.com.br/judge/en/problems/view/2123
 * 2123 - The Law Goes on Horseback!
*/

/**
 * No SPOJ também tem ele e já resolvi por lá
 * http://br.spoj.com/problems/CAVALOS/
 * CAVALOS
 */

// Criei n + m vertices com mais dois auxiliares
// n + 1 primeiros representa cavalos e n + 1 até n + m + 1
// os soldados

// Por alguma razão ele da errado com lista de adjacencia.
// Fiz 3 versões desta %$#@%$@@$#@

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <limits>
#include <algorithm>

class Graph
{
private:
	int n;
	int m;
	int card_v;
	std::vector<std::vector<int>> edges;
	std::vector<std::vector<int>> capacity;
	std::vector<std::vector<int>> rCap; // residuo
	std::vector<int> parent;
	bool dfs(int source_v, int destiny_v, std::vector<bool> &colors);
	bool getPath(int source_v, int destiny_v);

public:
	Graph(int n, int m);
	virtual ~Graph();

	void set_weight(int u, int v, int weight);
	int FordFulkerson();
	// void printEdges();
};

Graph::Graph(int n, int m)
{
	this->card_v = n + m + 2; // zero representa source e last é o destino
	this->n = n;
	this->m = m;
	this->edges.resize(card_v);
	this->capacity.resize(card_v, std::vector<int>(card_v, 0));
	this->rCap.resize(card_v, std::vector<int>(card_v, 0));
	this->parent.resize(card_v, -1);
}

Graph::~Graph() {}

void Graph::set_weight(int u, int v, int weight)
{
	// if already have, just plus the weight
	// this->edges[u].push_back(v);
	this->capacity[u][v] = weight;
#ifdef DIGRAFO
	// this->edges[v].push_back(u);
	this->capacity[v][u] = weight;
#endif
}

bool Graph::dfs(int source, int destiny, std::vector<bool> &colors)
{
	// std::stack<int> st;
	// st.push(source);
	//
	// while (!st.empty()) {
	//   int u = st.top();
	//   st.pop();
	//
	//   if (u == destiny) return true;
	//
	//   for ( auto v : edges[u]) {
	//     if (capacity[u][v] - rCap[u][v] > 0 && !colors[v]) {
	//       colors[v] = true;
	//       parent[v] = u;
	//       st.push(v);
	//     }
	//   }
	// }
	// return false;
	colors[source] = true;
	if (source == destiny)
		return true;

	for (int v = 0; v < this->card_v; v++)
	{
		if (capacity[source][v] - rCap[source][v] > 0 && !colors[v])
		{
			parent[v] = source;
			if (dfs(v, destiny, colors))
				return true;
		}
	}

	return false;
}

bool Graph::getPath(int source, int destiny)
{
	std::vector<bool> colors(this->card_v, false);
	return dfs(source, destiny, colors);
}

int Graph::FordFulkerson()
{
	int x;
	int source = 0;
	int destiny = this->m + this->n + 1;
	std::fill(parent.begin(), parent.end(), -1);

	parent[source] = source;

	int max_flow = 0;

	while (getPath(source, destiny))
	{
		int flow = std::numeric_limits<std::int32_t>::max();

		x = destiny;
		while (x != source)
		{
			flow = std::min(flow, capacity[parent[x]][x] - rCap[parent[x]][x]);
			x = parent[x];
		}

		x = destiny;
		while (x != source)
		{
			rCap[parent[x]][x] += flow;
			rCap[x][parent[x]] -= flow;
			x = parent[x];
		}
	}

	for (int i = 0; i < card_v; i++)
	{
		max_flow += rCap[i][destiny];
	}
	return max_flow;
}

int main(int argc, char const *argv[])
{
	int n, m, k;
	int c_i;
	int u, v;

	int counter = 1;

	while (std::cin >> n >> m >> k)
	{

		Graph graph(n, m);

		for (int i = 1; i <= n; i++)
		{
			std::cin >> c_i;
			graph.set_weight(m + i, n + m + 1, c_i);
		}
		for (int i = 1; i <= m; i++)
		{
			graph.set_weight(0, i, 1);
		}
		for (int i = 1; i <= k; i++)
		{
			std::cin >> u >> v;
			graph.set_weight(v, m + u, 1);
		}

		// graph.printEdges();
		// std::cout << "AQUI " << " " << n << " " << m << " " << k << '\n';
		std::cout << "Instancia " << counter++ << '\n';
		std::cout << graph.FordFulkerson() << "\n\n";
	}
	return 0;
}
