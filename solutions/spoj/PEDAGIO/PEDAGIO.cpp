/*
 * Yuri Diego Santos Niitsuma
 * 2011039023
 * http://br.spoj.com/problems/PEDAGIO/
 * PEDAGIO
 */

#include <iostream>
#include <vector>
#include <deque>
#include <tuple>
#include <algorithm>

// Inicialmente utilizei a ideia de grafos usando dicionário a partir daqui
// https://www.python.org/doc/essays/graphs/
// https://pt.wikipedia.org/wiki/Busca_em_largura
// Mas o tempo limite excedia então fiz em C++

class Graph {
public:
  int n;
  int m;
  int init_v;
  int max_walk;
  std::vector<std::vector<int>> edges;

  Graph (int, int, int, int);
  virtual ~Graph ();

  void add(int v, int w);
  void print();
  std::vector<int> who_reach();
};

Graph::Graph (int n, int m, int init, int max_walk) {
  this->n = n;
  this->m = m;
  this->init_v = init;
  this->max_walk = max_walk;
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
  // std::cout << "===============================" << '\n';
  // for (int i = 0; i < this->edges.size(); i++) {
  //   std::cout << (i+1) << ':' << " --> ";
  //   for (auto w : this->edges[i])
  //     std::cout <<  w << " ";
  //   std::cout << '\n';
  // }
  // std::cout << "===============================" << '\n';
  std::cout << "===============================" << '\n';
  for (int i = 0; i < this->edges.size(); i++) {
    std::cout << (i) << ':' << " --> ";
    for (auto w : this->edges[i])
      std::cout << w << " ";
    std::cout << '\n';
  }
  std::cout << "===============================" << '\n';
}

std::vector<int> Graph::who_reach() {

  std::vector<int> response; // for return
  std::vector<int> marked_v(this->n + 1, 0); // for color vertices
  std::vector<int> cost_from_init(this->n + 1, 0); // for color vertices
  std::deque<int> queue; // FIFO queue

  // temp vars
  int vertice;

  queue.push_back(this->init_v);
  marked_v[init_v] = 1;

  while (!queue.empty()) {
    vertice = queue.front();

    for (int i = 1; i <= this->n; i++) {
      if (this->edges[vertice][i]) {
        // std::cout << vertice << " -> " << i << '\n';
        // std::cout << cost_from_init[i] << ' ' << marked_v[i] << '\n';
        if (marked_v[i] == 0) {
          cost_from_init[i] = cost_from_init[vertice] + 1;
          if (cost_from_init[i] > this->max_walk) continue;
          marked_v[i] = 1;
          queue.push_back(i);
          response.push_back(i);
        }
        else { // Atualiza o custo
          if (cost_from_init[i] > cost_from_init[vertice] + 1)
            cost_from_init[i] = cost_from_init[vertice] + 1;
        }
      }
    }
    marked_v[vertice]++;
    queue.pop_front();
  }

  // for (int i = 1; i <= this->n; i++) {
  //   std::cout << i << ' ';
  // }
  // std::cout << '\n';
  // for (int i = 1; i <= this->n; i++) {
  //   std::cout << marked_v[i] << ' ';
  // }
  // std::cout << '\n';
  // for (int i = 1; i < cost_from_init.size(); i++) {
  //   std::cout << cost_from_init[i] << ' ';
  // }
  // std::cout << '\n';
  return response;
}

int main(int argc, char const *argv[]) {
  int c, e, l, p;
  int v, w;

  int count = 1;

  while (true) {
    std::cin >> c >> e >> l >> p;
    // c = numero de cidades
    // e = numero de estradas
    // l = onde a família está agora
    // p = numero maximo de pedagios

    if ( !(c | e | l | p) ) break;

    Graph graph(c, e, l, p);

    for (int i = 0; i < e; i++) {
      std::cin >> v >> w;
      graph.add(v, w);
    }
    // graph.print();

    std::string response("");

    std::cout << "Teste " << count++ << '\n';
    std::vector<int> v = graph.who_reach();
    std::sort(v.begin(), v.end());
    v.erase( unique( v.begin(), v.end() ), v.end() );
    if (v.size() == 0) {
      std::cout << "\n\n";
      continue;
    }
    for (auto x : v)
      response += std::to_string(x) + " ";
    response.pop_back(); std::cout << response << "\n\n";
  }
  return 0;
}
