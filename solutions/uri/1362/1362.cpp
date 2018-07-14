/*
 * Yuri Niitsuma
 * 2011039023
 * https://www.urionlinejudge.com.br/judge/pt/problems/view/1362
 * URI1362
 */

#include <iostream>
#include <string>
#include <vector>

#define NONE 0
#define SHIRT_XXL 1
#define SHIRT_XL 2
#define SHIRT_L 3
#define SHIRT_M 4
#define SHIRT_S 5
#define SHIRT_XS 6

int get_int_shirt (std::string shirt) {
	if (shirt.compare("XXL") == 0) {
		return SHIRT_XXL;
	} else if (shirt.compare("XL") == 0) {
		return SHIRT_XL;
	} else if (shirt.compare("L") == 0) {
		return SHIRT_L;
	} else if (shirt.compare("M") == 0) {
		return SHIRT_M;
	} else if (shirt.compare("S") == 0) {
		return SHIRT_S;
	} else if (shirt.compare("XS") == 0) {
		return SHIRT_XS;
	}
	return NONE;
}

class Pessoa {
public:
	// Escolhas
	int primeira;
	int segunda;
	Pessoa (int prim, int seg) {
		this->primeira = prim;
		this->segunda = seg;
	}
	virtual ~Pessoa () {}
};

bool choose_one(std::vector<Pessoa> pessoas, std::vector<int>& camisas, bool& everybody_has_shirt, int qual_pessoa, int num_pessoas) {
	// std::cout << "quem é?" << qual_pessoa << '\n';
	// for (int i = 1; i <= 6; i++) {
	// 	std::cout << camisas[i] << ' ';
	// }
	// std::cout << '\n';

	if (qual_pessoa == num_pessoas) {
		everybody_has_shirt = true;
		return true;
	}

	if (everybody_has_shirt) return true;

	// tentativa um, escolhe primeira opcao
	if (camisas[pessoas[qual_pessoa+1].primeira] > 0) {
		camisas[pessoas[qual_pessoa+1].primeira]--; // escolhe a primeira opcao
		everybody_has_shirt = choose_one(pessoas, camisas, everybody_has_shirt, qual_pessoa + 1, num_pessoas) ;
		camisas[pessoas[qual_pessoa+1].primeira]++; // devolve a camisa
	}
	if (everybody_has_shirt) return true;
	if (camisas[pessoas[qual_pessoa+1].segunda] > 0) {
		camisas[pessoas[qual_pessoa+1].segunda]--; // escolhe a primeira opcao
		everybody_has_shirt = choose_one(pessoas, camisas, everybody_has_shirt, qual_pessoa + 1, num_pessoas);
		camisas[pessoas[qual_pessoa+1].segunda]++; // devolve a camisa
	}
	if (everybody_has_shirt) return true;
	return false;
}

int main(){
	int num_tests;
	int n, m;
	std::string aux1, aux2;
	bool everybody_has_shirt;

	std::vector<int> camisas(7, 0); // quandidade de cada camisa

	std::cin >> num_tests;

	for (int tests_i = 0; tests_i < num_tests; tests_i++) {
		std::cin >> n >> m;

		std::vector<Pessoa> pessoas;
		pessoas.push_back(Pessoa(NONE, NONE)); // vetor posicao 0
		std::fill(camisas.begin(), camisas.end(), n/6);

		for (int m_i = 0; m_i < m; m_i++) {
			std::cin >> aux1 >> aux2;
			pessoas.push_back(Pessoa(get_int_shirt(aux1), get_int_shirt(aux2)));
		}
		everybody_has_shirt = false;
		if (choose_one(pessoas, camisas, everybody_has_shirt, 0, m))
			std::cout << "YES" << '\n';
		else
			std::cout << "NO" << '\n';
	}
	return 0;
}
