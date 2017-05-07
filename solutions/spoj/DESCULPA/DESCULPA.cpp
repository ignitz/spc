/*
 * Yuri Niitsuma
 * 2011039023
 * http://br.spoj.com/problems/DESCULPA/
 * DESCULPA
 */

// Problema da mochila ;-)

#include <iostream>
#include <vector>
#include <utility>

// Problema da mochila (KnapSack)
int solve( int n, int m, std::vector< std::pair<int, int> >& dados ) {
  std::vector<std::vector<int>> D (n + 1, std::vector<int> (m + 1, 0));

  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      if (i == 0 || j == 0) continue;
      D[i][j] = (std::get<0>(dados[i-1]) <= j) ?
         std::max(std::get<1>(dados[i-1]) + D[i-1][j-std::get<0>(dados[i-1])],  D[i-1][j])
         : D[i-1][j];
    }
  }
  return D[n][m];
}

int main(){
  int c, f;
  int n, d;
  int count = 1;

  // comprimento do cartão em caracteres (8 <= C <= 1000) e o número de frases coletadas (1 <= F <= 50)
  while (std::cin >> c >> f) {
    if ( !(c | f) ) break;

    std::vector< std::pair<int, int> > dados;


    for (int i = 0; i < f; i++) {
      //  o número de caracteres na frase (8 <= N <= 200) e quantas vezes a palavra ‘desculpe’ ocorre na frase (1 <= D <= 25).
      std::cin >> n >> d;
      dados.push_back(std::make_pair(n, d));
    }

    std::cout << "Teste " << count++ << '\n';
    std::cout << solve( f , c, dados ) << "\n\n";
  }

  return 0;
}
