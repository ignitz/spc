/*
 * Yuri Diego Santos Niitsuma
 * 2011039023
 * http://br.spoj.com/problems/TESOUR11/
 * TESOUR11
 */

#include <iostream>

int main()
{
  int N, K;
  int X, Y, D;
  std::cin >> N >> K;

  int a[N][N];
  for (int i = 0; i < N; i++)
   for (int j = 0; j < N; j++)
    a[i][j] = 0;

  int max = 0;

   // Marca no mapa os possíveis locais
  for (int i = 0; i < K; i++) {
    std::cin >> X >> Y >> D;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (abs(i- X) + abs(j - Y) == D) {
          a[i][j] += 1;
          if (a[i][j] > max)
            max = a[i][j];
        }
      }
    }
  }

  // Get the results
  int count = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (a[i][j] == max) {
        if (count == 0) {
          X = i;
          Y = j;
          count = 1;
        }
        else {
          std::cout << "-1 -1" << '\n';
          return 0;
        }
      }
    }
  }

  std::cout << X << " " << Y << '\n';

  return 0;
}
