/*
 * Yuri Niitsuma
 * 2011039023
 * http://br.spoj.com/problems/DESVIO/
 * DESVIO
 */

// Algoritmo de Dijkstra
// Este problema é muito ruim de entender,
// demorei o dia inteiro pra entender o enunciado
// O grafo tem direção apenas em algumas rotas
// Não curti

#include <iostream>
#include <vector>
#include <climits>
#include <queue>

#define INFINITE LLONG_MAX

class Graph {
private:
  long long n;
  long long m;
  std::vector < std::vector < long long > > edges; // n x n
  std::vector < long long > dist; // n

public:
  Graph (long long n, long long m);
  virtual ~Graph ();

  long long get_shortest_path (long long src, long long d);
  void set_edges (long long c);
private:
  void dijkstra(long long src);
};

Graph::Graph (long long n, long long m) {
  this->n = n;
  this->m = m;
  this->edges.resize(n); // Zero index is used for nothing
  for (long long i = 0; i < n; i++) {
    this->edges[i].resize(n, INFINITE);
    this->edges[i][i] = 0;
  }
}

Graph::~Graph () {
  // std::cout << "Graph deleted" << '\n';
}

long long Graph::get_shortest_path(long long src, long long d) {
  this->dijkstra(src);
  // for (int i = 0; i < this->n; i++) {
  //   std::cout << this->dist[i] << '\t';
  // }
  // std::cout << '\n';
  return this->dist[d];
}

void Graph::dijkstra(long long src) {
  long long k;

  this->dist.clear();
  this->dist.resize(n, INFINITE);

  // after this I will omite this->dist to get easy legibility
  dist[src] = 0;

  // BFS Dijkstra
  std::queue<long long> queue;
  queue.push(src);

  while (!queue.empty()) {
    k = queue.front();
    queue.pop();

    for (long long i = 0; i < this->n; i++) {
      if (this->edges[k][i] != INFINITE && dist[i] > dist[k] + this->edges[k][i]) {
        dist[i] = dist[k] + this->edges[k][i];
        queue.push(i);
      }
    }
	}
}

void Graph::set_edges(long long c) {
  long long input_ii, input_jj, input_tt;
  for (long long i = 0; i < m; i++) {
    std::cin >> input_ii >> input_jj >> input_tt;

    // Aqui tem uma peculariedade, se tiver na rota eu indico apenas uma direção
    if (
      (input_ii < c && input_jj < c && (input_ii - input_jj == 1 || input_jj - input_ii == 1))
      || (input_ii >= c && input_jj >=c) ) {
      this->edges[input_ii][input_jj] = input_tt;
      this->edges[input_jj][input_ii] = input_tt;
    }
    else if( input_ii >= c && input_jj < c ) { // input_jj ta na rota
      this->edges[input_ii][input_jj] = input_tt;
    }
    else if( input_ii < c && input_jj >= c ) { // input_ii ta na rota
      this->edges[input_jj][input_ii] = input_tt;
    }
    else { // Se for algo que não abordei
      continue;
    }
  }
}

int main(int argc, char const *argv[]) {
  long long n, m, c, k;

  while (true) {
    std::cin >> n >> m >> c >> k;
    if ( !(n | m | c | k) ) break;

    Graph graph(n, m);
    graph.set_edges(c);

    std::cout << graph.get_shortest_path(k, c - 1) << std::endl;

  }
  return 0;
}
