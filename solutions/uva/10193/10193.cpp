/*
 * Yuri Niitsuma
 * 2011039023
 * https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1134
 * 10193 - All You Need Is Love
*/

#include <iostream>
#include <bitset>
#include <algorithm>

std::string whatIsLove(unsigned long s, unsigned long l)
{
  return std::__gcd(s, l) > 1 ? "All you need is love!" : "Love is not all you need!";
}

int main()
{
  int n;
  std::bitset<64> firstLine, secondLine;
  unsigned long s, l;

  std::cin >> n;
  for (int i = 0; i < n; i++)
  {
    std::cin >> firstLine;
    std::cin >> secondLine;
    s = firstLine.to_ulong();
    l = secondLine.to_ulong();
    std::cout << "Pair #" << (i + 1) << ": " << whatIsLove(s, l) << '\n';
  }

  return 0;
}
