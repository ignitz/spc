/*
 * Yuri Niitsuma
 * 2011039023
 * https://www.urionlinejudge.com.br/judge/en/problems/view/1288
 * 1288 - Destruction Cannon
*/

// Problema da mochila
// Código tirado daqui
// https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/

#include <iostream>
#include <vector>
#include <cassert>

// A utility function that returns maximum of two integers
int max(int a, int b) { return (a > b) ? a : b; }

// Returns the maximum value that can be put in a knapsack of capacity W
int knapSack(int W, std::vector<int> &wt, std::vector<int> &val)
{
	int n = wt.size();

	assert(n == val.size());

	int K[n + 1][W + 1];

	// Build table K[][] in bottom up manner
	for (int i = 0; i <= n; i++)
	{
		for (int w = 0; w <= W; w++)
		{
			if (i == 0 || w == 0)
				K[i][w] = 0;
			else if (wt[i - 1] <= w)
				K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
			else
				K[i][w] = K[i - 1][w];
		}
	}

	return K[n][W];
}

int main()
{
	// A primeira linha de entrada contém o número de casos de teste. Cada caso de teste inicia com uma linha contendo um número inteiro N (1 ≤ N ≤ 50), que representa o número de projéteis de chumbo disponíveis. Seguem N linhas contendo dois inteiros X e Y, representando respectivamente o poder de destruição do projétil e o peso do projétil. A próxima linha contém um inteiro K (1 ≤ K ≤ 100) que representa a capacidade de carga do canhão e a última linha do caso de teste contém um inteiro R que indica a resistência total do castelo.

	int nTests, n;
	int x, y;
	int k, r;

	std::vector<int> wt, val;

	std::cin >> nTests;

	while (nTests--)
	{
		std::cin >> n;
		while (n--)
		{
			std::cin >> x >> y;
			val.push_back(x);
			wt.push_back(y);
		}
		std::cin >> k;
		std::cin >> r;

		// qual é W? k ou r?
		int result = knapSack(k, wt, val);

		if (result >= r)
			std::cout << "Missao completada com sucesso" << '\n';
		else
			std::cout << "Falha na missao" << '\n';

		wt.clear();
		val.clear();
	}
	return 0;
}