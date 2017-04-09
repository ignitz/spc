/*
 * Yuri Diego Santos Niitsuma
 * 2011039023
 * https://www.urionlinejudge.com.br/judge/pt/problems/view/1522
 * URI1522
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

#define None 0
#define only_A 1
#define only_B 1 << 1
#define only_C 1 << 2
#define A_and_B 1 << 3
#define B_and_C 1 << 4
#define A_and_C 1 << 5
#define A_B_C 1 << 6
// #define Done

// Print bits
void printBinary(int value) {
  std::bitset<8> x(value);
  std::cout << x << '\n';
}

// Class of decks
class Deck {
private:
  int n;
  std::vector<int> a;
  std::vector<int> b;
  std::vector<int> c;
  std::vector<std::vector<std::vector<bool>>> adjgraph;

public:
  Deck (int n);
  ~Deck ();

  int got_to_win();
  int analyze(int, int, int);
  void printMatrix();
};

Deck::Deck(int n) {
  this->n=n;

  int input;
  for (size_t i = 0; i < n; i++) {
    std::cin >> input;
    this->a.push_back(input);
    std::cin >> input;
    this->b.push_back(input);
    std::cin >> input;
    this->c.push_back(input);
  }
  this->a.push_back(-1);
  this->b.push_back(-1);
  this->c.push_back(-1);

  // Create a matrix n + 1 x n + 1 x n + 1
  this->adjgraph.resize(n + 1);
  for (auto& x : this->adjgraph) {
    x.resize(n + 1);
    for (auto& y : x) {
      y.resize(n + 1);
      std::fill(y.begin(), y.end(), false);
    }
  }

  // initial config of 3 decks
  this->adjgraph[0][0][0] = 1;
}

Deck::~Deck() {
  // std::cerr << "Deck deleted" << '\n';
}

int Deck::got_to_win() {
  int response;
  int n = this->n;

  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      for (int k = 0; k <= n; k++) {
        if (this->adjgraph[i][j][k]) {
          response = this->analyze(this->a[i],this->b[j],this->c[k]);
          // DEBUG std::cout << "[" << n-i << "] " <<"[" << n-j << "] " <<"[" << n-k << "] --> ";
          // DEBUG std::cout << this->a[i] << " " <<this->b[j] << " " <<this->c[k] << " --> ";
          // DEBUG printBinary(response);
          if ((only_A & response) )
            this->adjgraph[i+1][j][k] = 1;
          if ((only_B & response) )
            this->adjgraph[i][j+1][k] = 1;
          if ((only_C & response) )
            this->adjgraph[i][j][k+1] = 1;
          if ((A_and_B & response) )
            this->adjgraph[i+1][j+1][k] = 1;
          if ((A_and_C & response) )
            this->adjgraph[i+1][j][k+1] = 1;
          if ((B_and_C & response) )
            this->adjgraph[i][j+1][k+1] = 1;
          if ((A_B_C & response) )
            this->adjgraph[i+1][j+1][k+1] = 1;
        }
      }
    }
  }
  // DEBUG this->printMatrix();

  return this->adjgraph[n][n][n];
}

// Check the possibilities
int Deck::analyze(int a, int b, int c) {

  int r = None;

  // Uma carta multiplo de 3
  if (a % 3 == 0 && a >= 0)
    r |= only_A;
  if (b % 3 == 0 && b >= 0)
    r |= only_B;
  if (c % 3 == 0 && c >= 0)
    r |= only_C;

  if ((a + b) % 3 == 0 && a >= 0 && b >= 0)
    r |= A_and_B;
  if ((b + c) % 3 == 0 && b >= 0 && c >= 0)
    r |= B_and_C;
  if ((a + c) % 3 == 0 && a >= 0 && c >= 0)
    r |= A_and_C;
  if ((a + b + c) % 3 == 0 && a >= 0 && b >= 0 && c >= 0)
    r |= A_B_C;
  return r;
}

void Deck::printMatrix() {
  int n = this->n + 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        std::cout << this->adjgraph[i][j][k] << ' ';
      }
      std::cout << '\n';
    }
    std::cout << "--------------" << '\n';
  }
}

int main(int argc, char const *argv[]) {
  int n; // numero de cartas

  while (true) {
    std::cin >> n;
    if (n == 0)
      break;

    Deck cards = Deck(n);

    std::cout << (cards.got_to_win()) << '\n';
    // del cards;
  }

  return 0;
}
