/*
 * Yuri Niitsuma
 * 2011039023
 * https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=945
 * 10004 - Bicoloring
*/

// Só descobrir se o grafo é bipartido
// https://www.geeksforgeeks.org/unordered_map-in-cpp-stl/

#include <iostream>
#include <vector>
#include <unordered_map>

class Graph
{
private:
  int n;
  std::unordered_map<int, std::vector<int>> edges;
  std::unordered_map<int, bool> visited;
  std::unordered_map<int, int> color;

public:
  Graph(int n);
  ~Graph();
  void addEdge(int u, int v);
  bool isBiparttite(int v);
};

Graph::Graph(int n)
{
  this->n = n;
  for (int i = 1; i <= n; i++)
  {
    this->edges[i] = std::vector<int>();
    this->visited[i] = false;
    this->color[i] = 0;
  }
  this->visited[1] = true;
  this->color[1] = 0;
}

Graph::~Graph()
{
  for (auto &edge : this->edges)
    edge.second.clear();
  this->visited.clear();
  this->color.clear();
  this->edges.clear();
}

void Graph::addEdge(int u, int v)
{
  this->edges[u].push_back(v);
  this->edges[v].push_back(u);
}

bool Graph::isBiparttite(int v)
{
  for (auto &u : this->edges[v])
  {
    if (this->visited[u] == false)
    {
      this->visited[u] = true;
      this->color[u] = !this->color[v];

      if (!this->isBiparttite(u))
        return false;
    }
    else if (this->color[u] == this->color[v])
    {
      return false;
    }
  }
  return true;
}

int main()
{
  using namespace std;

  int n, m;
  int u, v;
  while (true)
  {
    cin >> n;
    if (n <= 0)
      break;
    cin >> m;
    Graph graph(n);
    for (int i = 0; i < m; i++)
    {
      cin >> u >> v;
      graph.addEdge(u, v);
    }
    if (graph.isBiparttite(1))
      cout << "BICOLORABLE." << '\n';
    else
      cout << "NOT BICOLORABLE." << '\n';
  }
  return 0;
}
