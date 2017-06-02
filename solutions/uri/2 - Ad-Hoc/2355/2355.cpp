/*
 * Yuri Niitsuma
 * 2011039023
 * https://www.urionlinejudge.com.br/judge/pt/problems/view/2355
 * Brasil e Alemanha
*/

#include <iostream>
#include <cmath>

int main(int argc, char const *argv[]) {
	int minutos;
	int golDaAlemanha;
	int golDoOscar;

	while(std::cin >> minutos){
		if(minutos == 0)
			break;

		// Brasil faz um gol a cada 90 minutos
		golDoOscar = (int) std::floor((((double) minutos)/90));
		// Alemanha faz 7 gols a cada 90 minutos
		golDaAlemanha = (int) std::ceil((7*((double) minutos))/(90));

		std::cout << "Brasil " << golDoOscar << " x " << "Alemanha " << golDaAlemanha << '\n';
	}
	return 0;
}
