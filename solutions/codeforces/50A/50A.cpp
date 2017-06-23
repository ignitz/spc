/*
 * Yuri Niitsuma
 * 2011039023
 * http://codeforces.com/problemset/problem/50/A
 * A. Domino piling
*/

// O melhor jeito de encaixar as peças são se todos forem
// colocados juntos na direção horizontal ou vertical.
// Se sobrar um quadrado, aí completa na direção perpendicular a escolhida.
// Resumindo, se utilizarmos o método acima, cada peça ocupará duas posições.
// Peças máxima = quantidades de posições (m x n) dividido por dois.

#include <iostream>
#include <cmath>

int main(int argc, char const *argv[]) {
	int m,n;
	std::cin >> m >> n;
	// floor = insanity check
	std::cout << std::floor((m*n)/2) << '\n';
	return 0;
}
