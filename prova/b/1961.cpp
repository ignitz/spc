#include <iostream>
#include <vector>

int main(int argc, char *argv[])
{
	int p, n; // 1 ≤ P ≤ 5 e 2 ≤ N ≤ 100
	std::cin >> p >> n;

	int above;

	std::cin >> above;

	for (int i = 1, temp; i < n; i++) {
		std::cin >> temp;
		if (abs(temp - above) > p) {
			std::cout << "GAME OVER" << "\n";
			return 0;
		}
		above = temp;
	}
	std::cout << "YOU WIN" << "\n";

	return 0;
}
