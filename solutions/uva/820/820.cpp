/*
* Yuri Niitsuma
* 2011039023
* https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=761
* UVa 820 - Internet Bandwidth
*/

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <limits>
#include <tuple>
#include <algorithm>


bool mycomp(const std::tuple<int, int, int> & a, const std::tuple<int, int, int> & b)
{
  return std::get<2>(a) < std::get<2>(b);
}

// Mesma ideia do primeiro MTOTALF do spoj
// Utilizando FordFulkerson

class Graph {
private:
  int n;
  std::vector<std::vector<int>> edges;
  std::vector<std::vector<int>> capacity;
  std::vector<std::vector<int>> rCap;
  std::vector<int> parent;
  bool bfs(int source_v, int destiny_v);

public:
  Graph (int n);
  virtual ~Graph ();

  void set_weight (int u, int v, int weight);
  int FordFulkerson (int source_v, int destiny_v);
  void printRCap ();
};

Graph::Graph (int n) {
  this->n = n;
  this->edges.resize(this->n+1);
  this->capacity.resize(this->n+1, std::vector<int>(this->n+1, 0));

  this->rCap.resize(this->n+1, std::vector<int>(this->n+1, 0));
  this->parent.resize(this->n+1, -1);
}

Graph::~Graph () {}

void Graph::set_weight(int u, int v, int weight) {
  // if already have, just plus the weight
  this->edges[u].push_back(v);
  this->edges[v].push_back(u);
  this->capacity[u][v] += weight;
  this->capacity[v][u] += weight;
}

bool Graph::bfs( int source_v, int destiny_v ) {
  // std::cerr << "\033[1;37m" << "exec bfs" << '\n' << "\033[0m";
  // std::vector<bool> colors;
  // colors.resize(this->n, false);
  bool response = false;
  int u;

  std::queue<int> queue;
  queue.push(source_v);
  // colors[source_v] = true;

  std::fill(this->parent.begin(), this->parent.end(), -1);
  parent[source_v] = source_v;

  while (!queue.empty()) {
    u = queue.front();
    // std::cerr << "\033[1;31m" << u << ' ' << "\033[0m";
    queue.pop();
    if (u == destiny_v) { // no return, because must finish theri job
      // std::cerr << "\033[1;31m" << '\n' << "\033[0m";
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
  // std::cerr << "\033[1;31m" << '\n' << "\033[0m";
  return response;
}

int Graph::FordFulkerson( int source_v, int destiny_v ) {
  // std::cerr << "\033[1;37m" << "exec FordFulkerson" << '\n' << "\033[0m";
  int response = 0;
  int path_flow;

  for (int i = 1; i <= this->n; i++) {
    for (int j = 1; j <= this->n; j++) {
      this->rCap[i][j] = this->capacity[i][j];
    }
  }

  // std::fill(this->parent.begin(), this->parent.end(), -1);

  while (this->bfs(source_v, destiny_v)) {

    for (int i = 1; i <= this->n; i++) {
      // std::cerr << "\033[1;36m" << this->parent[i] << ' ' << "\033[0m";
    }
    // std::cerr << "\033[1;31m" << '\n' << "\033[0m";
    // printRCap();

    // Find minimum residual capacity of the capacity along the
    // path filled by BFS. Or we can say find the maximum flow
    // through the path found.
    path_flow = std::numeric_limits<int>::max();
    int s = destiny_v;

    while (s != source_v) {
      // std::cerr << "\033[1;34m" << "path_flow " << path_flow  << "\trCap[" << parent[s] << "][" << s << "] " << this->rCap[parent[s]][s] << '\n' << "\033[0m";
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

    // std::cerr << "\033[1;32m" << "get path_flow " << path_flow << '\n' << "\033[0m";
    response += path_flow; // Add path flow to overall flow

    // std::cerr << "\033[1;33m" << "max_flow " << response << '\n' << "\033[0m";
  }
  // std::cerr << "\033[1;33m" << "response " << response << '\n' << "\033[0m";
  return response;
}

void Graph::printRCap() {
  for (int i = 0; i <= this->n; i++) {
    std::cout << i << " --> ";
    for (auto x : this->edges[i])
    std::cout << x << " ";
    std::cout << '\n';
  }
  // for (int i = 0; i <= this->n; i++) {
  //   for (int j = 0; j <= this->n; j++) {
  //     std::cout << this->rCap[i][j] << '\t';
  //   }
  //   std::cout << '\n';
  // }
}

int main(int argc, char const *argv[]) {
  int n;
  int s, t, c;
  int a, b, f;
  int count = 1;

  while (std::cin >> n) {
    if (n == 0) break;
    Graph graph(n);

    std::cin >> s >> t >> c;

    for (int i = 0; i < c; i++) {
      std::cin >> a >> b >> f;
      graph.set_weight(a, b, f);
    }

    std::cout << "Network " << count++ << '\n';
    std::cout << "The bandwidth is " << graph.FordFulkerson(s, t) << '.' << std::endl << std::endl;
    // graph.printRCap();

    // print_debug();

  }

  return 0;
}
