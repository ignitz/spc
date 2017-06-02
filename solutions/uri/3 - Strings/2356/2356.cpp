/*
 * Yuri Niitsuma
 * 2011039023
 * https://www.urionlinejudge.com.br/judge/pt/problems/view/2356
 * 2356 - Bactéria I
*/

#include <iostream>
#include <string>

int main(int argc, char const *argv[]) {
	std::string d, s;
	std::size_t found;

	while (std::cin >> d) {
		std::cin >> s;
		found = d.find(s);
		if (found!=std::string::npos)
			std::cout << "Resistente" << '\n';
		else
			std::cout << "Nao resistente" << '\n';
	}
	return 0;
}
