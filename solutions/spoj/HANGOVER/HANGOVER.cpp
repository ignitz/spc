/*
 * Yuri Niitsuma
 * 2011039023
 * http://www.spoj.com/problems/HANGOVER/
 * HANGOVER
*/

#include <iostream>

int main(int argc, char const *argv[]) {
  double supremo;
  double partial_sum;

  while (std::cin >> supremo) {
    if (supremo == 0.00)
      break;
    partial_sum = 0.0;

    // while (partial_sum < supremo) {
    //   partial_sum
    // }
    int i;
    for (i = 2; partial_sum < supremo; ++i) {
      partial_sum += 1.0/i;
    }
    std::cout << (i - 2) << " card(s)" << '\n';
  }
  return 0;
}