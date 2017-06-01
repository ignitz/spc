/*
 * Yuri Niitsuma
 * 2011039023
 * https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1251
 * Uva 10310 - Dog and Gopher
*/

#include <iostream>
#include <iomanip> // std::setprecision

int main(int argc, char const *argv[]) {
	int n;
	double gopherX, gopherY, dogX, dogY;

	double holeX, holeY;
	double escapeX, escapeY;
	bool canEscape;

	while (std::cin >> n >> gopherX >> gopherY >> dogX >> dogY) {
		canEscape = false;

		while (n--) {
			std::cin >> holeX >> holeY;

			if (
				4 * ((gopherX-holeX)*(gopherX-holeX)+(gopherY-holeY)*(gopherY-holeY))
				<=  ((dogX-holeX)*(dogX-holeX)+(dogY-holeY)*(dogY-holeY))
			) {
				canEscape = true;
				escapeX = holeX;
				escapeY = holeY;
			}
		}

		if (canEscape) {
			std::cout << std::setprecision(3) << std::fixed <<
			"The gopher can escape through the hole at (" <<
				escapeX << ',' << escapeY << ")." << '\n';
		}
		else {
			std::cout << "The gopher cannot escape." << '\n';
		}
	}
	return 0;
}
