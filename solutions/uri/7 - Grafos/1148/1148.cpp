/*
 * Yuri Niitsuma
 * 2011039023
 * https://www.urionlinejudge.com.br/judge/pt/problems/view/1148
 * Países em Guerra - 1148
*/

#include <iostream>
#include <vector>
#include <queue>
#include <limits>

class Graph{
private:
	int n;
	std::vector<std::vector<int>> matrix;
	std::vector<std::vector<int>> cost;
	int INT_MAX;
public:
	Graph(int n);
	virtual ~Graph();

	bool set_edge(int u, int v, int w);
	void make_cost_matrix();
	int min_path(int u, int v);
	void print_matrix();
};

Graph::Graph(int n) {
	this->n = n;
	this->matrix.resize(n + 1, std::vector<int> (n + 1, -1));
	this->cost.resize(n + 1, std::vector<int> (n + 1, -1));
	this->INT_MAX = std::numeric_limits<int>::max();
}
Graph::~Graph() {}

bool Graph::set_edge(int u, int v, int w) {

	if (u >= 1 && u <= n && v >= 1 && v <= n) {
		this->matrix[u][v] = w;
		if (this->matrix[v][u] != INT_MAX && this->matrix[v][u] != -1) {
			this->matrix[v][u] = this->matrix[u][v] = 0;
		}
		return true;
	}
	return false;
}

void Graph::make_cost_matrix() {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cost[i][j] = (matrix[i][j] >= 0) ? matrix[i][j] : INT_MAX;
			if (i == j) cost[i][j] = 0;
		}
	}
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (cost[i][k] < INT_MAX && cost[k][j] < INT_MAX) {
					cost[i][j] = std::min(cost[i][j], cost[i][k] + cost[k][j]);
				}
			}
		}		
	}
}

int Graph::min_path(int u, int v) {
	return cost[u][v];
}

void Graph::print_matrix() {
	for (int i = 1; i <= n; ++i) {
		std::cout << i << " --> ";
		for (int j = 1; j <= n; ++j) {
			if (cost[i][j] == INT_MAX) {
				std::cout << "INF\t";
			}
			else {
				(cost[i][j] < 10) ? (std::cout << ' ' << cost[i][j] << '\t') : std::cout << cost[i][j] << '\t';
			}
		}
		std::cout << '\n';
	}
}

int main(int argc, char const *argv[]) {
	int n, e;
	int x, y, h;
	int k, o, d;
	int INT_MAX = std::numeric_limits<int>::max();


	while(std::cin >> n >> e) {
		if( !(n | e) ) break;

		Graph graph(n);
		for (int i = 0; i < e; ++i) {
			std::cin >> x >> y >> h;
			graph.set_edge(x, y, h);
		}

		std::cin >> k;
		graph.make_cost_matrix();
		// graph.print_matrix();
		for (int i = 0; i < k; ++i) {
			std::cin >> o >> d;
			if (graph.min_path(o, d) == INT_MAX) {
				std::cout << "Nao e possivel entregar a carta\n";
			}
			else {
				std::cout << graph.min_path(o, d) << '\n';
			}
			
		}
		std::cout << '\n';
	}
	return 0;
}
