/*
 * Yuri Diego Santos Niitsuma
 * 2011039023
 * https://www.urionlinejudge.com.br/judge/pt/problems/view/1522
 * URI1522
 */

#include <iostream>
#include <vector>

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

  void add_card_A(int);
  void add_card_B(int);
  void add_card_C(int);

  int got_to_win();
};

Deck::Deck(int n) {
  this->n=n;
}

Deck::~Deck() {}

void Deck::add_card_A(int value){
  this->a.push_back(value);
}
void Deck::add_card_B(int value){
  this->b.push_back(value);
}
void Deck::add_card_C(int value){
  this->c.push_back(value);
}

int Deck::got_to_win() {
  // Em cada rodada, o jogador pode remover
  // qualquer combinação de cartas que estejam
  // no topo da pilha (pode escolher 1, 2 ou
  // até 3 cartas) cuja soma dos valores
  // seja múltipla de 3.
  // TODO make a way to predict if is possible
  return 1;
}

int main(int argc, char const *argv[]) {
  int n; // numero de cartas

  while (true) {
    std::cin >> n;
    if (n == 0)
      break;

    Deck cards = Deck(n);

    int input;
    for (size_t i = 0; i < n; i++) {
      std::cin >> input;
      cards.add_card_A(input);
      std::cin >> input;
      cards.add_card_B(input);
      std::cin >> input;
      cards.add_card_C(input);
    }

    std::cout << (cards.got_to_win()) << '\n';
    // del cards;
  }
  std::cin >> n;

  return 0;
}
