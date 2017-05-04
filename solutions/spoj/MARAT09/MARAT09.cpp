/*
 * Yuri Niitsuma
 * 2011039023
 * http://br.spoj.com/problems/MARAT09/
 * MARAT09
 */

#include <iostream>
int main(int argc, char *argv[])
{
	// Postos de água e a distância intermediária máxima de um atleta
	int n, m;
	int temp, aux;
	aux = 0;

	std::cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		std::cin >> temp;
		if (temp - aux > m) {
			std::cout << 'N' << std::endl;
			return 0;
		}
		aux = temp;
	}

	if (42195 - aux > m) {
		std::cout << 'N' << std::endl;
		return 0;
	}

	std::cout << 'S' << std::endl;	

	return 0;
}
