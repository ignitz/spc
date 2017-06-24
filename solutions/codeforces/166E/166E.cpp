/*
 * Yuri Niitsuma
 * 2011039023
 * http://codeforces.com/problemset/problem/166/E
 * E. Tetrahedron
*/

// A estratégia é simples. Conta a quantidade de caminhos até
// o ponto X a cada iteração.
// prev{i}, quantidade da iteração anterior
// aux{i}, variável auxiliar pra atualizar o prev{i} no final da iteração

// Utilizei long long ora efetuar MOD no final da soma, pois com int teria
// que efetuar mod a cada operação na soma de dois elementos

#include <iostream>

// Número primo mais próximo do overflow do int
#define MOD 1000000007

long long get_many_ways(long long n) {
  long long auxA, auxB, auxC, auxD;
  long long prevA, prevB, prevC, prevD;

  prevA = 0;
  prevB = 0;
  prevC = 0;
  prevD = 1;
  for(long long i = 1; i < n; i++) {
    auxA = prevB + prevC + prevD;
    auxB = prevA + prevC + prevD;
    auxC = prevA + prevB + prevD;
    auxD = prevA + prevB + prevC;
    prevA = auxA % MOD;
    prevB = auxB % MOD;
    prevC = auxC % MOD;
    prevD = auxD % MOD;
  }

  // Último voltando ao ponto D
  long long total = (prevA + prevB + prevC) % MOD;
  return total;
}

int main(int argc, char const *argv[]) {
  long long n;
  std::cin >> n;
  std::cout << get_many_ways(n) << '\n';
  return 0;
}
