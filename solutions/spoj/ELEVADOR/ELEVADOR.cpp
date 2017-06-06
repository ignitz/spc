/*
 * Yuri Niitsuma
 * 2011039023
 * http://br.spoj.com/problems/ELEVADOR/
 * ELEVADOR
*/

#include <iostream>
#include <cmath>

int main(int argc, char const *argv[]) {
	int l, c, r1, r2;

	int x, y, dist;

	while (std::cin >> l >> c >> r1 >> r2) {
		if ( !(l | c | r1 | r2) )
			break;

		if (r1 + r1 > c || r1 + r1 > l || r2 + r2 > l || r2 + r2 > c) {
			std::cout << "N" << '\n';
		}
		else {
			x = l - r1 - r2;
			y = c - r1 - r2;
			dist = x*x + y*y;

			if ((r1 + r2)*(r1 + r2) <= dist) {
				std::cout << "S" << '\n';
			}
			else {
				std::cout << "N" << '\n';
			}
		}
	}

	return 0;
}
