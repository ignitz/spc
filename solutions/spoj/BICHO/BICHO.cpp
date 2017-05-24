/*
 * Yuri Niitsuma
 * 2011039023
 * http://br.spoj.com/problems/BICHO/
 * BICHO
*/

#include <iostream>
#include <iomanip> // std::setprecision

// #define GENERATE_TEST

double get_prize(double value, long long number, long long result) {
	// se M e N têm os mesmos quatro últimos dígitos (milhar, centena, dezena e unidade), o apostador recebe V × 3000 (por exemplo, N = 99301 e M = 19301);
	if ((number % 10000) == (result % 10000))
		return double(value*3000);
	// se M e N têm os mesmos três últimos dígitos (centena, dezena e unidade), o apostador recebe V × 500 (por exemplo, N = 38944 e M = 83944);
	if ((number % 1000) == (result % 1000))
		return double(value*500);
	// se M e N têm os mesmos dois últimos dígitos (dezena e unidades), o apostador recebe V × 50 (por exemplo, N = 111 e M = 552211);
	if ((number % 100) == (result % 100))
		return double(value*50);
	// se M e N têm os dois últimos dígitos no mesmo grupo, correspondendo ao mesmo animal, o apostador recebe V × 16 (por exemplo, N = 82197 and M = 337600);

	number %= 100;
	result %= 100;
	// XGH for 0 because make wonderful things, but not #SQN
	if (number == 0) number = 100;
	if (result == 0) result = 100;

	if ( ((number + 3) / 4) == ((result + 3) / 4) )
		return double(value*16);

	// se nenhum dos casos acima ocorrer, o apostador não recebe nada.
	return double(0);
}

int test() {
	for (size_t i = 0; i < 1000; i++) {
		double f2 = static_cast <double> (rand()) / (static_cast <double> (RAND_MAX/1000));
		std::cout << std::setprecision(2) << std::fixed << f2 << ' ';
		std::cout << (rand() % 1000000) << ' ' << (rand() % 1000000) << '\n';
	}
	return 0;
}

int main(){
	#ifdef GENERATE_TEST
	test();
	return 0;
	#endif
	double v;
	long long n, m;
	while (std::cin >> v >> n >> m) {
		if (!(n | m) && v == 0.0) break;
		std::cout << std::setprecision(2) << std::fixed << get_prize(v, n, m) << '\n';
	}
	return 0;
}
