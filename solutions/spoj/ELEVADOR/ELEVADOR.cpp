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

	double x;

	while (std::cin >> l >> c >> r1 >> r2) {
		if ( !(l | c | r1 | r2) )
			break;

		// calc dist
		x = std::sqrt(2 * (r1*r1 + r2*r2)) + ((double)(r1 + r2));
		std::cout << x << std::endl;
		x = std::sqrt(2)*(r1 + r2) + ((double) (r1 + r2));
		std::cout << x << std::endl;
		x = std::sqrt(l*l + c*c);
		std::cout << x << std::endl;
		std::cout << ((double) l) << std::endl;
		std::cout << ((double) c) << std::endl;

		if (x <= ((double) l) ||
			x <= ((double) c) ||
			std::sqrt(2)*(r1 + r2) + ((double) (r1 + r2)) <= std::sqrt(l*l + c*c))
		{
			std::cout << 'S' << std::endl;
		}
		else {
			std::cout << 'N' << std::endl;
		}
	}

	return 0;
}