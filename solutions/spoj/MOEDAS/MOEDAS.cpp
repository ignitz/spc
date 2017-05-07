/*
 * Yuri Niitsuma
 * 2011039023
 * http://br.spoj.com/problems/MOEDAS/
 * MOEDAS
 */

#include <iostream>
#include <vector>
#include <limits>

// Da pau com INT_MAX...
#define MAX 50001

int get_max_coins (int m, int n, std::vector<int> C) {
    std::vector<int> D (m+1);
    D[0] = 0;
    for(int i=1; i <= m; i++) {
        D[i] = MAX;
        for(int j=0; j < n; j++) {
            if(i-C[j] >= 0) {
                D[i] = std::min(D[i], D[i-C[j] ] + 1);
            }
        }
    }
    return D[m];
}

int main(){
	int m, n;
	int aux, result;

  while (std::cin >> m >> n) {
    if ( !(m | n) ) return 0;
    std::vector<int> C;

		for (int i = 0; i < n; i++) {
			std::cin >> aux;
			C.push_back(aux);
		}
		result = get_max_coins (m, n, C);
		(result == MAX) ? std::cout << "Impossivel" << '\n' : std::cout << result << '\n';
	}
	return 0;
}
