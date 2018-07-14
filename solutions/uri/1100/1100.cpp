/*
 * Yuri Niitsuma
 * 2011039023
 * https://www.urionlinejudge.com.br/judge/pt/problems/view/1100
 * URI1100
*/

#include <iostream>
#include <vector>
#include <string>     // std::string, std::stoi
#include <limits>

class Casa {
public:
	int x;
	int y;
	int number;
	std::vector<int> edges;

	Casa (int x, int y) {
		this->x;
		this->y;
		this->number = x*8 + y;
	}
	virtual ~Casa () {}

	bool add_edge(int x, int y) {
		if(x >= 0 && x < 8 && y >= 0 && y < 8) {
			this->edges.push_back(x*8 + y);
			return true;
		}
		return false;
	}
};

class Graph {
private:
	int n;
	std::vector<Casa> casas;
	int f_char;
	int f_number;

	std::vector<std::vector<int>> cost;
	int INT_MAX;

public:
	Graph ();
	virtual ~Graph ();

	int get_position_X(std::string);
	int get_position_Y(std::string);
	int get_position_X(int number);
	int get_position_Y(int number);
	void make_cost_matrix();
	int get_min_path(std::string a, std::string b);

	bool casa_exists(int x, int y);
};

Graph::Graph() {
	this->cost.resize(65, std::vector<int> (65, 0));
	this->INT_MAX = std::numeric_limits<int>::max();

	this->n = 64;
	for (int x = 0; x < 8; x++) {
		for (int y = 0; y < 8; y++) {
			if (!casa_exists(x,y)) {
				Casa aux(x, y);
				// ja adiciona as arestas possíveis
				// ignora se não tiver como inserir
				aux.add_edge(x+2,y+1);
				aux.add_edge(x+2,y-1);
				aux.add_edge(x-2,y+1);
				aux.add_edge(x-2,y-1);
				aux.add_edge(x+1,y+2);
				aux.add_edge(x-1,y+2);
				aux.add_edge(x+1,y-2);
				aux.add_edge(x-1,y-2);
				this->casas.push_back(aux);
			}
		}
	}
	this->f_char = int('a');
	this->f_number = int('1');

	make_cost_matrix();
}

Graph::~Graph() {}

int Graph::get_position_X(std::string position) {
	return int(position[0] - f_char);
}
int Graph::get_position_Y(std::string position) {
	return int(position[1] - f_number);
}

int Graph::get_position_X(int number) {
	return (number / 8);
}
int Graph::get_position_Y(int number) {
	return (number % 8);
}

void Graph::make_cost_matrix() {
	int n = 64;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cost[i][j] = INT_MAX;
			if (i == j) cost[i][j] = 0;
		}
	}
	for (int i = 1; i <= n; ++i) { // insiro os custos dos edges
		for(auto const number : this->casas[i-1].edges) {
			cost[i][number+1] = 1;
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

int Graph::get_min_path(std::string a, std::string b) {
	int ax, ay, bx, by;
	ax = get_position_X(a); ay = get_position_Y(a);
	bx = get_position_X(b); by = get_position_Y(b);
	int number1 = ax*8 + ay;
	int number2 = bx*8 + by;
	return cost[number1 + 1][number2 + 1];
}

bool Graph::casa_exists(int x, int y) {
	int number = x*8 + y;
	if(x >= 0 && x < 8 && y >= 0 && y < 8) {
		for (auto casa : casas) {
			if (casa.number == number) return true;
		}
	}
	return false;
}

int main(int argc, char const *argv[])
{
	std::string a, b;

	Graph graph;

	while (std::cin >> a >> b) {
		std::cout << "To get from " << a << " to " << b << " takes " << graph.get_min_path(a, b) << " knight moves.\n";
	}
	return 0;
}
