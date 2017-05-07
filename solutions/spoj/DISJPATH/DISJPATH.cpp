/*
 * Yuri Niitsuma
 * 2011039023
 * http://www.spoj.com/problems/DISJPATH/
 * DISJPATH
 */

// INCOMPLETO, depois tento

#include <iostream>
#include <vector>

class Graph {
private:
  int n; // numero de vértices
  int st_no; // students_no
  std::vector<std::vector<int>> capacity;

public:
  Graph (int x1, int x2);
  virtual ~Graph ();
};

Graph::Graph (int x1, int x2) {
  this->n = x1;
  this->st_no = x2;
  this->capacity.resize( n + 1 , std::vector<int> ( n + 1 , 0 ) );
}

Graph::~Graph () {}

int main(int argc, char const *argv[]) {
  int n, k;
  int counter = 1;

  while (std::cin >> n >> k) {
    if ( !(n | k) ) break;

    Graph graph(n, k);

    for (int i = 0; i < n; i++) {

    }

    std::cout << "Case " << counter++ << '\n';
    // TODO
  }
  return 0;
}
