/*
 * Yuri Niitsuma
 * 2011039023
 * http://br.spoj.com/problems/POODLEMG/
 * POODLEMG
 */

#include <iostream>

inline void generate_poodle(int pages, int rest) {
	if (rest) pages++;

	std::string response;

	if (pages < 6) {
		std::cout << "Poodle" << '\n';
	}
	else if (pages >= 6 && pages <= 20) {
		response += "P";
		for (int i = 1; i <= pages - 4; i++) {
			response += "o";
		}
		response += "dle";
		std::cout << response << '\n';
	}
	else {
		std::cout << "Poooooooooooooooodle" << '\n';
	}
}

int main(){
	int n, p;
	while (std::cin >> n >> p) {
		if (n == 0) break;
		generate_poodle(n/p, n % p);
	}

	return 0;
}
