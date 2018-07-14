/*
 * Yuri Niitsuma
 * 2011039023
 * https://www.urionlinejudge.com.br/judge/pt/problems/view/1961
 * URI1961 - Pula Sapo
 */

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
