/*
 * Yuri Diego Santos Niitsuma
 * 2011039023
 * http://www.spoj.com/problems/CANDY/
 * CANDY
 */

 // Problema simples, pega tudo e divide igualmente.
 // Depois calcula o fluxo de entrada de saída dos
 // pacotes e divide por 2.

#include <iostream>
#include <vector>

int main(int argc, char const *argv[]) {
  int n;
  int input;

  int sum_of_elems;
  int amount;

  while (true) {
    std::cin >> n;
    std::vector<int> v;

    if (n == -1) break;

    for (int i = 0; i < n; i++) {
      std::cin >> input;
      v.push_back(input);
    }
    sum_of_elems = 0;
    for (auto e : v)
      sum_of_elems += e;

    if (sum_of_elems % n != 0) { // Vai dar briga
      std::cout << -1 << '\n';
      continue;
    }

    amount = 0;
    for (auto e : v)
      amount += ((e - sum_of_elems / n) >= 0) ? (e - sum_of_elems / n) : (sum_of_elems / n - e);
    std::cout << amount/2 << '\n';

  }
  return 0;
}
