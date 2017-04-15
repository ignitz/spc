/*
 * Yuri Diego Santos Niitsuma
 * 2011039023
 * http://br.spoj.com/problems/IREVIR/
 * IREVIR
 */

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

// Inicialmente utilizei a ideia de grafos usando dicionário a partir daqui
// https://www.python.org/doc/essays/graphs/
// https://pt.wikipedia.org/wiki/Busca_em_largura
// Mas o tempo limite excedia então fiz em C++

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

    // for ( auto x : queue)
    //   std::cout << x << ' ';
    // std::cout << '\n';
    // for (int i = 1; i <= this->n; i++)
    //   std::cout << vs_marked[i] << ' ';
    // std::cout << '\n';

  }

  // for (int i = 1; i <= this->n; i++) {
  //   vs_marked[0] &= vs_marked[i];
  //   std::cout << vs_marked[i] << '\t';
  // }
  // std::cout << '\n';

  return false;
}

bool Graph::is_connected() {
  bool response = true;

  for (int i = 1; i <= n; i++) { // check bfs in every vertice
    response &= this->bfs(i);
    if (!response) return false;
  }
  return true;
}

int main(int argc, char const *argv[]) {
  int n, m, v, w, p;

  while (true) {
    std::cin >> n;
    if (n == 0) break;
    std::cin >> m;
    Graph graph(n, m);

    for (int i = 0; i < m; i++) {
      std::cin >> v >> w >> p;
      graph.add(v, w);
      if (p == 2) graph.add(w, v);
    }
    // graph.print();
    // ask if connected
    std::cout << graph.is_connected() << '\n';
  }
  return 0;
}
