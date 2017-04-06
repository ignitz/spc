/*
 * Yuri Diego Santos Niitsuma
 * 2011039023
 * https://www.urionlinejudge.com.br/judge/pt/problems/view/1522
 * URI1522
 */

#include <iostream>
#include <vector>
#include <algorithm>

#define None 0
#define only_A 1
#define only_B 2
#define only_C 3
#define A_and_B 4
#define B_and_C 5
#define A_and_C 6
#define A_B_C 7
#define Done 8

#define PRINTAO std::cout <<
// #define PRINTAO //

// A entrada é composta por várias instâncias Cada
// instância é iniciada por um inteiro N (0 ≤ N ≤ 100),
// que identifica o número de cartas em cada pilha.
// A entrada termina quando N = 0. Cada uma das N
// linhas seguintes contém três inteiros A, B e C,
// que descrevem os valores numéricos das cartas em
// um nível da pilha (0 ≤ A, B, C ≤  9). As pilhas
// são descritas do topo até o fundo.

class Deck {
private:
  int n;
  std::vector<int> a;
  std::vector<int> b;
  std::vector<int> c;

public:
  Deck (int n);
  ~Deck ();

  int got_to_win();
  int analyze();
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
  std::reverse(this->a.begin(), this->a.end());
  std::reverse(this->b.begin(), this->b.end());
  std::reverse(this->c.begin(), this->c.end());

}

Deck::~Deck() {
  // std::cerr << "Deck deleted" << '\n';
}

int Deck::got_to_win() {
  while (true) {
    switch (this->analyze()) {
      // Uma carta multiplo de 3
      case None:
        return 0;
      case only_A: // A
        PRINTAO "only_A\n" << this->a.back() << '\n';
        this->a.pop_back();
        break;
      case only_B: // B
        PRINTAO "only_B\n" << this->b.back() << '\n';
        this->b.pop_back();
        break;
      case only_C: // C
        PRINTAO "only_C\n" << this->c.back() << '\n';
        this->c.pop_back();
        break;
      // Duas cartas 2k + 1k
      case A_and_B:
        PRINTAO "A_and_B\n" << this->a.back() << '\n' << this->b.back() << '\n';
        this->a.pop_back();
        this->b.pop_back();
        break;
      case B_and_C:
        PRINTAO "B_and_C" << this->b.back() << '\n' << this->c.back() << '\n';
        this->b.pop_back();
        this->c.pop_back();
        break;
      case A_and_C:
        PRINTAO "A_and_C" << '\n' << this->a.back() << '\n' << this->c.back() << '\n';
        this->a.pop_back();
        this->c.pop_back();
        break;
      case A_B_C: // Três cartas 1k 1k 1k
        PRINTAO "A_B_C" << '\n' << this->a.back() << '\n' << this->b.back() << '\n' << this->c.back() << '\n';
        this->a.pop_back();
        this->b.pop_back();
        this->c.pop_back();
        break;
      case Done:
        return 1;
        break;
      default: // Deu merda
        break;
    }
  }
}

int Deck::analyze() {
  int a, b, c;
  a = b = c = -1;
  if (!this->a.empty())
    a = this->a.back();
  if (!this->b.empty())
    b = this->b.back();
  if (!this->c.empty())
    c = this->c.back();

  if (a + b + c == -3)
    return Done;

  // Uma carta multiplo de 3
  if (a >= 0 && a % 3 == 0)
    return only_A;
  if (b >= 0 && b % 3 == 0)
    return only_B;
  if (c >= 0 && c % 3 == 0)
    return only_C;

  if ((a >= 0 && b >= 0) && (a + b) % 3 == 0)
    return A_and_B;
  if ((b >= 0 && c >= 0) && (b + c) % 3 == 0)
    return B_and_C;
  if ((a >= 0 && c >= 0) && (a + c) % 3 == 0)
    return A_and_C;
  if (((a >= 0 && b >= 0 && c >= 0)) && (a + b + c) % 3 == 0)
    return A_B_C;
  PRINTAO "Deu None" << '\n';
  return None;
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
