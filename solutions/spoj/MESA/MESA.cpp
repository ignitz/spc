/*
 * Yuri Diego Santos Niitsuma
 * 2011039023
 * http://br.spoj.com/problems/MESA/
 * MESA
 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

class Graph {
public:
  int n;
  int m;
  std::vector<std::vector<int>> edges;

  Graph (int m, int n);
  virtual ~Graph ();

  void add(int v, int w);
  void print();

  bool isBipartite();
  bool matching();
};

Graph::Graph (int n, int m) {
  this->n = n;
  this->m = m;

  this->edges.resize(n + 1);
  int count = 0;
  for (auto& x : this->edges) {
    x.resize(n+1, 0);
    if (count == 0) {
      for (auto& y : x) {
        y = count++;
      }
      count = 0;
    }
    x[0] = count++;
  }
}
Graph::~Graph() {
  // std::cerr << "Graph deleted" << '\n';
}

void Graph::add(int v, int w) {
  this->edges[v][w] = this->edges[w][v] = 1;
}

void Graph::print() {
  std::cout << "===============================" << '\n';
  for (int i = 0; i < this->edges.size(); i++) {
    std::cout << "--> ";
    for (auto w : this->edges[i])
      std::cout << w << " ";
    std::cout << '\n';
  }
  std::cout << "===============================" << '\n';
}

bool Graph::isBipartite() {

  int init_v = 1; // initial vertice

  // Create a color array for vertices
  int colors[this->n + 1];
  for (int i = 1; i <= this->n; ++i)
    colors[i] = -1;

  // TODO: check if it's a good choice for initial vertice
  colors[1] = init_v;

  // Similar to BFS
  std::queue <int> fifo_queue;
  fifo_queue.push(init_v);

  // let's colors these vertices
  while (!fifo_queue.empty()) {
    int vertice = fifo_queue.front();
    fifo_queue.pop();

    for (int i = 1; i <= this->n; ++i) {
      if (this->edges[vertice][i] && colors[i] == -1) {
        colors[i] = 1 - colors[vertice];
        fifo_queue.push(i);
      }

      else if (this->edges[vertice][i] && colors[i] == colors[vertice])
      return false;
    }
  }

  return true;
}

bool Graph::matching() {
  return this->isBipartite();
}

int main(int argc, char const *argv[]) {
  int n, m;
  int v, w;

  int count = 1;

  while (std::cin >> n >> m) {

    Graph graph(n, m);

    for (int i = 0; i < m; i++) {
      std::cin >> v >> w;
      graph.add(v, w);
    }
    // graph.print();

    std::cout << "Instancia " << count++ << '\n';
    if (graph.matching())
      std::cout << "sim" << '\n';
    else
      std::cout << "nao" << '\n';
  }
  return 0;
}
