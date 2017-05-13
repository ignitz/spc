/*
 * Yuri Niitsuma
 * 2011039023
 * https://www.urionlinejudge.com.br/judge/pt/problems/view/1559
 * URI1559
 */

#include <iostream>
#include <vector>

// DOWN LEFT RIGHT UP
// NONE

char check_down(std::vector<std::vector<int>>& matrix, int x, int y) {
	if (x < 3)
		return (matrix[x + 1][y] == matrix[x][y] || matrix[x + 1][y] == 0) ? 0b0001 : 0b0000;
	return 0b0000;
}
char check_left(std::vector<std::vector<int>>& matrix, int x, int y) {
	if (y > 0)
		return (matrix[x][y - 1] == matrix[x][y] || matrix[x][y - 1] == 0) ? 0b0010 : 0b0000;
	return 0b0000;
}
char check_rigth(std::vector<std::vector<int>>& matrix, int x, int y) {
	if (y < 3)
		return (matrix[x][y + 1] == matrix[x][y] || matrix[x][y + 1] == 0) ? 0b0100 : 0b0000;
	return 0b0000;
}
char check_up(std::vector<std::vector<int>>& matrix, int x, int y) {
	if (x > 0)
		return (matrix[x - 1][y] == matrix[x][y] || matrix[x - 1][y] == 0) ? 0b1000 : 0b0000;
	return 0b0000;
}

void check(std::vector<std::vector<int>>& matrix) {
	char mask = 0;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (matrix[i][j] != 0) {
				mask |= check_down(matrix, i, j);
				mask |= check_left(matrix, i, j);
				mask |= check_rigth(matrix, i, j);
				mask |= check_up(matrix, i, j);
			}
		}
	}

	if (mask) {
		if (mask & 0b0001)
			std::cout << "DOWN";
		if (mask & 0b0010)
			(mask & 0b0001) ? std::cout << " LEFT" : std::cout << "LEFT";
		if (mask & 0b0100)
			(mask & 0b0011) ? std::cout << " RIGHT" : std::cout << "RIGHT";
		if (mask & 0b1000)
			(mask & 0b0111) ? std::cout << " UP" : std::cout << "UP";
		std::cout << '\n';
	}
	else {
		std::cout << "NONE" << '\n';
	}
}

int main(){
	int num_testes;
	std::cin >> num_testes;
	int aux;

	std::vector<std::vector<int>> matrix (4, std::vector<int>());
	for (auto & x : matrix)
		x.resize(4, 0);

	int have2048;

	for (int count = 1; count <= num_testes; count++) {
		have2048 = 0;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				std::cin >> aux;
				if(aux == 2048) have2048++;
				matrix[i][j] = aux;
			}
		}
		if (have2048 >= 1) {
			std::cout << "NONE" << '\n';
		}
		else {
			check(matrix);
		}
	}
	return 0;
}
