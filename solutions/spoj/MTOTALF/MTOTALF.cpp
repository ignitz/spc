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

#define SINK 25

class Graph {
private:
  int n;
  std::vector<std::vector<int>> edges;
  std::vector<int> parent;

  bool dfs(int x);
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
  //std::cerr << "Setting edge weight" << '\n';
  //std::cerr << u << ' ' << v << " " << weight << '\n';
  int i = (int(u) < int('a') ) ? int(u) - int('A') : int(u) - int('a') + int('Z') - int('A');
  int j = (int(v) < int('a') ) ? int(v) - int('A') : int(v) - int('a') + int('Z') - int('A');
  //std::cerr << i << ' ' << j << '\n';
  // if already have, just plus the weight
  this->edges[ i ][ j ] += weight;
  this->edges[ j ][ i ] += weight;
}

bool Graph::bfs( int init_v ) {
  std::cerr << "\033[1;37m" << "exec bfs" << '\n' << "\033[0m";
  std::vector<bool> colors;
  colors.resize(this->n, false);

  std::queue<int> queue;
  queue.push(init_v);
  colors[0] = true;

  int u;

  while (!queue.empty()) {
    u = queue.front();
    std::cerr << "\033[1;31m" << u << '\t' << "\033[0m";
    queue.pop();
    if (u == SINK) {
      std::cerr << "\033[1;31m" << '\n' << "\033[0m";
      return true;
    }
    for (int v = 0; v < this->n; v++) {
      if (this->edges[u][v] > 0 && !colors[v]) {
        queue.push(v);
        colors[v] = true;
        this->parent[v] = u;
      }
    }
  }
  std::cerr << "\033[1;31m" << '\n' << "\033[0m";
  return false;
}

bool Graph::dfs( int init_v ) {
  std::cerr << "\033[1;37m" << "exec dfs" << '\n' << "\033[0m";
  std::vector<bool> colors;
  colors.resize(this->n, false);

  std::stack<int> mystack;
  mystack.push(init_v);
  colors[0] = true;

  int u;

  while (!mystack.empty()) {
    u = mystack.top();
    std::cerr << "\033[1;31m" << u << '\t' << "\033[0m";
    mystack.pop();
    if (u == SINK) {
      std::cerr << "\033[1;31m" << '\n' << "\033[0m";
      return true;
    }
    for (int v = 0; v < this->n; v++) {
      if (this->edges[u][v] > 0 && !colors[v]) {
        mystack.push(v);
        colors[v] = true;
        this->parent[v] = u;
      }
    }
  }
  std::cerr << "\033[1;31m" << '\n' << "\033[0m";
  return false;
}

int Graph::FordFulkerson() {
  std::cerr << "\033[1;37m" << "exec FordFulkerson" << '\n' << "\033[0m";
  int response = 0;
  int path_flow;
  std::fill(this->parent.begin(), this->parent.end(), -1);

  while (this->dfs(0)) {

    for (int i = 0; i < this->n; i++) {
      std::cerr << "\033[1;36m" << this->parent[i] << ' ' << "\033[0m";
    }
    std::cerr << "\033[1;31m" << '\n' << "\033[0m";

    // Find minimum residual capacity of the edges along the
    // path filled by BFS. Or we can say find the maximum flow
    // through the path found.
    path_flow = std::numeric_limits<int>::max();
    int s = SINK; // sink

    while (s != 0) { // sink != source
      path_flow = std::min(path_flow, this->edges[this->parent[s]][s]);
      s = parent[s];
    }

    std::cerr << "\033[1;32m" << "get path_flow " << path_flow << '\n' << "\033[0m";
    response += path_flow; // Add path flow to overall flow

    // update residual capacities of the edges and reverse edges
    // along the path
    int v = SINK;
    int u;
    while (v != 0) {
      u = this->parent[v];
      this->edges[u][v] -= path_flow;
      this->edges[v][u] += path_flow;
      v = this->parent[v];
    }
    std::cerr << "\033[1;33m" << "max_flow " << response << '\n' << "\033[0m";
  }
  std::cerr << "\033[1;33m" << "response " << response << '\n' << "\033[0m";
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
