/*
 * Yuri Niitsuma
 * 2011039023
 * http://br.spoj.com/problems/BIT/
 * BIT
 */

#include <iostream>
int main(){
	int v;
  int count = 1;
  while (std::cin >> v) {
    if (v == 0) break;
    std::cout << "Teste " << count++ << '\n';
    // B$ 50,00, B$10,00, B$5,00 e B$1,00
    std::cout << (v / 50) << ' ';
    v %= 50;
    std::cout << (v / 10) << ' ';
    v %= 10;
    std::cout << (v / 5) << ' ';
    v %= 5;
    std::cout << (v / 1) << ' ';
    // v %= 1;
    std::cout << "\n\n";
  }
  return 0;
}
