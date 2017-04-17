/*
 * Yuri Diego Santos Niitsuma
 * 2011039023
 * http://codeforces.com/problemset/problem/161/D
 * Distance in Tree
 */

// Fiz este código em python mas estoura o limite de memória de 512MB no codeforces
// c++ rulez

#include <iostream>
#include <vector>
#include <stack>
#include <queue>

#include <algorithm>

class Graph {
public:
  int n;
  int k;
  int num_with_k_dist;
  std::vector<std::vector<int>> edges;
  std::vector<std::vector<int>> cost;

  Graph (int n, int k);
  virtual ~Graph ();

  void set_connection(int x, int y);
  void walk_vertice(int, int);
  void print_edges();
  void printMatrix();
};

Graph::Graph (int n, int k) {
  this->n = n;
  this->k = k;
  this->num_with_k_dist = 0;
  this->edges.resize(n+1); // don't count edges[0]
  this->cost.resize(n+1);

  for (int i = 0; i <= n; i++) {
    this->cost[i].resize(k+1, 0);
  }
}

void Graph::set_connection(int x, int y) {
  this->edges[x].push_back(y);
  this->edges[y].push_back(x);
}

// using dfs to walk on tree and update cost matrix
void Graph::walk_vertice(int vertice, int came_from = 0) {
  // std::cout << "walk_vertice " << vertice << " " << came_from << '\n';
  this->cost[vertice][0] = 1; // to mark

  for ( auto aux_v : this->edges[vertice] ) {
    if (aux_v != came_from) {
      // std::cout << "aux_v " << aux_v << '\n';
      this->walk_vertice(aux_v, vertice);
      // std::cout << "back " << vertice << " " << aux_v << '\n';
      for (int i = 1; i <= this->k; i++) {
        this->num_with_k_dist += (this->cost[vertice][i-1]) * (this->cost[aux_v][this->k - i]);
        // std::cout << "num_with_k_dist " << this->num_with_k_dist << '\n';
      }
      for (int i = 1; i <= this->k; i++) {
        this->cost[vertice][i] += (i > 1) ? this->cost[aux_v][i-1] : 1;
      }
      // this->printMatrix();
    }
  }
}

void Graph::print_edges() {
  std::cout << "edges:\n";

  for (int i = 1; i <= this->n; i++) {
    (i < 10) ? std::cout << "   " : (i < 100) ? std::cout << "  " : std::cout << " ";
    std::cout << i << " --> [";
    for (int j = 0; j < this->edges[i].size(); j++) {
      std::cout << this->edges[i][j] << ",   ";
    }
    std::cout << "]\n";
  }
}

void Graph::printMatrix() {

  std::cout << "cost:\n      ";
  for (int i = 0; i <= this->k ; i++) {
    (i < 10) ? std::cout << "   " : (i < 100) ? std::cout << "  " : std::cout << " ";
    std::cout << i;
  }
  std::cout << '\n';

  for (int i = 0; i <= this->n; i++) {
    (i < 10) ? std::cout << "   " : (i < 100) ? std::cout << "  " : std::cout << " ";
    std::cout << i << " --> ";
    for (int j = 0; j <= this->k; j++) {
      std::cout << this->cost[i][j] << "   ";
    }
    std::cout << '\n';
  }
}

Graph::~Graph () {
  // //std::cerr << "\nGraph deleted\n";
}

int main(int argc, char const *argv[]) {
  int n, k;
  int a, b;
  int response = 0;

  std::cin >> n >> k;

  Graph graph(n, k); // need to reminder k inside graph

  for (int i = 0; i < n-1; i++) {
    std::cin >> a >> b;
    graph.set_connection(a, b);
  }

  // graph.print_edges();

  graph.walk_vertice(1); // start from one

  std::cout << graph.num_with_k_dist << '\n';
  return 0;
}
