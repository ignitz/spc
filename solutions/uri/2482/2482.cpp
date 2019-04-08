/*
 * Yuri Niitsuma
 * 2011039023
 * https://www.urionlinejudge.com.br/judge/en/problems/view/2482
 * 2482 - Noel's Labels
*/

#include <iostream>
#include <unordered_map>
// #include <utility>

int main()
{
	int n, m;

	std::string line, auxLine;

	std::unordered_map<std::string, std::string> saudacao;

	std::getline(std::cin, line);
	n = std::stoi(line);

	while (n--)
	{

		// lingua
		std::getline(std::cin, line);
		// traducao
		std::getline(std::cin, auxLine);
		saudacao[line] = auxLine;
	}

	std::getline(std::cin, line);
	m = std::stoi(line);

	while (m--)
	{
		std::getline(std::cin, line);
		std::cout << line << '\n';
		std::getline(std::cin, line);
		std::cout << saudacao[line] << "\n\n";
	}

	return 0;
}
