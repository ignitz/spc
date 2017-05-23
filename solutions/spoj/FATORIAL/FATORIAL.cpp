/*
 * Yuri Niitsuma
 * 2011039023
 * http://br.spoj.com/problems/FATORIAL/
 * FATORIAL
 */

// A solução da da 7 segundos no SPOJ mas passou,
// então não otimizei

// dois com cinco da um zero
// 4 com 25 da dois zeros
// 2 com 50 da dois zeros

#include <iostream>


long long get_last_num (int n) {
	long long result = 1;

	for (long long i = 2; i <= n; i++) {
		result *= i;
		while (result % 10 == 0)
			result /= 10;
		result = result % 1000000;
	}
	return result % 10;
}

int main () {
	int n, instance_num = 1;
	while ( std::cin >> n ) {
		std::cout << "Instancia " << instance_num++ << '\n';
		std::cout << get_last_num(n) << "\n\n";
	}
	return 0;
}
