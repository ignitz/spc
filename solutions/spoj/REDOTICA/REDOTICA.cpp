/*
 * Yuri Niitsuma
 * 2011039023
 * http://br.spoj.com/problems/REDOTICA/
 * REDOTICA
 */

// Using Kruskal, easy

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

// class Edge
///////////////////////////////////////////////////////////////////

class Edge {
private:
  long long weight;
  std::pair <long long, long long> v;

public:
  Edge (long long u, long long v, long long weight);
  virtual ~Edge ();
  long long getWeight ();
  long long first ();
  long long second ();

  bool operator< (const Edge &other) const { // For Sort
    if (weight != other.weight)
      return weight < other.weight;
    if (v.first != other.v.first)
      return v.first < other.v.first;
    return v.second < other.v.second;
  }
  static bool sortWithoutWeight(const Edge &a, const Edge &b) {
    if (a.v.first != b.v.first)
      return a.v.first < b.v.first;
    return a.v.second < b.v.second;
  }
};

Edge::Edge (long long u, long long v, long long weight) {
  this->weight = weight;
  this->v = (u < v) ? std::make_pair(u, v) : std::make_pair(v, u);
}

Edge::~Edge () {}

long long Edge::getWeight () { return this->weight; }

long long Edge::first () { return this->v.first; }

long long Edge::second () { return this->v.second; }

// class Graph
///////////////////////////////////////////////////////////////////
class Graph {
private:
  long long n;
  long long m;
  std::vector<Edge> edges;

public:
  Graph (long long n, long long m);
  virtual ~Graph ();
  void addEdge(long long u, long long v, long long w);
  void sortEdges();
  void sortEdges_NoWeight();
  void minimumSpanningTree ();
  void printEdges ();
  void printEdges_withWeight ();
};

Graph::Graph (long long n , long long m) {
  this->n = n;
  this->m = m;
}

Graph::~Graph () {
  // std::cerr << "Graph deleted" << '\n';
}

void Graph::addEdge(long long u, long long v, long long w) {
  this->edges.push_back(Edge(u, v, w));
}

void Graph::sortEdges() {
  std::sort(this->edges.begin(), this->edges.end());
}

void Graph::sortEdges_NoWeight() {
  std::sort(this->edges.begin(), this->edges.end(), Edge::sortWithoutWeight);
}

// Using Kruskal
void Graph::minimumSpanningTree () {
  this->sortEdges();

  Graph tree(this->n, this->n-1);

  std::vector<long long> sets(this->n+1, 0);
  for (long long i = 0; i <= this->n; i++) {
    sets[i] = i;
  }

  long long u, v, count, aux;
  count = 0; // if n-1  break
  for (auto edge : this->edges) {
    u = edge.first();
    v = edge.second();
    if (sets[u] != sets[v]) {
      if (sets[u] < sets[v]) {
        aux = sets[v];
        sets[v] = sets[u];
        for (long long i = 0; i <= this->n; i++) {
          if (sets[i] == aux) sets[i] = sets[u];
        }
      }
      else {
        aux = sets[u];
        sets[u] = sets[v];
        for (long long i = 0; i <= this->n; i++) {
          if (sets[i] == aux) sets[i] = sets[v];
        }
      }
      count++;
      tree.addEdge(u, v, edge.getWeight());
    }
    // for (long long i = 0; i <= this->n; i++)
    //   std::cout << sets[i] << " ";
    // std::cout << '\n';
    if (count >= this->n - 1) break;
  }
  // for (long long i = 0; i <= this->n; i++)
  //   std::cout << sets[i] << " ";
  // std::cout << '\n';
  tree.sortEdges_NoWeight();
  tree.printEdges();
}

void Graph::printEdges () {
  std::vector<Edge>::iterator it;
  for (it = edges.begin(); it != edges.end(); it++) {
    std::cout << it->first() << ' ' <<
    it->second() << '\n';
  }
  std::cout << '\n';
}

void Graph::printEdges_withWeight () {
  std::vector<Edge>::iterator it;
  std::cout << "Edges:" << '\n';
  for (it = edges.begin(); it != edges.end(); it++) {
    std::cout << it->first() << '\t' <<
    it->second() << '\t' <<
    it->getWeight() << '\n';
  }
}


int main(int argc, char const *argv[]) {
  long long n, m, x, y, z;
  int num_teste = 1;

  while (true) {
    std::cin >> n >> m;
    if ( !(n | m) ) break;

    Graph graph(n, m);

    for (long long i = 0; i < m; i++) {
      std::cin >> x >> y >> z;
      graph.addEdge(x, y, z);
    }

    std::cout << "Teste " << num_teste++ << '\n';
    graph.minimumSpanningTree();
  }
  return 0;
}
