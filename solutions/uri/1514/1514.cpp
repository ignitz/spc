/*
 * Yuri Niitsuma
 * 2011039023
 * https://www.urionlinejudge.com.br/judge/pt/problems/view/1514
 * Competição
*/

// Faz uma matriz binária, checa cada condição pedida e só.
// O difícil é interpretar o protuguês de (não necessariamente a mesma).

#include <iostream>
#include <vector>

class Matrix {
private:
	int n, m;
	std::vector<std::vector<int>> mat;

public:
	Matrix (int n, int m) {
		this->n = n;
		this->m = m;
		this->mat.resize(n, std::vector<int> (m, 0));
	};
	virtual ~Matrix () {};

	void set_one(int i, int j) {
		this->mat[i][j] = 1;
	};

	// Ninguém resolveu todos os problemas.
	bool check_1 () {
		int sum_of_line;

		for (int i = 0; i < n; i++) {
			sum_of_line = 0;
			for (int j = 0; j < m; j++) {
				sum_of_line += mat[i][j];
			}
			if (sum_of_line == m) return false;
		}

		return true;
	};

	// Todo problema foi resolvido por pelo menos uma pessoa (não necessariamente a mesma).
	bool check_2 () {
		int sum_of_col;
		std::vector<int> mark_problem(m, 0);
		for (int j = 0; j < m; j++) {
			sum_of_col = 0;
			for (int i = 0; i < n; i++) {
				sum_of_col += mat[i][j];
			}
			mark_problem[j] = sum_of_col;
		}
		for (auto const x : mark_problem) {
			if (x == 0) return false;
		}
		return true;
	};

	// Não há nenhum problema resolvido por todos.
	bool check_3 () {
		int sum_of_col;
		for (int j = 0; j < m; j++) {
			sum_of_col = 0;
			for (int i = 0; i < n; i++) {
				sum_of_col += mat[i][j];
			}
			if (sum_of_col == n) return false;
		}
		return true;
	};

	// Todos resolveram ao menos um problema (não necessariamente o mesmo).
	bool check_4 () {
		int sum_of_line;
		std::vector<int> mark_competidor(n, 0);

		for (int i = 0; i < n; i++) {
			sum_of_line = 0;
			for (int j = 0; j < m; j++) {
				sum_of_line += mat[i][j];
			}
			mark_competidor[i] = sum_of_line;
		}
		for (auto const x : mark_competidor) {
			if (x == 0) return false;
		}
		return true;
	};

	int check_all() {
		int count = 0;

		count += check_1() ? 1 : 0;
		count += check_2() ? 1 : 0;
		count += check_3() ? 1 : 0;
		count += check_4() ? 1 : 0;

		return count;
	}

	void print_matrix() {
		for (int i = 0; i < this->n; i++) {
			for (int j = 0; j < this->m; j++) {
				std::cout << mat[i][j] << ' ';
			}
			std::cout << '\n';
		}
	};
};

int main(int argc, char const *argv[]) {
	int aux, n, m;

	while (std::cin >> n >> m) {
		if ( !(n | m) ) break;

		Matrix matrix(n, m);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				std::cin >> aux;
				if (aux) matrix.set_one(i,j);
			}
		}

		// matrix.print_matrix();
		// std::cout << n << ' ' << m << ' ' << matrix.check_all() << '\n';
		std::cout << matrix.check_all() << '\n';
	}
	return 0;
}
