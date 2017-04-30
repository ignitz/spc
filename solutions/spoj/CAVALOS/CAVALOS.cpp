/*
 * Yuri Niitsuma
 * 2011039023
 * http://br.spoj.com/problems/CAVALOS/
 * CAVALOS
 */

// Criei n + m vertices com mais dois auxiliares
// n + 1 primeiros representa cavalos e n + 1 até n + m + 1
// os soldados

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <limits>
#include <algorithm>

// #define DIGRAFO

class Graph {
private:
  int n;
  int m;
  int card_v;
  std::vector<std::vector<int>> edges;
  std::vector<std::vector<int>> capacity;
  std::vector<std::vector<int>> rCap; // residuo
  std::vector<int> parent;
  bool bfs(int source_v, int destiny_v);
  void set_weight (int u, int v, int weight);

public:
  Graph (int n, int m);
  virtual ~Graph ();

  void set_weight_horse(int v, int weight);
  void set_weight_soldier(int v);
  void set_weight_horse_to_soldier(int u, int v);
  int FordFulkerson ();
  void printEdges();
};

Graph::Graph (int n, int m) {
  this->card_v = n + m + 2; // zero representa source e last é o destino
  this->n = n;
  this->m = m;
  this->edges.resize( card_v );
  this->capacity.resize(card_v , std::vector<int>(card_v, 0));
  this->rCap.resize(card_v, std::vector<int>(card_v, 0));
  this->parent.resize(card_v, -1);
}

Graph::~Graph () {}

void Graph::set_weight(int u, int v, int weight) {
  // if already have, just plus the weight
  this->edges[u].push_back(v);
  this->capacity[u][v] += weight;
  #ifdef DIFRAGO
  this->edges[v].push_back(u);
  this->capacity[v][u] += weight;
  #endif
}

void Graph::set_weight_horse(int v, int weight) {
  this->set_weight(this->m + v, this->m + this->n + 1, weight);
}

void Graph::set_weight_soldier(int v) {
  this->set_weight(0, v , 1);
}

void Graph::set_weight_horse_to_soldier(int u, int v) {
  this->set_weight(v, this->m + u, 1);
}

bool Graph::bfs( int source_v, int destiny_v ) {
  std::cerr << "\033[1;37m" << "exec bfs" << '\n' << "\033[0m";
  bool response = false;
  int u;

  std::queue<int> queue;
  queue.push(source_v);

  std::fill(this->parent.begin(), this->parent.end(), -1);
  parent[source_v] = source_v;

  while (!queue.empty()) {
    u = queue.front();
    std::cerr << "\033[1;31m" << u << ' ' << "\033[0m";
    queue.pop();
    if (u == destiny_v) { // no return, because must finish theri job
      std::cerr << "\033[1;31m" << '\n' << "\033[0m";
      response = true;
    }
    std::sort(this->edges[u].begin(), this->edges[u].end());
    for ( auto v : this->edges[u] ) {
      if (this->rCap[u][v] > 0 && parent[v] == -1) {
        queue.push(v);
        this->parent[v] = u;
      }
    }
  }
  std::cerr << "\033[1;31m" << '\n' << "\033[0m";
  return response;
}

int Graph::FordFulkerson() {
  std::cerr << "\033[1;37m" << "exec FordFulkerson" << '\n' << "\033[0m";
  int source_v = 0;
  int destiny_v = this->n + this->m + 1;
  int response = 0;
  int path_flow;

  for (int i = 0; i < this->card_v; i++) {
    for (int j = 0; j < this->card_v; j++) {
      this->rCap[i][j] = this->capacity[i][j];
    }
  }

  // std::fill(this->parent.begin(), this->parent.end(), -1);

  while (this->bfs(source_v, destiny_v)) {

    for (int i = 1; i < this->card_v; i++) {
      std::cerr << "\033[1;36m" << this->parent[i] << ' ' << "\033[0m";
    }
    std::cerr << "\033[1;31m" << '\n' << "\033[0m";
    // printRCap();

    // Find minimum residual capacity of the capacity along the
    // path filled by BFS. Or we can say find the maximum flow
    // through the path found.
    path_flow = std::numeric_limits<int>::max();
    int s = destiny_v;

    while (s != source_v) {
      std::cerr << "\033[1;34m" << "path_flow " << path_flow  << "\trCap[" << parent[s] << "][" << s << "] " << this->rCap[parent[s]][s] << '\n' << "\033[0m";
      path_flow = std::min(path_flow, this->rCap[parent[s]][s]);
      s = parent[s];
    }

    // update residual capacities of the capacity and reverse capacity
    // along the path
    int v = destiny_v;
    int u;

    while (v != source_v) {
      u = parent[v];
      this->rCap[u][v] -= path_flow;
      this->rCap[v][u] += path_flow;
      v = parent[v];
    }

    std::cerr << "\033[1;32m" << "get path_flow " << path_flow << '\n' << "\033[0m";
    response += path_flow; // Add path flow to overall flow

    std::cerr << "\033[1;33m" << "max_flow " << response << '\n' << "\033[0m";
  }
  std::cerr << "\033[1;33m" << "response " << response << '\n' << "\033[0m";
  return response;
}

void Graph::printEdges() {
  for (int i = 0; i < this->card_v; i++) {
    std::cout << i << " --> ";
    for (auto x : this->edges[i]) {
      std::cout << x << ':' << this->capacity[i][x] << ' ';
    }
    std::cout << '\n';
  }
}

int main(int argc, char const *argv[]) {
  int n, m, k;
  int c_i;
  int u, v;

  int counter = 1;

  while (std::cin >> n >> m >> k) {

    Graph graph(n, m);

    for (int i = 1; i <= n; i++) {
      std::cin >> c_i;
      graph.set_weight_horse(i, c_i);
    }
    for (int i = 1; i <= m; i++) {
      graph.set_weight_soldier(i);
    }
    for (int i = 1; i <= k; i++) {
      std::cin >> u >> v;
      graph.set_weight_horse_to_soldier(u, v);
    }

    // graph.printEdges();
    // std::cout << "AQUI " << " " << n << " " << m << " " << k << '\n';
    std::cout << "Instancia " << counter++ << '\n';
    std::cout << graph.FordFulkerson() << "\n\n";
  }
  return 0;
}
