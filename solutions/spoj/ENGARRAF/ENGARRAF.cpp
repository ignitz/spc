/*
 * Yuri Niitsuma
 * 2011039023
 * http://br.spoj.com/problems/ENGARRAF/
 * ENGARRAF
 */

// Algoritmo de Floyd-Marshall

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>    // std::min
// #include <utility> // std::pair

class Graph {
private:
  long long n;
  long long m;
  std::vector <std::vector <long long>> edges; // n x n
  std::vector <std::vector<long long>> cost_matrix; // n x n

  bool floyd_done;

public:

  Graph (long long n, long long m);
  virtual ~Graph ();

  long long get_shortest_path(long long s, long long d);
  void print_matrix();

private:
  void floyd_marshall();
};

Graph::Graph (long long n, long long m) {
  this->n = n;
  this->m = m;
  this->floyd_done = false;
  this->edges.resize(n+1); // Zero index is used for nothing

  // matrix weight
  for (long long i = 1; i <= n; i++) {
    this->edges[i].resize(n+1, 0);
  }
  long long input_ii, input_jj, input_tt;
  for (long long i = 0; i < m; i++) {
    std::cin >> input_ii >> input_jj >> input_tt;
    this->edges[input_ii][input_jj] = input_tt;
    // this->edges[input_ii].push_back(std::make_pair(input_jj, input_tt));
  }
}

Graph::~Graph () {
  // std::cout << "Graph deleted" << '\n';
}

long long Graph::get_shortest_path(long long s, long long d) {
  this->floyd_marshall();
  long long response  = this->cost_matrix[s][d];
  return (response != LLONG_MAX) ? response : -1;
}

// DEBUG print matrix with edges
void Graph::print_matrix() {
  for (long long i = 1; i <= this->n; i++) {
    for (long long j = 1; j <= this->n; j++)
      (this->edges[i][j] != LLONG_MAX) ? std::cout << this->edges[i][j] << '\t' : std::cout << "INF ";
    std::cout << '\n';
  }

  if (this->floyd_done) {
    for (long long i = 1; i <= this->n; i++) {
      for (long long j = 1; j <= this->n; j++)
      (this->cost_matrix[i][j] != LLONG_MAX) ? std::cout << this->cost_matrix[i][j] << '\t' : std::cout << "INF ";
      std::cout << '\n';
    }
  }
}

void // O(n³)
Graph::floyd_marshall() {
  if (this->floyd_done) return;

  this->floyd_done = true;

  this->cost_matrix.resize(this->n + 1);

  for (auto& x : this->cost_matrix) {
    x.resize(this->n + 1, LLONG_MAX);
  }

  for (long long i = 1; i <= this->n; i++) {
    for (long long j = 1; j <= this->n; j++) {
      if (this->edges[i][j] != 0) {
        this->cost_matrix[i][j] = this->edges[i][j];
      }
      this->cost_matrix[i][i] = 0;
    }
  }

  long long aux1, aux2;

  for (long long k = 1; k <= this->n; k++) {
    for (long long i = 1; i <= this->n; i++) {
      for (long long j = 1; j <= this->n; j++) {
        aux1 = (this->cost_matrix[i][j] == LLONG_MAX) ? LLONG_MAX : this->cost_matrix[i][j];
        aux2 = (this->cost_matrix[i][k] == LLONG_MAX || this->cost_matrix[k][j] == LLONG_MAX) ? LLONG_MAX : this->cost_matrix[i][k] + this->cost_matrix[k][j];
        this->cost_matrix[i][j] = std::min(aux1, aux2);
      }
    }
  }
  return;
}

int main(int argc, char const *argv[]) {
  unsigned long long n, m, s, d;

  while (true) {
    std::cin >> n >> m;
    if ( !(n | m) ) break;

    Graph graph(n, m);
    std::cin >> s >> d;
    std::cout << graph.get_shortest_path(s, d) << std::endl;
    // graph.print_matrix();
  }
  return 0;
}
