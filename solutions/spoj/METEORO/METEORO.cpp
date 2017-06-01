/*
 * Yuri Niitsuma
 * 2011039023
 * http://br.spoj.com/problems/METEORO/
 * METEORO
*/

#include <iostream>

bool check_in_box(int x1, int y1, int x2, int y2, int x, int y) {
	if (x >= x1 && y <= y1 && x <= x2 && y >= y2)
		return true;
	else
		return false;
}

int main(int argc, char const *argv[]) {
	int x1, y1, x2, y2;
	int n;
	int num_test = 1;
	int num_meteors;
	int x, y;

	while (std::cin >> x1 >> y1 >> x2 >> y2) {
		if (!(x1 | y1 | x2 | y2))
			break;

		num_meteors = 0;
		std::cin >> n;

		for (int i = 0; i < n; i++) {
			std::cin >> x >> y;
			if (check_in_box(x1, y1, x2, y2, x, y))
				num_meteors++;
		}

		std::cout << "Teste " << num_test++ << '\n';
		std::cout << num_meteors << "\n\n";
	}
	return 0;
}
