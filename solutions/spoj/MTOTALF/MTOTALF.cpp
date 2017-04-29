/*
 * Yuri Niitsuma
 * 2011039023
 * http://www.spoj.com/problems/MTOTALF/
 * MTOTALF
 */

// FordFulkerson do WIkipédia
// https://en.wikipedia.org/wiki/Ford%E2%80%93Fulkerson_algorithm

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <limits>


class Graph {
private:
  int n;
  std::vector<std::vector<int>> edges;
  std::vector<int> parent;

  // bool dfs(int x);
  bool bfs(int x);

public:
  Graph ();
  virtual ~Graph ();

  void set_weight(char u, char v, int weight);
  int FordFulkerson();
};

Graph::Graph () {
  this->n = 2*26;
  this->edges.resize(this->n);
  for ( auto& x : this->edges ) {
    x.resize(this->n, 0);
  }
  this->parent.resize(this->n, -1);
}

Graph::~Graph () {}

void Graph::set_weight(char u, char v, int weight) {
  // std::cerr << "Setting edge weight" << '\n';
  // std::cerr << u << ' ' << v << " " << weight << '\n';
  // int i = (u != 'Z') ? int(u) - int('A') : this->n;
  // int j = (v != 'Z') ? int(v) - int('A') : this->n;
  int i = (int(u) < int('a') ) ? int(u) - int('A') : int(u) - int('a') + int('Z') - int('A');
  int j = (int(v) < int('a') ) ? int(v) - int('A') : int(v) - int('a') + int('Z') - int('A');
  // std::cerr << i << ' ' << j << '\n';
  // if already have, just plus the weight
  this->edges[ i ][ j ] += weight;
  this->edges[ j ][ i ] += weight;
}

bool Graph::bfs( int init_v ) {
  // std::cerr << "exec bfs" << '\n';
  std::vector<bool> colors;
  colors.resize(this->n, false);

  std::queue<int> queue;
  queue.push(init_v);
  colors[0] = true;

  int u;

  while (!queue.empty()) {
    u = queue.front();
    // std::cerr << u << '\n';
    queue.pop();
    if (u == 25) return true;
    for (int v = 0; v < this->n; v++) {
      if (this->edges[u][v] > 0 && !colors[v]) {
        queue.push(v);
        colors[v] = true;
        this->parent[v] = u;
      }
    }
  }
  return false;
}

int Graph::FordFulkerson() {
  // std::cerr << "initint totalflow" << '\n';
  int response = 0;
  int path_flow;
  std::fill(this->parent.begin(), this->parent.end(), -1);

  while (this->bfs(0)) {
    path_flow = std::numeric_limits<int>::max();
    int s = 25; // sink

    while (s != 0) { // sink != source
      path_flow = std::min(path_flow, this->edges[this->parent[s]][s]);
      s = parent[s];
    }

    // std::cerr << "get path_flow " << path_flow << '\n';
    response += path_flow;

    // update residual capacities
    int v = 25;
    int u;
    while (v != 0) {
      u = this->parent[v];
      this->edges[u][v] -= path_flow;
      this->edges[v][u] += path_flow;
      v = parent[v];
    }
  }
  return response;
}

int main(int argc, char const *argv[]) {
  int n, f;
  char a, b;

  std::cin >> n;

  Graph graph;

  for (int i = 0; i < n; i++) {
    std::cin >> a >> b >> f;
    graph.set_weight(a, b, f);
  }

  std::cout << graph.FordFulkerson() << std::endl;

  return 0;
}
