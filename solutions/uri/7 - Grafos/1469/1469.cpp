/*
 * Yuri Diego Santos Niitsuma
 * 2011039023
 * https://www.urionlinejudge.com.br/judge/pt/problems/view/1469
 * URI1469
 */

#include <iostream>
#include <vector>
#include <queue>

#include <algorithm>

#define MAX_AGE 100

// function to help DEBUG
void print_colors(std::vector<int> v) {
  for (int i = 0; i < v.size(); i++) {
    std::cerr << v[i] << ' ';
  }
  std::cerr << '\n';
}

class Person {
public:
  int id; // like a name
  int age;

  Person (int id, int age);
  virtual ~Person ();
};

class Graph {
public:
  int size; // number os employee
  std::vector<Person> persons;
  std::vector<std::vector<int>> matrix;
  Graph (int n);
  virtual ~Graph ();

  void set_who_manage(int x, int y);
  void swap_employee(int x, int y);
  void manager_more_younger(int x);
  void printMatrix();
};

Graph::Graph (int n) {
  this->size = n;
  this->matrix.resize(n+1);

  int age;
  for (int i = 1; i <= n; i++) {
    std::cin >> age;
    std::cerr << age << ' ';
    this->persons.push_back(Person(i, age));
    this->matrix[i].resize(n+1, 0);
  }

}

void Graph::set_who_manage(int x, int y) {
  if (x == y) {
    // this->matrix[x][y] = 2;
  }
  else {
    this->matrix[x][y] = 1;
    this->matrix[y][x] = -1;
    this->matrix[y][0] = -1; // to inform if has a manager
  }
}

// swap lines and collums of matrix
void Graph::swap_employee(int x, int y) {
  std::cerr << "=================================" << '\n';
  std::cerr << "switching employee " << x << " with " << y << '\n';
  int temp;
  iter_swap(this->matrix.begin() + x, this->matrix.begin() + y);

  for (int i = 1; i <= this->size; i++) {
    temp = this->matrix[i][x];
    this->matrix[i][x] = this->matrix[i][y];
    this->matrix[i][y] = temp;
  }
  // iter_swap(this->matrix[x].begin() + y, this->matrix[y].begin() + x);
  std::cerr << "=================================" << '\n';
}

// search depth in here
void Graph::manager_more_younger(int x) {
  std::cerr << "=================================" << '\n';
  std::cerr << "asking who is more younger " << x << '\n';

  int vertice;
  std::vector<int> colors(this->size + 1, 0);

  int min_age = MAX_AGE + 1;

  colors[x] = 1;
  std::queue<int> q;
  q.push(x);

  while (!q.empty()) {
    print_colors(colors);
    vertice = q.front();
    q.pop();

    if (this->matrix[vertice][0] == 0)
      continue;
    for (int i = 1; i <= this->size; i++) {
      if (this->matrix[vertice][i] == -1 && !colors[i]) {
        colors[i] = 1;
        q.push(i);
        if (min_age > this->persons[i-1].age)
          min_age = this->persons[i-1].age;
      }

    }

  }

  if (min_age <= MAX_AGE) {
    std::cout << min_age << '\n';
    std::cerr << min_age << '\n';
  }
  else {
    std::cout << "*" << '\n';
    std::cerr << "*" << '\n';
  }
  std::cerr << "=================================" << '\n';

}

void Graph::printMatrix() {
  for (int i = 0; i < this->size; i++) { // Print ages
    std::cerr << this->persons[i].id << ' ' << this->persons[i].age << '\t';
  }
  std::cerr << "\n       ";

  for (int i = 1; i <= this->size; i++) {
    (i < 10) ? (i < 100) ? std::cerr << "  " : std::cerr << " " : std::cerr << "";
    std::cerr << i;
  }
  std::cerr << '\n';

  for (int i = 1; i <= this->size; i++) {
    (i < 10) ? (i < 100) ? std::cerr << "  " : std::cerr << " " : std::cerr << "";
    std::cerr << i << " --> ";
    for (int j = 1; j <= this->size; j++) {
      if (this->matrix[i][j] != -1)
        std::cerr << " ";
      std::cerr << this->matrix[i][j] << " ";
    }
    std::cerr << '\n';
  }
}

Graph::~Graph () {
  // std::cerr << "\nGraph deleted\n";
}

Person::Person (int id, int age) {
  this->id = id;
  this->age = age;
}

Person::~Person () {
  // std::cerr << "\nPerson deleted\n";
}

int main(int argc, char const *argv[]) {

  // input vars
  int n, m, p;
  int x, y;
  char option;
  int a, b;
  int e;

  while (std::cin >> n >> m >> p) {

    Graph graph(n);

    for (int i = 0; i < m; i++) {
      std::cin >> x >> y;
      graph.set_who_manage(x, y);
    }
    // DEBUG
    graph.printMatrix()
    ;

    for (int i = 0; i < p; i++) {
      std::cin >> option;
      switch (option) {
        case 'T':
        std::cin >> a >> b;
        graph.swap_employee(a, b);
        break;
        case 'P':
        std::cin >> e;
        graph.manager_more_younger(e);
        break;
        default:
        std::cerr << "shit happens" << '\n';;
      }
    }

    // DEBUG
    graph.printMatrix();

  }
  return 0;
}
