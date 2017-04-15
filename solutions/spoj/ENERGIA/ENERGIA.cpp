/*
 * Yuri Diego Santos Niitsuma
 * 2011039023
 * http://br.spoj.com/problems/ENERGIA/
 * ENERGIA
 */

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

// Utilizei a mesma solução do IREVIR, mas com grafo bi-direcionado

class Graph {
public:
  int n;
  int m;
  std::vector<std::vector<int>> edges;

  Graph (int n, int m);
  virtual ~Graph ();

  void add(int v, int w);
  void print();
  bool bfs(int init_v);
  bool is_connected();
};

Graph::Graph (int n, int m) {
  this->n = n;
  this->m = m;
  this->edges.resize(n);
}
Graph::~Graph() {
  // std::cerr << "Graph deleted" << '\n';
}

void Graph::add(int v, int w) {
  this->edges[v-1].push_back(w);
  this->edges[w-1].push_back(v);
}

void Graph::print() {
  std::cout << "===============================" << '\n';
  for (int i = 0; i < this->edges.size(); i++) {
    std::cout << (i+1) << ':' << '\n';
    for (auto w : this->edges[i])
      std::cout <<  w << ' ';
    std::cout << '\n';
  }
  std::cout << "===============================" << '\n';
}

bool Graph::bfs(int init_v) {
  std::deque<int> vs_marked;
  std::deque<int> queue; // Poe vertice inicial na fila
  queue.push_back(init_v);
  vs_marked.resize (this->n + 1, 0);
  vs_marked[0] = vs_marked[init_v] = true;
  int count_marked = 1;

  int vertice1;

  while( !queue.empty() ) {
    vertice1 = queue.front();

    for ( auto p : this->edges[vertice1 - 1] ) {
      // if p is not marked
      if ( !vs_marked[p] ) {
        // mark p and put in queue
        if (vs_marked[p] == 0) {
          vs_marked[p] = true; count_marked++;
          if (count_marked == this->n) return true;
          queue.push_back(p);
        }
      }
    }
    queue.pop_front();
  }
  return false;
}

bool Graph::is_connected() {
  return this->bfs(1);
}

int main(int argc, char const *argv[]) {
  int n, m, v, w;

  int count = 1;

  while (true) {
    std::cin >> n >> m;
    if (n == 0 && m == 0) break;

    Graph graph(n, m);

    for (int i = 0; i < m; i++) {
      std::cin >> v >> w;
      graph.add(v, w);
    }

    // ask if connected
    std::cout << "Teste " << count++ << '\n';
    if (graph.is_connected())
      std::cout << "normal" << '\n';
    else
      std::cout << "falha" << '\n';
  }
  return 0;
}
